#ifndef WOODSHORTSWORD_H
#define WOODSHORTSWORD_H

#include "MeleeWeapon.h"

class WoodShortSword :public MeleeWeapon
{
public:
    explicit WoodShortSword(QGraphicsItem *parent = nullptr);

    void mountToParent() override;

    void unmount() override;

    void attack() override;

    void attackStoped() override;

    int material = 2; //材质，0表示无，1表示铁质，2表示木质

    int element = 0; //元素，0表示无元素，1表示火元素，2表示冰元素，3表示雷元素

    qreal damage = 10; //伤害值
};

#endif // WOODSHORTSWORD_H
