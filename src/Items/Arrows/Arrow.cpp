#include "Arrow.h"

Arrow::Arrow(QGraphicsItem *parent, const QString &pixmapPath) :Item(parent, pixmapPath) {}

void Arrow::mountToParent() {
    Mountable::mountToParent(); //调用父类的挂载函数，设置为挂载状态
    setRotation(-135);
    setScale(0.8); //设置缩放比例
    setPos(-80, -15);  //设置位置
    if (pixmapItem != nullptr) {
        pixmapItem->setPos(0, 0); //设置图片位置
    }
} //挂载到父节点

void Arrow::unmount() {
    Mountable::unmount(); //调用父类的卸载函数，设置为未挂载状态
    setScale(0.2);
    if (pixmapItem != nullptr) {
        pixmapItem->setPos(0, -120); //设置图片位置
    }
}

QPointF Arrow::getSpeed() const {
    return speed;
} //获取速度
