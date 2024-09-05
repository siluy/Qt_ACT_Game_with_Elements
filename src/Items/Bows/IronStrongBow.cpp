#include "IronStrongBow.h"

IronStrongBow::IronStrongBow(QGraphicsItem *parent) : Bow(parent, "://Items/Weapons/BowsAndArrows/IronStrongBow/IronStrongBow.png") {
    material = 1;
    capacity = 2;
} //构造函数，传入父节点和图片路径
