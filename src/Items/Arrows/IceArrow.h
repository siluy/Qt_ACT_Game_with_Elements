#ifndef ICEARROW_H
#define ICEARROW_H

#include "Arrow.h"

class IceArrow : public Arrow
{
public:
    explicit IceArrow(QGraphicsItem *parent = nullptr);

    bool beThrown = false;

    int element = 2; //元素，0表示无元素，1表示火元素，2表示冰元素，3表示雷元素
};

#endif // ICEARROW_H
