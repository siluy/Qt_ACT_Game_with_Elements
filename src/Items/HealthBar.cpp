#include "HealthBar.h"
#include <QBrush>

HealthBar::HealthBar(QGraphicsItem* parent, qreal width, qreal height, qreal PosX, qreal PosY) : QGraphicsRectItem(parent), maxWidth(width), height(height) {
    setRect(0, 0, maxWidth, height); // 设置初始矩形
    setBrush(QBrush(Qt::green)); // 设置生命值条的颜色
    setPos(PosX, PosY); // 设置位置
}

void HealthBar::updateHealthBar(qreal health) {
    // 计算当前生命值对应的宽度
    qreal healthBarWidth = (maxWidth * health) / 100;

    // 更新生命值条的矩形大小
    setRect(-50, -220, healthBarWidth, height);

    // 如果生命值较低，可以改变颜色（变为红色）
    if (health <= 20) {
        setBrush(QBrush(Qt::red));
    } else {
        setBrush(QBrush(Qt::green));
    }
}

void HealthBar::mountToParent() {
    // 设置位置
//    setScale(1);
//    setPos(-100, 0);
 //   Mountable::mountToParent();

}
