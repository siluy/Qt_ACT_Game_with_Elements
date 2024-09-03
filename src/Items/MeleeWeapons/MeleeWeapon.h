#ifndef MELEEWEAPON_H
#define MELEEWEAPON_H

#include "../Item.h"
#include "../Mountable.h"
#include "../Throwable.h"

class MeleeWeapon : public Item, public Mountable, public Throwable
{
public:
    explicit MeleeWeapon(QGraphicsItem *parent, const QString &pixmapPath); //构造函数，传入父节点和图片路径

    void mountToParent() override; //挂载到父节点

    void unmount() override; //卸载

    virtual void attack(); //攻击函数

    virtual void attackStoped(); //攻击停止

    QPointF getSpeed() const; //获取速度

    int material; //材质，0表示木质，1表示铁质

    int element; //元素，0表示无元素，1表示火元素，2表示冰元素，3表示雷元素

    qreal damage = 10; //伤害值

    qreal attackRange = 250; //攻击范围

    QPointF speed = QPointF(0, 0); //投掷初速度

    qreal downAcceleration; //重力加速度

    qreal downSpeed; //下降速度

};

#endif // MELEEWEAPON_H
