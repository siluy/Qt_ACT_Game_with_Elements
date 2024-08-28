//
// Created by gerw on 8/20/24.
//

#ifndef QT_PROGRAMMING_2024_BATTLESCENE_H
#define QT_PROGRAMMING_2024_BATTLESCENE_H

#include <QKeyEvent>
#include "Scene.h"
#include "../Items/Maps/Map.h"
#include "../Items/Characters/Character.h"
#include "../Items/Blocks/Grassblock.h"
#include "../Items/Blocks/Ironblock.h"
#include "../Items/Blocks/Soilblock.h"
#include "../Items/Blocks/Stoneblock.h"
#include "../Items/Gravity.h"
#include "../Items/MeleeWeapons/IronShortSword.h"
#include "../Items/HealthBar.h"



class BattleScene : public Scene {
Q_OBJECT

public:
    explicit BattleScene(QObject *parent); //构造函数，传入父节点

    void processInput() override; //处理输入

    void processMovement() override; //处理移动

    void processPicking() override; //处理拾取

    static const int blocks[9][16];

    Gravity gravity; //重力

protected slots:

    void update() override; //更新

protected:
    void keyPressEvent(QKeyEvent *event) override; //按键按下事件

    void keyReleaseEvent(QKeyEvent *event) override; //按键释放事件

private:

    Mountable *findNearestUnmountedMountable(const QPointF &pos, qreal distance_threshold = std::numeric_limits<qreal>::max()); //查找最近的未挂载的可挂载物品

    static Mountable * pickupMountable(Character *character, Mountable *mountable); //拾取可挂载物品

    Map *map; //地图
    Character *link;   //角色
    Character *rival; //对手
    Armor *spareArmor; //备用护甲
    Grassblock *grassBlock; //草方块
    Ironblock *ironBlock; //铁方块
    MeleeWeapon *spareMelee; //备用近战武器
    //vector<Item*> dropItems; //掉落物品
    //Battlebackground *battlebackground; //战斗背景
    Stoneblock *stoneBlock; //石头方块
    Soilblock *soilBlock; //土方块
    Blocks* blockGrid[9][16]; // 定义一个9x16的方块指针数组
    HealthBar *healthBarForLink; //角色的生命值条
    HealthBar *healthBarForRival; //对手的生命值条
};  //BattleScene类继承自Scene类，表示战斗场景


#endif //QT_PROGRAMMING_2024_BATTLESCENE_H
