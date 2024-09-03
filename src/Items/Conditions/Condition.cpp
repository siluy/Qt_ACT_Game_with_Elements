#include "Condition.h"

Condition::Condition(QGraphicsItem *parent, const QString &pixmapPath) : Item(parent, pixmapPath)
{

}

void Condition::mountToParent()
{
    Mountable::mountToParent();
}

void Condition::unmount()
{
    Mountable::unmount();
}
