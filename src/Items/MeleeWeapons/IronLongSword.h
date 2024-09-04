#ifndef IRONLONGSWORD_H
#define IRONLONGSWORD_H

#include "MeleeWeapon.h"

class IronLongSword : public MeleeWeapon
{
public:
    explicit IronLongSword(QGraphicsItem *parent = nullptr);

    void attack() override;

    void attackStoped() override;

    void mountToParent() override;

    void unmount() override;


};

#endif // IRONLONGSWORD_H
