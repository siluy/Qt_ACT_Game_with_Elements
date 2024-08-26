//
// Created by gerw on 8/20/24.
//

#include "Item.h"

Item::Item(QGraphicsItem *parent, const QString &pixmapPath) : QGraphicsItem(parent) {
    if (pixmapPath != "") {
        pixmapItem = new QGraphicsPixmapItem(QPixmap(pixmapPath), this);
    } //如果图片路径不为空，创建一个QGraphicsPixmapItem对象
}
