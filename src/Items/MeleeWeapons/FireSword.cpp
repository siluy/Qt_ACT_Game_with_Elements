#include "FireSword.h"

FireSword::FireSword(QGraphicsItem *parent) : MeleeWeapon(parent, "://Items/Weapons/MeleeWeapons/FireSword/fire_sword.png")
{
}


void FireSword::mountToParent() {
    MeleeWeapon::mountToParent();
    setScale(1.0);
    setTransform(QTransform(-1, 0, 0, 1, 0, 0));//镜像翻转
    setPos(-15, -170);
    if (pixmapItem != nullptr) {
        pixmapItem->setPos(0, 0);
    }
}

void FireSword::unmount() {
    MeleeWeapon::unmount();
    setScale(0.8);
    if (pixmapItem != nullptr) {
        pixmapItem->setPos(0, -120);
    }
}

void FireSword::attack() {
    if(pixmapItem != nullptr){
    setPos(-75,-170);
    }
}

void FireSword::attackStoped() {
    if (pixmapItem != nullptr) {
        setPos(-15, -170);
        pixmapItem->setPos(0, 0);
    }
}
