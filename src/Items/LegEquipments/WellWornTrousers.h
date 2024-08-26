//
// Created by gerw on 8/20/24.
//

#ifndef QT_PROGRAMMING_2024_WELLWORNTROUSERS_H
#define QT_PROGRAMMING_2024_WELLWORNTROUSERS_H


#include "LegEquipment.h"

class WellWornTrousers : public LegEquipment {
public:
    explicit WellWornTrousers(QGraphicsItem *parent); //构造函数，传入父节点
}; //WellWornTrousers类继承自LegEquipment类，表示破旧的裤子


#endif //QT_PROGRAMMING_2024_WELLWORNTROUSERS_H
