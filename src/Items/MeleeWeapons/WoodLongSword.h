#ifndef WOODLONGSWORD_H
#define WOODLONGSWORD_H

#include "MeleeWeapon.h"

class WoodLongSword : public MeleeWeapon
{
public:
    explicit WoodLongSword(QGraphicsItem *parent = nullptr);

    void attack() override;

    void attackStoped() override;

    void mountToParent() override;

    void unmount() override;
};

#endif // WOODLONGSWORD_H
