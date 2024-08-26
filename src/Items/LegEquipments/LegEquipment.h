//
// Created by gerw on 8/20/24.
//

#ifndef QT_PROGRAMMING_2024_LEGEQUIPMENT_H
#define QT_PROGRAMMING_2024_LEGEQUIPMENT_H


#include "../Item.h"
#include "../Mountable.h"

class LegEquipment: public Item, public Mountable {
public:
    explicit LegEquipment(QGraphicsItem *parent, const QString &pixmapPath); //构造函数，传入父节点和图片路径

    void mountToParent() override; //挂载到父节点

    int index;
}; //LegEquipment类继承自Item类和Mountable类，表示腿部装备，可以挂载到父节点


#endif //QT_PROGRAMMING_2024_LEGEQUIPMENT_H