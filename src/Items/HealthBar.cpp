#include "HealthBar.h"
#include <QBrush>
#include <qpainter.h>

HealthBar::HealthBar(QGraphicsItem* parent, qreal width, qreal height, qreal PosX, qreal PosY) : QGraphicsRectItem(parent), maxWidth(width), height(height) {
    //setRect(0, 0, 100, 10); // 设置初始矩形
    //setBrush(QBrush(Qt::green)); // 设置生命值条的颜色
    //setPos(PosX, PosY); // 设置位置
}

void HealthBar::updateHealthBar(qreal health) {
    // 计算当前生命值对应的宽度
    //qreal healthBarWidth = health;
    nowHealth = health;

    // 更新生命值条的矩形大小
    //qDebug() << "Setting health bar width to:" << healthBarWidth;
    //setRect(-50, -220, healthBarWidth, height);
    qDebug() << "Rectangle updating";
    // 如果生命值较低，可以改变颜色（变为红色）

}

void HealthBar::mountToParent() {
    // 设置位置
//    setScale(1);
//    setPos(-100, 0);
 //   Mountable::mountToParent();

}

void HealthBar::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                      QWidget *widget) {
    if (nowHealth <= 20) {
        painter->setBrush(QBrush(Qt::red));
    } else {
        painter->setBrush(QBrush(Qt::green));
    }
    painter->drawRect(-50, -220, nowHealth, height);
}
