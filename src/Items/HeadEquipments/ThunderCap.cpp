#include "ThunderCap.h"

ThunderCap::ThunderCap(QGraphicsItem *parent) : HeadEquipment(parent, "://Items/HeadEquipments/ThunderCap/ThunderCap.png") {
    antiElement = 3; //雷抗性
} //构造函数，传入父节点和图片路径
