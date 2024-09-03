#ifndef THUNDERSWORD_H
#define THUNDERSWORD_H

#include "MeleeWeapon.h"

class ThunderSword : public MeleeWeapon
{
public:
    explicit ThunderSword(QGraphicsItem *parent = nullptr);

    void attack() override;

    void attackStoped() override;

    void mountToParent() override;

    void unmount() override;

    int element = 3; //元素，0表示无元素，1表示火元素，2表示冰元素，3表示雷元素

    int material = 0; //材质，0表示无，1表示铁质，2表示木质
};

#endif // THUNDERSWORD_H
