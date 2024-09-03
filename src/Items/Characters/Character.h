//
// Created by gerw on 8/20/24.
//

// character.h
#ifndef QT_PROGRAMMING_2024_CHARACTER_H
#define QT_PROGRAMMING_2024_CHARACTER_H

#include <QGraphicsEllipseItem>
#include "../HeadEquipments/HeadEquipment.h"
#include "../Armors/Armor.h"
#include "../LegEquipments/LegEquipment.h"
#include "../Gravity.h"
#include "../MeleeWeapons/MeleeWeapon.h"
#include "../Bows/Bow.h"
#include "../Arrows/Arrow.h"
#include <QTimer>
#include "../Conditions/Fire.h"
#include "../Conditions/Frozen.h"
#include "../Conditions/Electrocuted.h"
#include "../../Items/Item.h"

class BattleScene;

class Character : public Item, public QObject {
    Q_OBJECT
public:
    explicit Character(QGraphicsItem *parent); //构造函数，传入父节点

    [[nodiscard]] bool isLeftDown() const; //是否按下左键

    void setLeftDown(bool leftDown); //设置左键是否按下

    [[nodiscard]] bool isRightDown() const; //是否按下右键

    void setRightDown(bool rightDown); //设置右键是否按下

    [[nodiscard]] bool isJumpDown() const; //是否按下跳跃键

    void setJumpDown(bool jumpDown); //设置跳跃键是否按下

    [[nodiscard]] bool isPickDown() const; //是否按下拾取键

    void setPickDown(bool pickDown); //设置拾取键是否按下

    [[nodiscard]] bool isAttackDown() const; //是否按下攻击键

    void setAttackDown(bool attackDown); //设置攻击键是否按下

    [[nodiscard]] bool isThrowDown() const; //是否按下投掷键

    void setThrowDown(bool throwDown); //设置投掷键是否按下

    [[nodiscard]] bool isChangeDown() const; //是否按下切换武器键

    void setChangeDown(bool changeDown); //设置切换武器键是否按下

    [[nodiscard]] bool isChangeArrowDown() const; //是否按下切换箭键

    void setChangeArrowDown(bool changeArrowDown); //设置切换箭键是否按下

    [[nodiscard]] const QPointF &getVelocity() const; //获取速度

    [[nodiscard]] bool isPicking() const; //是否在拾取

    void setVelocity(const QPointF &velocity); //设置速度

    void processInput(); //处理输入

    Armor* pickupArmor(Armor* newArmor); //拾取护甲

    MeleeWeapon* pickupMelee(MeleeWeapon* newMeleeWeapon); //拾取近战武器

    Bow* pickupBow(Bow* newBow); //拾取弓

    Gravity gravity; //重力

    bool isOnGround() const; //是否在地面上

    MeleeWeapon *melee{nullptr}; //近战武器

    Bow *bow{nullptr}; //弓

    QVector<Arrow*> arrows; //箭

    int arrowNum = 0; //箭数量

    bool isArrowFired = false;  // 用于标记是否已射箭

    Arrow* pickupArrow(Arrow* newArrow); //拾取箭

    QVector<Arrow*> removeAllArrows(); //移除所有箭

    void removeArrow(Arrow* selected); //移除箭

    qreal health = 100.0; //生命值

    void setHealth(qreal health); //设置生命值

    void updateHealthBar(); //更新生命值条

    QPointF getDirection() const; //获取朝向

    void throwWeapon(); //投掷武器

    void archery(); //射箭

    bool checkCollision(); //检查碰撞

    void changeWeapon(); //切换武器

    void changeArrow(); //切换箭

    bool onFire = false; //是否着火

    bool beThundered = false; //是否被雷击

    bool beFrozen = false; //是否被冻结

    void setMovable(bool movable); //设置是否可移动

    Fire* fireEffect = nullptr;    // 火焰特效
    Frozen* frozenEffect = nullptr;  // 冰冻特效
    Electrocuted* electrocutedEffect = nullptr; // 雷电特效

    QTimer* fireTimer = nullptr;
    QTimer* freezeTimer = nullptr;
    QTimer* thunderTimer = nullptr;

    void initEffects();
    void startFireEffect();
    void startFrozenEffect();
    void startThunderEffect();
    void stopAllEffects();
    void updateHealth(qreal damage);

    bool isOnMetalPlatform() const; //是否在金属平台上

    void startThunderEffect(BattleScene* scene);



protected:
    HeadEquipment *headEquipment{}; //头部装备
    LegEquipment *legEquipment{}; //腿部装备
    Armor *armor{}; //护甲
    QPointF velocity{}; //速度
    //HealthBar *healthBar{}; //生命值条
    QGraphicsRectItem *healthBar; //生命值条

    //    QGraphicsEllipseItem *ellipseItem; //椭圆图形项，用于绘制角色的碰撞体积，debug用
private:
    bool leftDown{}, rightDown{}, pickDown{}, jumpDown{}, attackDown{}, throwDown{}, changeDown{}, changeArrowDown{}; //左键、右键、拾取键是否按下
    bool lastPickDown{}; //上一次拾取键是否按下
    bool picking{}; //是否在拾取
    bool onGround{}; //是否在地面上
    bool movable = true; //是否可移动

};


#endif //QT_PROGRAMMING_2024_CHARACTER_H
