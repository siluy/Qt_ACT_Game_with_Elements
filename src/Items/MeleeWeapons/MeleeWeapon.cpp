#include "MeleeWeapon.h"

MeleeWeapon::MeleeWeapon(QGraphicsItem *parent, const QString &pixmapPath) : Item(parent, pixmapPath) {

} //构造函数，传入父节点和图片路径

void MeleeWeapon::mountToParent() {
    Mountable::mountToParent(); //调用父类的挂载函数，设置为挂载状态
    //setScale(2.0); //设置缩放比例2.0 适合铁短剑的大小
    //setPos(-190, -170);  //设置近战武器的位置 适合铁短剑的位置
    //if (pixmapItem != nullptr) {
     //   pixmapItem->setPos(0, 0); //设置图片位置
    //}
} //挂载到父节点

void MeleeWeapon::unmount() {
    Mountable::unmount(); //调用父类的卸载函数，设置为未挂载状态
    //setScale(0.8);
    //if (pixmapItem != nullptr) {
        //pixmapItem->setPos(0, -120); //设置图片位置
    //}
}

void MeleeWeapon::attack() {
    //攻击函数
    if(pixmapItem != nullptr){
        //setRotation(90);
        setPos(-250,-170);
    }
}

void MeleeWeapon::attackStoped() {
    if (pixmapItem != nullptr) {
        setPos(-190, -170);  //设置近战武器的位置 适合铁短剑的位置
        pixmapItem->setPos(0, 0); //设置图片位置
    }
}

QPointF MeleeWeapon::getSpeed() const {
    return speed;
} //获取速度
