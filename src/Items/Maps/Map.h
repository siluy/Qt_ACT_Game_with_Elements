//
// Created by gerw on 8/21/24.
//

#ifndef QT_PROGRAMMING_2024_MAP_H
#define QT_PROGRAMMING_2024_MAP_H

#include <QGraphicsScene>
#include <QPointF>
#include "../Item.h"

class Map : public Item {
public:
    explicit Map(QGraphicsItem *parent = nullptr, const QString &pixmapPath = ""); //构造函数，传入父节点和图片路径

    void scaleToFitScene(QGraphicsScene *scene); //缩放适应场景

    virtual qreal getFloorHeight(); // Need to rewrite to support multiple platforms //获取地图高度

    virtual QPointF getSpawnPos(); //获取出生点

    int index;
}; //Map类继承自Item类，表示地图，可以缩放适应场景，获取地图高度和出生点


#endif //QT_PROGRAMMING_2024_MAP_H
