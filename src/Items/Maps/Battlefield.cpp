//
// Created by gerw on 8/21/24.
//

#include "Battlefield.h"

Battlefield::Battlefield(QGraphicsItem *parent) : Map(parent, ":/Items/Maps/Battlefield/g9tOqth.png") {}

qreal Battlefield::getFloorHeight() {
    auto sceneRect = sceneBoundingRect(); //获取场景矩形
    return (sceneRect.top() + sceneRect.bottom()) * 0.63; //返回地图高度
} //获取地图高度
