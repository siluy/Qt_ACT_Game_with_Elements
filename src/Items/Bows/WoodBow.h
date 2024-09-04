#ifndef WOODBOW_H
#define WOODBOW_H

#include "Bow.h"

class WoodBow : public Bow
{
public:
    explicit WoodBow(QGraphicsItem *parent = nullptr);
};

#endif // WOODBOW_H
