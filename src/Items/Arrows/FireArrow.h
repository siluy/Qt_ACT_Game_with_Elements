#ifndef FIREARROW_H
#define FIREARROW_H

#include "Arrow.h"

class FireArrow : public Arrow
{
public:
    explicit FireArrow(QGraphicsItem *parent = nullptr);

    bool beThrown = false;
};

#endif // FIREARROW_H
