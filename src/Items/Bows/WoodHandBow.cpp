#include "WoodHandBow.h"

WoodHandBow::WoodHandBow(QGraphicsItem *parent) : Bow(parent, "://Items/Weapons/BowsAndArrows/WoodHandBow/WoodHandBow.png") {
    material = 2;
} //构造函数，传入父节点和图片路径

void WoodHandBow::mountToParent(){
    Mountable::mountToParent(); //调用父类的挂载函数，设置为挂载状态
    setTransform(QTransform(-1, 0, 0, 1, 0, 0));//镜像翻转
    setScale(0.5); //设置缩放比例
    setPos(30, -160);  //设置弓的位置

    if (pixmapItem != nullptr) {
        pixmapItem->setPos(0, 0); //设置图片位置
    }
}

void WoodHandBow::unmount(){
    Mountable::unmount(); //调用父类的卸载函数，设置为未挂载状态
    setScale(0.8);
    if (pixmapItem != nullptr) {
        pixmapItem->setPos(0, -120); //设置图片位置
    }
}