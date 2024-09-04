//
// Created by gerw on 8/20/24.
//

#include "Item.h"

Item::Item(QGraphicsItem *parent, const QString &pixmapPath) : QGraphicsItem(parent) {
    if (pixmapPath != "") {
        pixmapItem = new QGraphicsPixmapItem(QPixmap(pixmapPath), this);
    } //如果图片路径不为空，创建一个QGraphicsPixmapItem对象
}

bool Item::isOnGround(Item *item) {
    if (item != nullptr) {
        QPointF Position = item->pos();
        int blockX = static_cast<int>(Position.x()) / 80;
        int blockY = static_cast<int>(Position.y()) / 80;
        double absence = 30;
        int n_blockY = static_cast<int>(Position.y() + absence) / 80;

        if (blockY < 0 || blockY >= 9 || blockX < 0 || blockX >= 16) {
            return false;  // 防止越界访问
        }

        if (blocks[blockY][blockX] != 0) {
            return true;
        }

        if (blocks[blockY][blockX] == 0 && blocks[n_blockY][blockX] != 0) {
            return false;
        }
    }
    return false;
}

void Item::setAcceleration() {
    if(isOnGround(this)) {
        downAcceleration = 0;
        downSpeed = 0;
    } else {
        downAcceleration = 0.03;
    }
} //设置加速度

int Item::blocks[9][16] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}}; //地图
