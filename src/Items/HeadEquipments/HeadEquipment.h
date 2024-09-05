//
// Created by gerw on 8/20/24.
//

#ifndef QT_PROGRAMMING_2024_HEADEQUIPMENT_H
#define QT_PROGRAMMING_2024_HEADEQUIPMENT_H


#include "../Item.h"
#include "../Mountable.h"

class HeadEquipment: public Item, public Mountable {
public:
    explicit HeadEquipment(QGraphicsItem *parent, const QString &pixmapPath); //构造函数，传入父节点和图片路径

    void mountToParent() override; //挂载到父节点

    void unmount() override; //卸载

    int antiElement; //抗性，0表示无抗性，1表示火焰抗性，2表示冰霜抗性，3表示雷电抗性
}; //HeadEquipment类继承自Item类和Mountable类，表示头部装备，可以挂载到父节点




#endif //QT_PROGRAMMING_2024_HEADEQUIPMENT_H
