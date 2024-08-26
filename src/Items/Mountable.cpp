//
// Created by gerw on 8/21/24.
//

#include "Mountable.h"

void Mountable::unmount() {
    mounted = false;
} //卸载

bool Mountable::isMounted() const {
    return mounted;
} //是否已挂载

void Mountable::mountToParent() {
    mounted = true;
} //挂载到父节点

//更新速度gravity 更新位置gravity（加速度不为0才更新） 判断方块item（下降速度是否大于0） 按下跳跃设置速度加速度为0.3 0。03

//for (item: items)
