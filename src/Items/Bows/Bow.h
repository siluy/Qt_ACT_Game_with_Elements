#ifndef BOW_H
#define BOW_H

#include "../Item.h"
#include "../Mountable.h"
//#include "../Throwable.h"

class Bow : public Item, public Mountable//, public Throwable
{
public:
    explicit Bow(QGraphicsItem *parent, const QString &pixmapPath); //构造函数，传入父节点和图片路径

    void mountToParent() override; //挂载到父节点

    void unmount() override; //卸载

    void attack(); //攻击函数

    void attackStoped(); //攻击停止

    //qreal damage = 10; //伤害值

    qreal downAcceleration; //重力加速度

    qreal downSpeed; //下降速度

    int capacity; //弓箭容量

    int attackRange; //攻击范围


};

#endif // BOW_H
