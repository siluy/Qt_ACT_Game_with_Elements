#ifndef FROZEN_H
#define FROZEN_H

#include "Condition.h"

class Frozen : public Condition
{
public:
    Frozen(QGraphicsItem *parent = nullptr);

    void mountToParent() override;

    void unmount() override;
};

#endif // FROZEN_H
