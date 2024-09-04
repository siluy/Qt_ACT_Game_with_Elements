#ifndef WOODHANDBOW_H
#define WOODHANDBOW_H

#include "Bow.h"

class WoodHandBow : public Bow
{
public:
    explicit WoodHandBow(QGraphicsItem *parent = nullptr);

    void mountToParent() override;

    void unmount() override;
};

#endif // WOODHANDBOW_H
