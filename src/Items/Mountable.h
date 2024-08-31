//
// Created by gerw on 8/21/24.
//

#ifndef QT_PROGRAMMING_2024_MOUNTABLE_H
#define QT_PROGRAMMING_2024_MOUNTABLE_H


class Mountable {
public:
    virtual void mountToParent(); //挂载到父节点

    virtual void unmount(); //卸载

    [[nodiscard]] bool isMounted() const; //是否已挂载


private:
    bool mounted{}; //是否已挂载
};


#endif //QT_PROGRAMMING_2024_MOUNTABLE_H
