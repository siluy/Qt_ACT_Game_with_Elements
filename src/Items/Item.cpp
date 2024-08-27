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
    QPointF Position = item->pos();
    bool onGround = false;
    int blockX = (int)Position.x() / 80;
    int blockY = (int)Position.y() / 80;
    double absence = 30;
    //int n_blockX = (int)(Position.x() + absence) / 80;
    int n_blockY = (int)(Position.y() + absence) / 80;
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
    //判断当前位置是否为空
    if (blocks[blockY][blockX] == 0 && blocks[n_blockY][blockX] != 0) {
        onGround = false;}
    return onGround;
} //判断item是否在地面上

void Item::setAcceleration() {
    if(isOnGround(this)) {
        downAcceleration = 0;
        downSpeed = 0;
    } //else {
        //downAcceleration = 0.03;
    //}
} //设置加速度
