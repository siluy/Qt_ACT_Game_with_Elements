#include "IronStaff.h"

IronStaff::IronStaff(QGraphicsItem *parent) : MeleeWeapon(parent, "://Items/Weapons/MeleeWeapons/IronStaff/iron_staff.png")
{
    element = 0;
    material = 1;
}

void IronStaff::attack()
{
    //攻击函数
    if(pixmapItem != nullptr){
        //setRotation(90);
        setPos(-250,-50);
    }
}

void IronStaff::attackStoped()
{
    if (pixmapItem != nullptr) {
        setPos(-190, -50);  //设置近战武器的位置 适合铁短剑的位置
        pixmapItem->setPos(0, 0); //设置图片位置
    }
}

void IronStaff::mountToParent()
{
    MeleeWeapon::mountToParent(); //调用父类的挂载函数，设置为挂载状态
    setScale(1.0); //设置缩放比例2.0 适合铁短剑的大小
    setRotation(-90);
    setPos(-190, -50);  //设置近战武器的位置 适合铁短剑的位置
    if (pixmapItem != nullptr) {
        pixmapItem->setPos(0, 0); //设置图片位置
    }
}

void IronStaff::unmount()
{
    MeleeWeapon::unmount(); //调用父类的卸载函数，设置为未挂载状态
    setScale(0.8);
    if (pixmapItem != nullptr) {
        pixmapItem->setPos(0, -120); //设置图片位置
    }
}
