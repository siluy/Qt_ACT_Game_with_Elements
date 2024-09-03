#ifndef IRONBLOCK_H
#define IRONBLOCK_H

#include "Blocks.h"
//#include "../Conditions/Electrocuted.h"

class Ironblock : public Blocks
{
public:
    explicit Ironblock(QGraphicsItem *parent = nullptr);

    //Electrocuted* electrocuted = nullptr; //电击效果
};

#endif // IRONBLOCK_H
