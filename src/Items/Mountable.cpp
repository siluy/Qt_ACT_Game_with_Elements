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

