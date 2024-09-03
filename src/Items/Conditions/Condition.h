#ifndef CONDITION_H
#define CONDITION_H

#include "../Item.h"
#include "../Mountable.h"

class Condition : public Item, public Mountable
{
public:

    explicit Condition(QGraphicsItem *parent, const QString &pixmapPath); //构造函数，传入父节点和图片路径

    void mountToParent() override; //挂载到父节点

    void unmount() override; //卸载
};

#endif // CONDITION_H
