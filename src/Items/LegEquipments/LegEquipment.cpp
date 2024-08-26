//
// Created by gerw on 8/20/24.
//

#include "LegEquipment.h"

LegEquipment::LegEquipment(QGraphicsItem *parent, const QString &pixmapPath) : Item(parent, pixmapPath) {
}

void LegEquipment::mountToParent() {
    Mountable::mountToParent(); //调用父类的挂载函数
    setScale(0.8); //缩放比例
    setPos(-60, -110); //位置
}

//LegEquipment::index=3;
