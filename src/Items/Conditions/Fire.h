#ifndef FIRE_H
#define FIRE_H

#include "Condition.h"

class Fire : public Condition
{
public:
    explicit Fire(QGraphicsItem *parent = nullptr);

    void mountToParent() override;

    void unmount() override;
};

#endif // FIRE_H
