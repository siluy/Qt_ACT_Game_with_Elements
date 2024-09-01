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

class Character : public Item {
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

    Arrow* pickupArrow(Arrow* newArrow); //拾取箭

    QVector<Arrow*> removeAllArrows(); //移除所有箭

    Arrow* removeArrow(int index); //移除箭

    qreal health = 100.0; //生命值

    void setHealth(qreal health); //设置生命值

    void updateHealthBar(); //更新生命值条

    QPointF getDirection() const; //获取朝向

    void throwWeapon(); //投掷武器

    bool checkCollision(); //检查碰撞

protected:
    HeadEquipment *headEquipment{}; //头部装备
    LegEquipment *legEquipment{}; //腿部装备
    Armor *armor{}; //护甲
    QPointF velocity{}; //速度
    //HealthBar *healthBar{}; //生命值条
    QGraphicsRectItem *healthBar; //生命值条

    //    QGraphicsEllipseItem *ellipseItem; //椭圆图形项，用于绘制角色的碰撞体积，debug用
private:
    bool leftDown{}, rightDown{}, pickDown{}, jumpDown{}, attackDown{}, throwDown{}; //左键、右键、拾取键是否按下
    bool lastPickDown{}; //上一次拾取键是否按下
    bool picking{}; //是否在拾取
    bool onGround{}; //是否在地面上
};


#endif //QT_PROGRAMMING_2024_CHARACTER_H
