// gravity.h
#ifndef GRAVITY_H
#define GRAVITY_H

#include <QGraphicsItem>
#include <QPointF>
//#include "../Scenes/BattleScene.h"

class Gravity {
public:
    explicit Gravity(qreal gravity = 0.1);

    qreal getGravity() const;
    void setGravity(qreal newGravity);

    void applyGravity();

    bool isOnGround(QGraphicsItem *Item) const;

    void setOnGround(bool onGround);
    QPointF getVelocity() const;
    void setVelocity(const QPointF &velocity);

protected:
    qreal gravity = 0.1;
    QPointF velocity = {0.0,0.0};
    bool onGround;
};

#endif // GRAVITY_H
