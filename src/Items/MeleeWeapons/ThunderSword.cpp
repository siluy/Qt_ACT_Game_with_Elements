#include "ThunderSword.h"

ThunderSword::ThunderSword(QGraphicsItem *parent) : MeleeWeapon(parent, "://Items/Weapons/MeleeWeapons/ThunderSword/thunder_sword.png") {
    //构造函数，传入父节点和图片路径
}

void ThunderSword::mountToParent() {
    MeleeWeapon::mountToParent();
    setScale(1.0);
    setRotation(-90);
    //setTransform(QTransform(-1, 0, 0, 1, 0, 0));//镜像翻转
    setPos(-180, -40);
    if (pixmapItem != nullptr) {
        pixmapItem->setPos(0, 0);
    }
}

void ThunderSword::unmount() {
    MeleeWeapon::unmount();
    setScale(0.8);
    if (pixmapItem != nullptr) {
        pixmapItem->setPos(0, -120);
    }
}

void ThunderSword::attack() {
    if(pixmapItem != nullptr){
    setPos(-240,-40);
    }
}

void ThunderSword::attackStoped() {
    if (pixmapItem != nullptr) {
        setPos(-180, -40);
        pixmapItem->setPos(0, 0);
    }
}
