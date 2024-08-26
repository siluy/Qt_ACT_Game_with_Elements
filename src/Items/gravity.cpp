// gravity.cpp
#include "Gravity.h"

Gravity::Gravity(qreal gravity) : gravity(gravity)/*, onGround(false)*/ {}

qreal Gravity::getGravity() const {
    return gravity;
}

void Gravity::setGravity(qreal newGravity) {
    gravity = newGravity;
}

bool Gravity::isOnGround(QGraphicsItem *item) const {
    QPointF Position = item->pos();
    bool onGround = false;
    int blockX = (int)Position.x() / 80;
    int blockY = (int)Position.y() / 80;
    if (BattleScene::blocks[blockY + 1][blockX] != 0) {
        onGround = true;
    }
    return onGround;
}

void Gravity::applyGravity() {
    //if (!onGround) {
    velocity.setY(velocity.y() + gravity * 1.0 / 90.0);
    //} else {
        // 当物体在地面上时，重置垂直速度
        //velocity.setY(0);
    //}
}

QPointF Gravity::getVelocity() const {
    return velocity;
}

void Gravity::setVelocity(const QPointF &newVelocity) {
    velocity = newVelocity;
}

void Gravity::setOnGround(bool onGroundStatus) {
    //onGround = onGroundStatus;
}
