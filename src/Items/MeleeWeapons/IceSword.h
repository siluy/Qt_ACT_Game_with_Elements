#ifndef ICESWORD_H
#define ICESWORD_H

#include "MeleeWeapon.h"

class IceSword : public MeleeWeapon
{
public:
    explicit IceSword(QGraphicsItem *parent = 0);

    void attack() override;

    void attackStoped() override;

    void mountToParent() override;

    void unmount() override;

    int element = 2; //元素，0表示无元素，1表示火元素，2表示冰元素，3表示雷元素

    int material = 0; //材质，0表示无，1表示铁质，2表示木质
};

#endif // ICESWORD_H
