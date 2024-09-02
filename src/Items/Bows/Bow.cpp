#include "Bow.h"

Bow::Bow(QGraphicsItem *parent, const QString &pixmapPath) : Item(parent, pixmapPath) {

} //构造函数，传入父节点和图片路径

void Bow::mountToParent() {
    Mountable::mountToParent(); //调用父类的挂载函数，设置为挂载状态
    setRotation(135);
    setScale(0.5); //设置缩放比例
    setPos(60, -90);  //设置弓的位置

    if (pixmapItem != nullptr) {
        pixmapItem->setPos(0, 0); //设置图片位置
    }
} //挂载到父节点

void Bow::unmount() {
    Mountable::unmount(); //调用父类的卸载函数，设置为未挂载状态
    setScale(0.8);
    if (pixmapItem != nullptr) {
        pixmapItem->setPos(0, -120); //设置图片位置
    }
}

void Bow::attack() {
    //攻击函数
    if(pixmapItem != nullptr){
        setPos(30,-90);}
}

void Bow::attackStoped() {
    if (pixmapItem != nullptr) {
        setPos(60, -90);  //设置近战武器的位置
        pixmapItem->setPos(0, 0); //设置图片位置
    }
}


