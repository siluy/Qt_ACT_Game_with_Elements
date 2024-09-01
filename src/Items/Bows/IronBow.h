#ifndef IRONBOW_H
#define IRONBOW_H

#include "Bow.h"

class IronBow : public Bow
{
public:
    explicit IronBow(QGraphicsItem *parent = nullptr);

    void attack(); //攻击函数

    void attackStoped(); //攻击停止

    //void mountToParent() override; //挂载到父节点

    //void unmount() override;//卸载

    qreal downAcceleration; //重力加速度

    qreal downSpeed; //下降速度

    int capacity = 1; //弓箭容量

    int attackRange = 300; //攻击范围
};

#endif // IRONBOW_H
