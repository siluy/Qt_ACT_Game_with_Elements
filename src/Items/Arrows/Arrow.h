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

    QPointF getSpeed() const; //获取速度

    qreal damage = 10; //伤害值

    int element = 0; //元素，0表示无元素，1表示火元素，2表示冰元素，3表示雷元素

    qreal downAcceleration; //重力加速度

    qreal downSpeed; //下降速度

    QPointF speed; //速度
};

#endif // ARROW_H
