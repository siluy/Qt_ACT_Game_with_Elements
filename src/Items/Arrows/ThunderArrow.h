#ifndef THUNDERARROW_H
#define THUNDERARROW_H

#include "Arrow.h"

class ThunderArrow : public Arrow
{
public:
    explicit ThunderArrow(QGraphicsItem *parent = nullptr);

    bool beThrown = false;

    int element = 3; //元素，0表示无元素，1表示火元素，2表示冰元素，3表示雷元素
};

#endif // THUNDERARROW_H
