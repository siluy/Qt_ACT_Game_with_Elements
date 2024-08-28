#ifndef RIVAL_H
#define RIVAL_H

#include "Character.h"

class Rival : public Character {
public:
    explicit Rival(QGraphicsItem *parent = nullptr); //构造函数，传入父节点

    Gravity gravity; //重力
}; //Rival类继承自Character类，表示敌方

#endif // RIVAL_H
