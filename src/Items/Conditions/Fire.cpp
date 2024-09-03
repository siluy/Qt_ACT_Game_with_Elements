#include "Fire.h"

Fire::Fire(QGraphicsItem *parent) : Condition(parent, "://Items/Conditions/OnFire/be_fire.png")
{

}

void Fire::mountToParent()
{
    Condition::mountToParent();
    setScale(0.8);
    setPos(-90, -200);
    setVisible(0);
    if (pixmapItem != nullptr) {
        pixmapItem->setPos(0, 0);
    }
}

void Fire::unmount()
{
    Condition::unmount();
    setScale(0.8);
    if (pixmapItem != nullptr) {
        pixmapItem->setPos(0, -120);
    }
}
