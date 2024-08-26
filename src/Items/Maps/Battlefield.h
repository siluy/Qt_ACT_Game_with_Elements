//
// Created by gerw on 8/21/24.
//

#ifndef QT_PROGRAMMING_2024_BATTLEFIELD_H
#define QT_PROGRAMMING_2024_BATTLEFIELD_H


#include "Map.h"

class Battlefield: public Map {
public:
    explicit Battlefield(QGraphicsItem *parent= nullptr); //构造函数，传入父节点

    qreal getFloorHeight() override; //获取地图高度
}; //Battlefield类继承自Map类，表示战场地图


#endif //QT_PROGRAMMING_2024_BATTLEFIELD_H
