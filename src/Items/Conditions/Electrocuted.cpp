#include "Electrocuted.h"

Electrocuted::Electrocuted(QGraphicsItem *parent) : Condition(parent, "://Items/Conditions/Electrocuted/be_thunder.png")
{

}

void Electrocuted::mountToParent()
{
    Condition::mountToParent();
    setScale(2); //设置缩放比例
    setPos(-70, -180);  //设置位置
    setVisible(0); //设置可见性
    if (pixmapItem != nullptr) {
        pixmapItem->setPos(0, 0); //设置图片位置
    }
}

void Electrocuted::unmount()
{
    Condition::unmount();
    setScale(0.8);
    if (pixmapItem != nullptr) {
        pixmapItem->setPos(0, -120); //设置图片位置
    }
}
