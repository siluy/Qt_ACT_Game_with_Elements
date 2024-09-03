#include "WoodShortSword.h"

WoodShortSword::WoodShortSword(QGraphicsItem *parent) :MeleeWeapon(parent, ":/Items/Weapons/MeleeWeapons/WoodShortSword/WoodShortSword.png")
{
    material = 2; //设置材质为木质
}

void WoodShortSword::mountToParent() {
    MeleeWeapon::mountToParent(); //调用父类的挂载函数，设置为挂载状态
    setScale(1.8); //设置缩放比例2.0 适合铁短剑的大小
    setPos(-190, -170);  //设置近战武器的位置 适合铁短剑的位置
    if (pixmapItem != nullptr) {
        pixmapItem->setPos(0, 0); //设置图片位置
    }
} //挂载到父节点

void WoodShortSword::unmount() {
    MeleeWeapon::unmount(); //调用父类的卸载函数，设置为未挂载状态
    setScale(0.75);
    if (pixmapItem != nullptr) {
        pixmapItem->setPos(0, -90); //设置图片位置
    }
}

void WoodShortSword::attack() {
    //攻击函数
    if(pixmapItem != nullptr){
    //setRotation(90);
    setPos(-250,-170);
    }
}

void WoodShortSword::attackStoped() {
    //qDebug() << "Stopping attack.";
    if (pixmapItem != nullptr) {
        setPos(-190, -170);  //设置近战武器的位置 适合铁短剑的位置
        pixmapItem->setPos(0, 0); //设置图片位置
    } //else {
        //qDebug() << "pixmapItem is null.";
    //}
}
