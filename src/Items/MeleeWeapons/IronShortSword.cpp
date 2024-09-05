#include "IronShortSword.h"

IronShortSword::IronShortSword(QGraphicsItem *parent) :MeleeWeapon(parent, ":/Items/Weapons/MeleeWeapons/IronShortSword/Iron_Short_Sword.png")
{
    material = 1; //设置材质为铁质
    element = 0; //设置元素为无
    attackRange = 250; //设置攻击范围为150
}

void IronShortSword::mountToParent() {
    MeleeWeapon::mountToParent(); //调用父类的挂载函数，设置为挂载状态
    setScale(2.0); //设置缩放比例2.0 适合铁短剑的大小
    setPos(-190, -170);  //设置近战武器的位置 适合铁短剑的位置
    if (pixmapItem != nullptr) {
        pixmapItem->setPos(0, 0); //设置图片位置
    }
} //挂载到父节点

void IronShortSword::unmount() {
    MeleeWeapon::unmount(); //调用父类的卸载函数，设置为未挂载状态
    setScale(0.8);
    if (pixmapItem != nullptr) {
        pixmapItem->setPos(0, -80); //设置图片位置
    }
}

void IronShortSword::attack() {
    //攻击函数
    if(pixmapItem != nullptr){
    //setRotation(90);
    setPos(-250,-170);
    }
}

void IronShortSword::attackStoped() {
    //qDebug() << "Stopping attack.";
    if (pixmapItem != nullptr) {
        setPos(-190, -170);  //设置近战武器的位置 适合铁短剑的位置
        pixmapItem->setPos(0, 0); //设置图片位置
    } //else {
        //qDebug() << "pixmapItem is null.";
    //}
}
