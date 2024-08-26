//
// Created by gerw on 8/20/24.
//

#include "Armor.h"

Armor::Armor(QGraphicsItem *parent, const QString &pixmapPath) : Item(parent, pixmapPath) {

} //构造函数，传入父节点和图片路径

void Armor::mountToParent() {
    Mountable::mountToParent(); //调用父类的挂载函数，设置为挂载状态
    setScale(0.8); //设置缩放比例0.8
    setPos(-59, -176);  //设置Armor的位置
    if (pixmapItem != nullptr) {
        pixmapItem->setPos(0, 0); //设置图片位置
    }
} //挂载到父节点

void Armor::unmount() {
    Mountable::unmount(); //调用父类的卸载函数，设置为未挂载状态
    setScale(0.8);
    if (pixmapItem != nullptr) {
        pixmapItem->setPos(0, -120); //设置图片位置
    }
}

//Armor::index = 1; //设置index为1
