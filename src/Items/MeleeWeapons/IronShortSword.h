#ifndef IRONSHORTSWORD_H
#define IRONSHORTSWORD_H

#include "MeleeWeapon.h"

class IronShortSword : public MeleeWeapon
{
public:
    explicit IronShortSword(QGraphicsItem *parent = nullptr);

    void attack() override;

    void throwWeapon();

    void mountToParent() override; //挂载到父节点

    void unmount() override; //卸载

};

#endif // IRONSHORTSWORD_H
