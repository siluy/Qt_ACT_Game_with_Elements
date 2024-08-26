//
// Created by gerw on 8/20/24.
//

#include "HeadEquipment.h"

HeadEquipment::HeadEquipment(QGraphicsItem *parent, const QString &pixmapPath) : Item(parent, pixmapPath) {
}

void HeadEquipment::mountToParent() {
    Mountable::mountToParent(); //调用父类的挂载函数
    setScale(0.4); //设置缩放比例
    setPos(-30, -210); //设置位置
}

//HeadEquipment::index=2;
