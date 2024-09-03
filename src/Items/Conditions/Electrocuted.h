#ifndef ELECTROCUTED_H
#define ELECTROCUTED_H

#include "Condition.h"

class Electrocuted : public Condition
{
public:
    explicit Electrocuted(QGraphicsItem *parent = nullptr);

    void mountToParent() override;

    void unmount() override;
};

#endif // ELECTROCUTED_H
