//
// Created by gerw on 8/20/24.
//

#include <QTransform>
#include <qgraphicsscene.h>
#include "Character.h"
#include "../Gravity.h"

Character::Character(QGraphicsItem *parent) : Item(parent, "") {
    //    ellipseItem = new QGraphicsEllipseItem(-5, -5, 10, 10, this); //创造一个椭圆，位置在(-5,-5)，大小为10*10，父节点为当前节点
    //    // Optionally, set some properties of the ellipse //可选，设置椭圆的一些属性
    //    ellipseItem->setBrush(Qt::green);          // Fill color //填充颜色
    //    ellipseItem->setZValue(1); // Draw on top of the pixmap //绘制在图片的上面 //设置Z值为1，Z值表示绘制顺序，数值越大越靠上
} //构造函数，传入父节点

bool Character::isLeftDown() const {
    return leftDown;
} //是否按下左键

void Character::setLeftDown(bool leftDown) {
    Character::leftDown = leftDown;
} //设置左键是否按下

bool Character::isRightDown() const {
    return rightDown;
} //是否按下右键

void Character::setRightDown(bool rightDown) {
    Character::rightDown = rightDown;
} //设置右键是否按下

bool Character::isJumpDown() const {
    return jumpDown;
} //是否按下跳跃键

void Character::setJumpDown(bool jumpDown) {//TODO  给人赋值速度加速度
    Character::jumpDown = jumpDown;
} //设置跳跃键是否按下

bool Character::isPickDown() const {
    return pickDown;
} //是否按下拾取键

void Character::setPickDown(bool pickDown) {
    Character::pickDown = pickDown;
} //设置拾取键是否按下

bool Character::isAttackDown() const {
    return attackDown;
} //是否按下攻击键

void Character::setAttackDown(bool attackDown) {
    Character::attackDown = attackDown;
} //设置攻击键是否按下

const QPointF &Character::getVelocity() const {
    return velocity;
} //获取速度

void Character::setVelocity(const QPointF &velocity) {
    Character::velocity = velocity;
} //设置速度

bool Character::isOnGround() const {
    QRectF characterRect = mapToScene(boundingRect()).boundingRect(); //获取边界矩形
    QRectF sceneRect = sceneBoundingRect(); //获取场景矩形
    qreal groundY = sceneRect.top() + (sceneRect.top() - sceneRect.bottom()) * 0.5; //获取地面高度
    bool onGround = characterRect.bottom() >= groundY; //是否在地面上
    return onGround; //是否在地面上
} //是否在地面上

void Character::processInput() {
    //auto velocity = QPointF(0, 0); //速度初始化为0
    const auto moveSpeed = 0.3; // 移动速度
    const auto jumpSpeed = 0.5; // 跳跃速度

    if (isLeftDown()) {
        velocity.setX(qMax(velocity.x() - moveSpeed,-0.3)); // 左键按下，速度向左增加
        setTransform(QTransform().scale(1, 1)); // 设置角色的水平翻转
    }
    if (isRightDown()) {
        velocity.setX(qMin(velocity.x() + moveSpeed,0.3)); // 右键按下，速度向右增加
        setTransform(QTransform().scale(-1, 1)); // 设置角色的水平翻转
    }
    else{
        //如果没有按下任何水平移动的按键，速度向0靠近
        if (velocity.x() > 0) {
            velocity.setX(qMax(velocity.x() - moveSpeed/2, 0.0));
        } else if (velocity.x() < 0) {
            velocity.setX(qMin(velocity.x() + moveSpeed/2, 0.0));
        }
    }
    if(isAttackDown()){
        //attack
        melee->attack();
    }
    if (isJumpDown()&&isOnGround()) {
        // 跳跃键按下，只有在地面上时才允许跳跃
        //velocity.setY(-jumpSpeed); // 设置向上的速度
        //gravity.applyGravity(); //应用重力
    }
    //gravity.applyGravity(); //应用重力

    //setVelocity(velocity); // 设置速度

    if (!lastPickDown && pickDown) { // first time pickDown //拾取键第一次按下
        picking = true; //设置为拾取
    } else {
        picking = false; //否则不拾取
    }
    lastPickDown = pickDown; //设置上一次拾取键是否按下
} //处理输入

bool Character::isPicking() const {
    return picking; //是否在拾取
} //是否在拾取

Armor *Character::pickupArmor(Armor *newArmor) {
    auto oldArmor = armor; //旧护甲
    if (oldArmor != nullptr) { //如果旧护甲不为空
        oldArmor->unmount(); //卸载旧护甲
        oldArmor->setPos(newArmor->pos()); //设置旧护甲位置为新护甲位置
        oldArmor->setParentItem(parentItem());  //设置旧护甲的父节点为当前节点
    }
    newArmor->setParentItem(this); //设置新护甲的父节点为当前节点
    newArmor->mountToParent(); //挂载新护甲到父节点
    armor = newArmor; //设置新护甲
    return oldArmor; //返回旧护甲
} //拾取护甲

MeleeWeapon *Character::pickupMelee(MeleeWeapon *newMelee) {
    auto oldMelee = melee; //旧近战武器
    if (oldMelee != nullptr) { //如果旧近战武器不为空
        oldMelee->unmount(); //卸载旧近战武器
        oldMelee->setPos(newMelee->pos()); //设置旧近战武器位置为新近战武器位置
        oldMelee->setParentItem(parentItem());  //设置旧近战武器的父节点为当前节点
    }
    if (oldMelee == nullptr) {
        newMelee->setParentItem(this); //设置新近战武器的父节点为当前节点
        newMelee->mountToParent(); //挂载新近战武器到父节点
        melee = newMelee; //设置新近战武器
    }
    newMelee->setParentItem(this); //设置新近战武器的父节点为当前节点
    newMelee->mountToParent(); //挂载新近战武器到父节点
    melee = newMelee; //设置新近战武器
    return oldMelee; //返回旧近战武器
} //拾取近战武器

void Character::setHealth(qreal health) {
    qDebug() << "Setting health to:" << health;
    healthBar->updateHealthBar(health);
    qDebug() << "setHealth finished.";
}


//void Character::updateHealthBar(){
    //qreal healthBarWidth = (healthBar.width * health) / 100; //生命值是0-100，计算生命值条的宽度
    //healthBar->setRect(0,0,healthBarWidth,10); //设置生命值条的矩形
//}
