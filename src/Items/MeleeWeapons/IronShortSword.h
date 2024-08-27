#ifndef IRONSHORTSWORD_H
#define IRONSHORTSWORD_H

#include "MeleeWeapon.h"

class IronShortSword : public MeleeWeapon
{
public:
    explicit IronShortSword(QGraphicsItem *parent = nullptr);

    void attack();

    void throwWeapon();


};

#endif // IRONSHORTSWORD_H
