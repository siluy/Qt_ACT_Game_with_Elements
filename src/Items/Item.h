//
// Created by gerw on 8/20/24.
//

#ifndef QT_PROGRAMMING_2024_ITEM_H
#define QT_PROGRAMMING_2024_ITEM_H

#include <QGraphicsItem>
#include <QPainter>

class Item : public QGraphicsItem {
public:
    explicit Item(QGraphicsItem *parent, const QString &pixmapPath); //构造函数，传入父节点和图片路径

    [[nodiscard]] QRectF boundingRect() const override { //重写boundingRect函数，返回pixmapItem的boundingRect，[[nodiscard]]表示函数的返回值不应该被忽略
        if (pixmapItem != nullptr) {
            return this->pixmapItem->boundingRect();
        }
        //返回一个空的矩形，使得空的item不可选择和不可碰撞
        return {};
    } //boundingRect函数返回一个矩形，该矩形是图形项的边界矩形，用于确定图形项的边界，以便在需要时进行重绘

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override {
        // Draw nothing as it is an empty item //不绘制任何东西，因为空项
        // Its pixmapItem is automatically handled by children's paint() //其pixmapItem由子项的paint()函数自动处理
    } //paint函数用于绘制图形项，可以在这里绘制图形项的内容

    int index; //用于标记item的序号

protected:
    QGraphicsPixmapItem *pixmapItem{}; //QGraphicsPixmapItem对象指针，用于绘制图片
};


#endif //QT_PROGRAMMING_2024_ITEM_H
