#ifndef ARROW_H
#define ARROW_H

#include "../Item.h"
#include "../Mountable.h"
#include "../Throwable.h"

class Arrow : public Item, public Mountable, public Throwable
{
public:
    explicit Arrow(QGraphicsItem *parent, const QString &pixmapPath); //构造函数，传入父节点和图片路径

    void mountToParent() override; //挂载到父节点

    void unmount() override; //卸载

    void attack(); //攻击函数

    void attackStoped(); //攻击停止

    qreal damage = 10; //伤害值

    qreal downAcceleration; //重力加速度

    qreal downSpeed; //下降速度
};

#endif // ARROW_H
