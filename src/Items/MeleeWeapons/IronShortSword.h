#ifndef IRONSHORTSWORD_H
#define IRONSHORTSWORD_H

#include "MeleeWeapon.h"

class IronShortSword : public MeleeWeapon
{
public:
    explicit IronShortSword(QGraphicsItem *parent = nullptr);

    qreal attack() override;

    void attackStoped() override;

    void throwWeapon();

    void mountToParent() override; //挂载到父节点

    void unmount() override; //卸载

    qreal damage = 10; //伤害值

    int material = 1; //材质，0表示木质，1表示铁质

    int attackRange = 100; //攻击范围

};

#endif // IRONSHORTSWORD_H
