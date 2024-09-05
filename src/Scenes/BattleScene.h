//
// Created by gerw on 8/20/24.
//

#ifndef QT_PROGRAMMING_2024_BATTLESCENE_H
#define QT_PROGRAMMING_2024_BATTLESCENE_H

#include <QKeyEvent>
#include <QTimer>
#include <QRandomGenerator>
#include "Scene.h"
#include "../Items/Maps/Map.h"
#include "../Items/Characters/Character.h"
#include "../Items/Blocks/Grassblock.h"
#include "../Items/Blocks/Ironblock.h"
#include "../Items/Blocks/Soilblock.h"
#include "../Items/Blocks/Stoneblock.h"
#include "../Items/Gravity.h"
#include "../Items/MeleeWeapons/IronShortSword.h"
#include "../Items/MeleeWeapons/WoodShortSword.h"
#include "../Items/MeleeWeapons/FireSword.h"
#include "../Items/MeleeWeapons/IceSword.h"
#include "../Items/MeleeWeapons/ThunderSword.h"
#include "../Items/Bows/IronBow.h"
#include "../Items/Bows/Bow.h"
#include "../Items/Arrows/Arrow.h"
#include "../Items/Arrows/NormalArrow.h"
#include "../Items/Arrows/FireArrow.h"
#include "../Items/Arrows/IceArrow.h"
#include "../Items/Arrows/ThunderArrow.h"
#include "../Items/Conditions/Fire.h"
#include "../Items/Conditions/Electrocuted.h"
#include "../Items/Conditions/Frozen.h"
#include "../Items/Characters/Link.h"
#include "../Items/Characters/Rival.h"
#include "../Items/Maps/battlebackground.h"
#include "../Items/Armors/FlamebreakerArmor.h"
#include "../Items/Armors/OldShirt.h"
#include "../Items/Armors/IceArmor.h"
#include "../Items/Armors/ThunderArmor.h"
#include "../Items/HeadEquipments/ThunderCap.h"
#include "../Items/HeadEquipments/IceCap.h"
#include "../Items/HeadEquipments/FlameCap.h"
#include "../Items/HeadEquipments/CapOfTheHero.h"
#include "../Items/LegEquipments/IceTrousers.h"
#include "../Items/LegEquipments/ThunderTrousers.h"
#include "../Items/LegEquipments/FlameTrousers.h"
#include "../Items/LegEquipments/WellWornTrousers.h"
#include "../Items/MeleeWeapons/IronLongSword.h"
#include "../Items/MeleeWeapons/WoodLongSword.h"
#include "../Items/MeleeWeapons/FireSword.h"
#include "../Items/MeleeWeapons/IceSword.h"
#include "../Items/MeleeWeapons/ThunderSword.h"
#include "../Items/MeleeWeapons/IronStaff.h"
#include "../Items/MeleeWeapons/WoodStaff.h"
#include "../Items/MeleeWeapons/IronShortSword.h"
#include "../Items/MeleeWeapons/WoodShortSword.h"
#include "../Items/Bows/IronBow.h"
#include "../Items/Bows/WoodBow.h"
#include "../Items/Bows/IronStrongBow.h"
#include "../Items/Bows/WoodStrongBow.h"
#include "../Items/Bows/IronHandBow.h"
#include "../Items/Bows/WoodHandBow.h"
#include "../Items/Arrows/NormalArrow.h"
#include "../Items/Arrows/FireArrow.h"
#include "../Items/Arrows/IceArrow.h"
#include "../Items/Arrows/ThunderArrow.h"
#include "GameOverDialog.h"


class BattleScene : public Scene {
Q_OBJECT

public:
    explicit BattleScene(QObject *parent); //构造函数，传入父节点

    void processInput() override; //处理输入

    void processMovement() override; //处理移动

    void processPicking() override; //处理拾取

    void processThrow(Item* item); //处理投掷

    void processMeleeThrow(MeleeWeapon* meleeWeapon); //处理近战投掷

    void processArrowThrow(Arrow* arrow); //处理箭投掷

    void applyMeleeEffect(MeleeWeapon* melee, Character* victim); //应用元素效果

    void applyArrowEffect(Arrow* arrow, Character* victim); //应用元素效果

    static const int blocks[9][16];

    Gravity gravity; //重力

    bool attackTrue(Character *attacker, Character *victim); //能否完成攻击

    void attackDone(Character *attacker, Character *victim); //攻击

    void spreadThunderEffect(Character* character); //传播雷电效果

    void propagateThunderEffect(int startX, int y, int direction);

    void spreadFire(int i, int j); //传播火焰

    void igniteBlockIfLanded(Item* item); //如果物品落地，点燃方块

    void checkGameOver(); //检查游戏是否结束

    void showGameOverDialog(const QString& winner); //显示游戏结束对话框

    void restartGame(); //重新开始游戏

    void quitGame(); //退出游戏

public slots:
    void spawnItem(const QString &itemType); //生成物品

    void spawnRandomItem();
    void removeItemAfterDelay(Item* item);

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
    FlamebreakerArmor *flamebreakerArmor; //火焰护甲
    OldShirt *oldShirt; //旧衬衫
    IceArmor *iceArmor; //冰护甲
    ThunderArmor *thunderArmor; //雷护甲

    ThunderCap *thunderCap; //雷帽
    IceCap *iceCap; //冰帽
    FlameCap *flameCap; //火帽
    CapOfTheHero *capOfTheHero; //英雄帽

    IceTrousers *iceTrousers; //冰裤
    ThunderTrousers *thunderTrousers; //雷裤
    FlameTrousers *flameTrousers; //火裤
    WellWornTrousers *wellWornTrousers; //破旧裤

    Grassblock *grassBlock; //草方块
    Ironblock *ironBlock; //铁方块

    MeleeWeapon *spareMelee; //空近战武器
    IronShortSword *ironShortSword; //铁短剑
    WoodShortSword *woodShortSword; //木短剑
    IronLongSword *ironLongSword; //铁长剑
    WoodLongSword *woodLongSword; //木长剑
    IronStaff *ironStaff; //铁杖
    WoodStaff *woodStaff; //木杖
    FireSword *fireSword; //火剑
    IceSword *iceSword; //冰剑
    ThunderSword *thunderSword; //雷剑

    Bow *spareBow; //空弓
    IronBow *ironBow; //铁弓
    WoodBow *woodBow; //木弓
    IronStrongBow *ironStrongBow; //铁强弓
    WoodStrongBow *woodStrongBow; //木强弓
    IronHandBow *ironHandBow; //铁手弓
    WoodHandBow *woodHandBow; //木手弓

    Arrow *spareArrow; //空箭
    NormalArrow *normalArrow; //普通箭
    FireArrow *fireArrow; //火箭
    IceArrow *iceArrow; //冰箭
    ThunderArrow *thunderArrow; //雷箭

    QVector<Item*> dropItems; //掉落物品
    QVector<MeleeWeapon*> Melees; //近战武器
    QVector<Armor*> Armors; //护甲
    QVector<Character*> Characters; //角色
    Stoneblock *stoneBlock; //石头方块
    Soilblock *soilBlock; //土方块
    Blocks* blockGrid[9][16]; // 定义一个9x16的方块指针数组
    Condition *conditions[9][16]; // 定义一个9x16的状态指针数组
    Fire *fireOfLink; //火
    Electrocuted *electrocutedOfLink; //电
    Frozen *frozenOfLink; //冰
    Fire *fireOfRival; //火
    Electrocuted *electrocutedOfRival; //电
    Frozen *frozenOfRival; //冰

    QTimer *spawnTimer;
    QList<Item*> fallItems; // 用于存储掉落物品的列表
    void applyGravity(Item* item); // 应用重力

    //QGraphicsView *view; //视图
};  //BattleScene类继承自Scene类，表示战斗场景


#endif //QT_PROGRAMMING_2024_BATTLESCENE_H
