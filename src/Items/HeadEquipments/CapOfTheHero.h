//
// Created by gerw on 8/20/24.
//

#ifndef QT_PROGRAMMING_2024_CAPOFTHEHERO_H
#define QT_PROGRAMMING_2024_CAPOFTHEHERO_H


#include "HeadEquipment.h"

class CapOfTheHero: public HeadEquipment {
public:
    explicit CapOfTheHero(QGraphicsItem *parent = nullptr); //构造函数，传入父节点
}; //CapOfTheHero类继承自HeadEquipment类，表示英雄的帽子


#endif //QT_PROGRAMMING_2024_CAPOFTHEHERO_H
