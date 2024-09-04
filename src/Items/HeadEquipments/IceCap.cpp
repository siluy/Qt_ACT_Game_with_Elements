#include "IceCap.h"

IceCap::IceCap(QGraphicsItem *parent) : HeadEquipment(parent, "://Items/HeadEquipments/IceCap/IceCap.png") {
    antiElement = 2; //冰抗性
} //构造函数，传入父节点和图片路径
