#ifndef HAIROFTHEHERO_H
#define HAIROFTHEHERO_H

#include "HeadEquipment.h"

class HairOfTheHero: public HeadEquipment {
public:
    explicit HairOfTheHero(QGraphicsItem *parent);
}; //HairOfTheHero类继承自HeadEquipment类，表示英雄的头发

#endif // HAIROFTHEHERO_H
