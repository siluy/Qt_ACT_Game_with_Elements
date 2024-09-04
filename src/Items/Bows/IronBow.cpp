#include "IronBow.h"

IronBow::IronBow(QGraphicsItem *parent) :Bow(parent, "://Items/Weapons/BowsAndArrows/IronBow/IronBow.png"){
    material = 1; //设置材质为铁质
}

//void IronBow::mountToParent() {
    //Bow::mountToParent(); //调用父类的挂载函数，设置为挂载状态
    //setScale(2.0); //设置缩放比例2.0 适合铁弓的大小
    //setPos(-190, -170);  //设置近战武器的位置 适合铁弓的位置
    //if (pixmapItem != nullptr) {
        //pixmapItem->setPos(0, 0); //设置图片位置
    //}
//} //挂载到父节点

//void IronBow::unmount() {
    //Bow::unmount(); //调用父类的卸载函数，设置为未挂载状态
    //setScale(0.8);
    //if (pixmapItem != nullptr) {
        //pixmapItem->setPos(0, -120); //设置图片位置
    //}
//}
