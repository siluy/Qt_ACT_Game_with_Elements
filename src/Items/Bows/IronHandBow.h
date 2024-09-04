#ifndef IRONHANDBOW_H
#define IRONHANDBOW_H

#include "Bow.h"

class IronHandBow : public Bow
{
public:
    explicit IronHandBow(QGraphicsItem *parent = nullptr);

    void mountToParent() override;

    void unmount() override;
};

#endif // IRONHANDBOW_H
