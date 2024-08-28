#include "Rival.h"
#include <memory>
#include "../HeadEquipments/HairOfTheHero.h"
#include "../Armors/OldShirt.h"
#include "../LegEquipments/WellWornTrousers.h"

Rival::Rival(QGraphicsItem *parent) : Character(parent) {
    headEquipment = new HairOfTheHero(this); //创建一个CapOfTheHero对象
    legEquipment = new WellWornTrousers(this); //创建一个WellWornTrousers对象，表示破旧的裤子，传入父节点
    armor = new OldShirt(this); //创建一个OldShirt对象，表示破旧的衬衫，传入父节点
    headEquipment->mountToParent(); //将headEquipment挂载到父节点
    legEquipment->mountToParent(); //将legEquipment挂载到父节点
    armor->mountToParent(); //将armor挂载到父节点
} //Rival类的构造函数，传入父节点，创建一个HairOfTheHero对象，一个WellWornTrousers对象，一个OldShirt对象，将headEquipment、legEquipment、armor挂载到父节点
