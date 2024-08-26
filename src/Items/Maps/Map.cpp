//
// Created by gerw on 8/21/24.
//

#include "Map.h"

Map::Map(QGraphicsItem *parent, const QString &pixmapPath) : Item(parent, pixmapPath) {} //构造函数，传入父节点和图片路径
void Map::scaleToFitScene(QGraphicsScene *scene) {
    // Calculate scale factors to scale the item to fit the entire scene //计算缩放因子，将项目缩放到适应整个场景
    QRectF sceneRect = scene->sceneRect(); //获取场景矩形
    QRectF itemRect = boundingRect(); //获取项目矩形

    qreal scaleX = sceneRect.width() / itemRect.width(); //计算x轴缩放因子
    qreal scaleY = sceneRect.height() / itemRect.height(); //计算y轴缩放因子

    // Choose the smaller scale factor to maintain aspect ratio //选择较小的缩放因子以保持纵横比
    qreal scaleFactor = qMin(scaleX, scaleY);

    // Apply the scale to the item
    setTransform(QTransform::fromScale(scaleFactor, scaleFactor), true); //应用缩放到项目

    // Center the item in the scene (optional)
    setPos((sceneRect.width() - boundingRect().width() * scaleFactor) / 2,
           (sceneRect.height() - boundingRect().height() * scaleFactor) / 2);   //将项目居中

} //缩放适应场景

QPointF Map::getSpawnPos() {
    auto boundingRect = sceneBoundingRect(); //获取场景矩形
    auto midX = (boundingRect.left() + boundingRect.right()) * 0.5; //计算中心x坐标
    return {midX, getFloorHeight()}; //返回出生点坐标
} //获取出生点

qreal Map::getFloorHeight() { //获取地图高度
    auto sceneRect = sceneBoundingRect(); //获取场景矩形
    return sceneRect.top() + (sceneRect.top() - sceneRect.bottom()) * 0.5; //返回地图高度
}

//Map::index=4;
