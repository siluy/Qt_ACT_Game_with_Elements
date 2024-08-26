// gravity.h
#ifndef GRAVITY_H
#define GRAVITY_H

#include "Item.h"
#include <QPointF>
//#include "../Scenes/BattleScene.h"
//#include "../Scenes/Scene.h"

class Gravity {
public:
    explicit Gravity(qreal gravity = 0.005);

    qreal getGravity() const;
    void setGravity(qreal newGravity);

    void applyGravity(Item *item);

    //bool isOnGround(Item *item) const;

    void setOnGround(bool onGround);
    qreal getVelocity(Item *item);
    void setVelocity(Item *item, double deltaTime);
    void setPos(Item *item, double deltaTime);

protected:
    qreal gravity = 0.005;
    qreal velocity = 0.0;
    bool onGround;
};

#endif // GRAVITY_H
