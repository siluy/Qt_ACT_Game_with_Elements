#include "HairOfTheHero.h"

HairOfTheHero::HairOfTheHero(QGraphicsItem *parent) : HeadEquipment(parent,
                    ":/Items/HeadEquipments/HairOfTheHero/HairOfTheHero.png") {
    antiElement = 0; //无抗性
}
//HairOfTheHero类的构造函数，传入父节点，调用基类构造函数，传入父节点和图片路径
