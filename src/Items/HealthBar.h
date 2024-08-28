#ifndef HEALTHBAR_H
#define HEALTHBAR_H

#include <QGraphicsRectItem>
#include "Mountable.h"

class HealthBar : public QGraphicsRectItem, public Mountable {
public:
    explicit HealthBar(QGraphicsItem* parent = nullptr, qreal width = 100, qreal height = 10, qreal PosX = 0, qreal PosY = 0); // 构造函数

    void updateHealthBar(qreal health); // 更新生命值条

    void mountToParent() override; //挂载到父节点

private:
    qreal maxWidth; // 最大宽度
    qreal height; // 高度
};

#endif // HEALTHBAR_H