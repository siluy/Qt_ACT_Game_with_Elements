#include "FlameCap.h"

FlameCap::FlameCap(QGraphicsItem *parent) : HeadEquipment(parent, "://Items/HeadEquipments/FlameCap/FlameCap.png") {
    antiElement = 1; //火焰抗性
} //构造函数，传入父节点和图片路径
