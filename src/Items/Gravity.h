// gravity.h
#ifndef GRAVITY_H
#define GRAVITY_H

#include <QGraphicsItem>
#include <QPointF>

class Gravity {
public:
    explicit Gravity(qreal gravity = 1);

    qreal getGravity() const;
    void setGravity(qreal newGravity);

    void applyGravity();

    void setOnGround(bool onGround);
    QPointF getVelocity() const;
    void setVelocity(const QPointF &velocity);

protected:
    qreal gravity;
    QPointF velocity = {0.0,0.0};
    //bool onGround;
};

#endif // GRAVITY_H
