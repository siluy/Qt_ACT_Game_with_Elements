#include "battlebackground.h"

Battlebackground::Battlebackground(QGraphicsItem *parent) : Map(parent, ":/Items/Maps/BattleBackground/battle_background.png") {}

qreal Battlebackground::getFloorHeight() {
    auto sceneRect = sceneBoundingRect();
    return (sceneRect.top() + sceneRect.bottom()) * 0.63;
}
//获取地图高度
