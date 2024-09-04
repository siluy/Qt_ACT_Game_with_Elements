#include "IceArmor.h"

IceArmor::IceArmor(QGraphicsItem *parent) : Armor(parent, "://Items/Armors/IceArmor/IceArmor.png") {
    antiElement = 2; //冰抗性
} //构造函数，传入父节点和图片路径
