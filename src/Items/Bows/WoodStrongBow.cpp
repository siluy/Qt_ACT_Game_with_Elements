#include "WoodStrongBow.h"

WoodStrongBow::WoodStrongBow(QGraphicsItem *parent) : Bow(parent, "://Items/Weapons/BowsAndArrows/WoodStrongBow/WoodStrongBow.png") {
    material = 2;
} //构造函数，传入父节点和图片路径
