// gravity.cpp
#include "Gravity.h"

Gravity::Gravity(qreal gravity) : gravity(gravity)/*, onGround(false)*/ {}

qreal Gravity::getGravity() const {
    return gravity;
}

void Gravity::setGravity(qreal newGravity) {
    gravity = newGravity;
}

/*bool Gravity::isOnGround(Item *item) const {
    QPointF Position = item->pos();
    bool onGround = false;
    int blockX = (int)Position.x() / 80;
    int blockY = (int)Position.y() / 80;
    int blocks[9][16] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};
    if (blocks[blockY][blockX] != 0) {
        onGround = true;
    }
    return onGround;
}*/

/*void Gravity::applyGravity(Item *item) {
    if (!isOnGround(item)) {
        item->setPos(item->pos() + velocity);
        velocity.setY(velocity.y() + gravity * 1.0 / 90.0);
    } else {
        velocity.setY(0);
    }
}*/

qreal Gravity::getVelocity(Item *item)  {
    velocity = item->downSpeed;
    return velocity;
}

void Gravity::setVelocity(Item *item, double deltaTime) {
    velocity = item->downSpeed + gravity * deltaTime;
    item->downSpeed = velocity;
}

void Gravity::setPos(Item *item, double deltaTime) {
    if(item->downAcceleration != 0)
    {
        auto y = item->downSpeed * deltaTime + 0.5 * gravity * deltaTime * deltaTime;
        item->setPos(item->pos() + QPointF(0, y));
        //if(item->isOnGround(item)){
            //item->downSpeed = 0;
            //item->downAcceleration = 0;
        //}
    }
    else {
        item->setPos(item->pos() + QPointF(0, 0));
    }
}

void Gravity::setOnGround(bool onGround) {
    //onGround = onGroundStatus;
}
