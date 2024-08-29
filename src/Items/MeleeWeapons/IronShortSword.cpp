#include "IronShortSword.h"

IronShortSword::IronShortSword(QGraphicsItem *parent) :MeleeWeapon(parent, ":/Items/Weapons/MeleeWeapons/IronShortSword/Iron_Short_Sword.png")
{}

void IronShortSword::mountToParent() {
    Mountable::mountToParent(); //调用父类的挂载函数，设置为挂载状态
    setScale(2.0); //设置缩放比例2.0 适合铁短剑的大小
    setPos(-190, -170);  //设置近战武器的位置 适合铁短剑的位置
    if (pixmapItem != nullptr) {
        pixmapItem->setPos(0, 0); //设置图片位置
    }
} //挂载到父节点

void IronShortSword::unmount() {
    Mountable::unmount(); //调用父类的卸载函数，设置为未挂载状态
    setScale(0.8);
    if (pixmapItem != nullptr) {
        pixmapItem->setPos(0, -120); //设置图片位置
    }
}

qreal IronShortSword::attack() {
    //攻击函数
    //setRotation(90);
    setPos(-250,-170);

    return damage;
}

void IronShortSword::attackStoped() {
//setRotation(-90);
    setPos(-190, -170);  //设置近战武器的位置 适合铁短剑的位置
    if (pixmapItem != nullptr) {
        pixmapItem->setPos(0, 0); //设置图片位置
    }
}
