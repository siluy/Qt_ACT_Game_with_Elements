#include "IceSword.h"

IceSword::IceSword(QGraphicsItem *parent) : MeleeWeapon(parent,"://Items/Weapons/MeleeWeapons/IceSword/freeze_sword.png")
{}

void IceSword::mountToParent() {
    MeleeWeapon::mountToParent();
    setScale(1.0);
    setRotation(-90);
    //setTransform(QTransform(-1, 0, 0, 1, 0, 0));//镜像翻转
    setPos(-150, -20);
    if (pixmapItem != nullptr) {
        pixmapItem->setPos(0, 0);
    }
}

void IceSword::unmount() {
    MeleeWeapon::unmount();
    setScale(0.8);
    if (pixmapItem != nullptr) {
        pixmapItem->setPos(0, -120);
    }
}

void IceSword::attack() {
    if(pixmapItem != nullptr){
    setPos(-210,-20);
    }
}

void IceSword::attackStoped() {
    if (pixmapItem != nullptr) {
        setPos(-150, -20);
        pixmapItem->setPos(0, 0);
    }
}
