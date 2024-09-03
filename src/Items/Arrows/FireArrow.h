#ifndef FIREARROW_H
#define FIREARROW_H

#include "Arrow.h"

class FireArrow : public Arrow
{
public:
    explicit FireArrow(QGraphicsItem *parent = nullptr);

    bool beThrown = false;

    int element = 1; //元素，0表示无元素，1表示火元素，2表示冰元素，3表示雷元素
};

#endif // FIREARROW_H
