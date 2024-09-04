#include "WoodBow.h"

WoodBow::WoodBow(QGraphicsItem *parent) : Bow(parent, "://Items/Weapons/BowsAndArrows/WoodBow/WoodBow.png") {
    material = 2;
} //构造函数，传入父节点和图片路径
