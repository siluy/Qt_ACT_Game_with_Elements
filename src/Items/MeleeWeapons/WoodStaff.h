#ifndef WOODSTAFF_H
#define WOODSTAFF_H

#include "MeleeWeapon.h"

class WoodStaff : public MeleeWeapon
{
public:
    explicit WoodStaff(QGraphicsItem *parent = nullptr);

    void attack() override;

    void attackStoped() override;

    void mountToParent() override;

    void unmount() override;
};

#endif // WOODSTAFF_H
