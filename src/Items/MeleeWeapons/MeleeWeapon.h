#ifndef MELEEWEAPON_H
#define MELEEWEAPON_H

#include "../Item.h"
#include "../Mountable.h"

class MeleeWeapon : public Item, public Mountable
{
public:
    explicit MeleeWeapon(QGraphicsItem *parent, const QString &pixmapPath); //构造函数，传入父节点和图片路径

    void mountToParent() override; //挂载到父节点

    void unmount() override; //卸载

    virtual qreal attack(); //攻击函数

    virtual void attackStoped(); //攻击停止

    void throwWeapon(); //投掷武器函数

    int material; //材质，0表示木质，1表示铁质

    qreal damage = 10; //伤害值

    qreal attackRange = 100; //攻击范围
};

#endif // MELEEWEAPON_H
