#include "IronLongSword.h"

IronLongSword::IronLongSword(QGraphicsItem *parent) : MeleeWeapon(parent, "://Items/Weapons/MeleeWeapons/IronLongSword/iron_long_sword.png")
{
    element = 0;
    material = 1;
}

void IronLongSword::attack()
{
    //攻击函数
    if(pixmapItem != nullptr){
        //setRotation(90);
        setPos(-280,-40);
    }
}

void IronLongSword::attackStoped()
{
    if (pixmapItem != nullptr) {
        setPos(-220, -40);  //设置近战武器的位置 适合铁短剑的位置
        pixmapItem->setPos(0, 0); //设置图片位置
    }
}

void IronLongSword::mountToParent()
{
    MeleeWeapon::mountToParent(); //调用父类的挂载函数，设置为挂载状态
    setScale(1.0); //设置缩放比例2.0 适合铁短剑的大小
    setRotation(-90);
    setPos(-220, -40);  //设置近战武器的位置 适合铁短剑的位置
    if (pixmapItem != nullptr) {
        pixmapItem->setPos(0, 0); //设置图片位置
    }
}

void IronLongSword::unmount()
{
    MeleeWeapon::unmount(); //调用父类的卸载函数，设置为未挂载状态
    setScale(0.5);
    if (pixmapItem != nullptr) {
        pixmapItem->setPos(0, -120); //设置图片位置
    }
}
