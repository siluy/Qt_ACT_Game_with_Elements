#include "Frozen.h"

Frozen::Frozen(QGraphicsItem *parent) : Condition(parent, "://Items/Conditions/BeFrozen/BeFrozen.png")
{

}

void Frozen::mountToParent()
{
    Condition::mountToParent();
    setScale(0.3);
    setPos(-50, -80);
    setVisible(0);
    if (pixmapItem != nullptr) {
        pixmapItem->setPos(0, 0);
    }
}

void Frozen::unmount()
{
    Condition::unmount();
    setScale(0.8);
    if (pixmapItem != nullptr) {
        pixmapItem->setPos(0, -120);
    }
}
