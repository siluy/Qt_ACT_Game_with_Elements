#ifndef BLOCKS_H
#define BLOCKS_H

#include "../Item.h"
#include "../Conditions/Electrocuted.h"
#include "../Conditions/Fire.h"
class Blocks : public Item
{
public:
    explicit Blocks(QGraphicsItem *parent, const QString &pixmapPath);

    Fire* fire = nullptr; //火效果

    Electrocuted* electrocuted = nullptr; //电击效果

};

#endif // BLOCKS_H
