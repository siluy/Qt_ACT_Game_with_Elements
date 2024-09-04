#include "ThunderArmor.h"

ThunderArmor::ThunderArmor(QGraphicsItem *parent) : Armor(parent, "://Items/Armors/ThunderArmor/Thunder_Armor.png") {
    antiElement = 3; //雷抗性
} //构造函数，传入父节点和图片路径
