#ifndef NORMALARROW_H
#define NORMALARROW_H

#include "Arrow.h"

class NormalArrow: public Arrow
{
public:
    explicit NormalArrow(QGraphicsItem *parent = nullptr);

    bool beThrown = false;
};

#endif // NORMALARROW_H
