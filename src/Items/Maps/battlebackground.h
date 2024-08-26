#ifndef BATTLEBACKGROUND_H
#define BATTLEBACKGROUND_H

#include "Map.h"

class Battlebackground: public Map {
public:
    explicit Battlebackground(QGraphicsItem *parent= nullptr); //构造函数，传入父节点

    qreal getFloorHeight() override; //获取地图高度
}; //Battlefield类继承自Map类，表示战场地图

#endif // BATTLEBACKGROUND_H
