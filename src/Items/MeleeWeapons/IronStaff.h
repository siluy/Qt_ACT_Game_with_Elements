#ifndef IRONSTAFF_H
#define IRONSTAFF_H

#include "MeleeWeapon.h"

class IronStaff : public MeleeWeapon
{
public:
    explicit IronStaff(QGraphicsItem *parent = nullptr);

    void attack() override;

    void attackStoped() override;

    void mountToParent() override;

    void unmount() override;
};

#endif // IRONSTAFF_H
