//
// Created by gerw on 8/20/24.
//

#include <QTransform>
#include <qgraphicsscene.h>
#include <QGraphicsItem>
#include "Character.h"
#include "../Gravity.h"
#include "../../Scenes/BattleScene.h"

Character::Character(QGraphicsItem *parent) : Item(parent, ""), healthBar(new QGraphicsRectItem(this)) {
    //    ellipseItem = new QGraphicsEllipseItem(-5, -5, 10, 10, this); //创造一个椭圆，位置在(-5,-5)，大小为10*10，父节点为当前节点
    //    // Optionally, set some properties of the ellipse //可选，设置椭圆的一些属性
    //    ellipseItem->setBrush(Qt::green);          // Fill color //填充颜色
    //    ellipseItem->setZValue(1); // Draw on top of the pixmap //绘制在图片的上面 //设置Z值为1，Z值表示绘制顺序，数值越大越靠上
    healthBar->setRect(-50,-220,100,10); //设置生命值条的矩形
    healthBar->setBrush(QBrush(Qt::green)); //设置生命值条的颜色
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

bool Character::isThrowDown() const {
    return throwDown;
} //是否按下投掷键

void Character::setThrowDown(bool throwDown) {
    Character::throwDown = throwDown;
} //设置投掷键是否按下

bool Character::isChangeDown() const {
    return changeDown;
}

void Character::setChangeDown(bool changeDown) {
    Character::changeDown = changeDown;
}

bool Character::isChangeArrowDown() const {
    return changeArrowDown;
}

void Character::setChangeArrowDown(bool changeArrowDown) {
    Character::changeArrowDown = changeArrowDown;
}

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
            velocity.setX(qMax(velocity.x() - moveSpeed/2, 0.00000001));
        } else if (velocity.x() < 0) {
            velocity.setX(qMin(velocity.x() + moveSpeed/2, -0.00000001));
        }
    }
    if (isThrowDown()) {
        throwWeapon();
        archery();
    }
    if(isAttackDown()){
        //attack
        if(bow != nullptr){
            bow->attack();
        }
        if(melee != nullptr){
            melee->attack();
        }
    }

    if(isChangeDown()){
        changeWeapon();
    }
    if(isChangeArrowDown()){
        changeArrow();
    }
    //if (isJumpDown()&&isOnGround()) {
        // 跳跃键按下，只有在地面上时才允许跳跃
        //velocity.setY(-jumpSpeed); // 设置向上的速度
        //gravity.applyGravity(); //应用重力
    //}
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
Arrow* Character::pickupArrow(Arrow* newArrow) {
    // 假设你想保留原有的箭矢，这里直接添加新的箭矢到 arrows 中
    newArrow->setParentItem(this); // 设置新箭矢的父节点为当前角色
    newArrow->mountToParent(); //挂载新箭矢到父节点
    arrows.append(newArrow); // 将新箭矢添加到 arrows 向量中
    newArrow->setVisible(0);
    return nullptr;
    /*for (Arrow* newArrow : newArrows) {
        if (newArrow) {
            newArrow->setParentItem(this); // 设置新箭矢的父节点为当前角色
            arrows.append(newArrow); // 将新箭矢添加到 arrows 向量中
        }
    }

    // 如果需要返回原来的箭矢（例如为了丢弃或者处理），可以将旧箭矢返回
    // 这里假设你只想返回新添加的箭矢
    return newArrows;*/
}

QVector<Arrow*> Character::removeAllArrows() {
    QVector<Arrow*> removedArrows = arrows; // 保存当前的箭矢
    arrows.clear(); // 清空 arrows 向量
    return removedArrows; // 返回被移除的箭矢
}

void Character::removeArrow(Arrow* selected) {
    int removedIndex = arrows.indexOf(selected);
    if (removedIndex != -1) {
        arrows.removeAt(removedIndex);
        if (arrowNum >= arrows.size()) {
            arrowNum = 0;  // 如果当前索引超出范围，重置为 0
        }
    }
}

MeleeWeapon *Character::pickupMelee(MeleeWeapon *newMelee) {
    auto oldMelee = melee; //旧近战武器
    if (oldMelee != nullptr) { //如果旧近战武器不为空
        oldMelee->unmount(); //卸载旧近战武器
        oldMelee->setPos(newMelee->pos()); //设置旧近战武器位置为新近战武器位置
        oldMelee->setParentItem(parentItem());  //设置旧近战武器的父节点为当前节点
        oldMelee->setVisible(1);
    }
    newMelee->setParentItem(this); //设置新近战武器的父节点为当前节点
    newMelee->mountToParent(); //挂载新近战武器到父节点
    melee = newMelee; //设置新近战武器
    if(bow != nullptr && bow->isVisible()){
        melee->setVisible(0);
    }
    return oldMelee; //返回旧近战武器
} //拾取近战武器

Bow *Character::pickupBow(Bow *newBow){
    auto oldBow = bow;
    if(oldBow != nullptr){
        oldBow->unmount();
        oldBow->setPos(newBow->pos());
        oldBow->setParentItem(parentItem());
        oldBow->setVisible(1);
    }
    newBow->setParentItem(this);
    newBow->mountToParent();
    bow = newBow;
    if(melee != nullptr && melee->isVisible()){
        bow->setVisible(0);
    }
    return oldBow;
}

void Character::setHealth(qreal newHealth) {
    //qDebug() << "Setting health to:" << health;
    //healthBar->updateHealthBar(health);
    //qDebug() << "setHealth finished.";
    this->health = newHealth;
    updateHealthBar();
}


void Character::updateHealthBar(){
    int width = 100; //生命值条的宽度
    qreal healthBarWidth = (width * health) / 100; //生命值是0-100，计算生命值条的宽度
    healthBar->setRect(-50,-220,healthBarWidth,10); //设置生命值条的矩形
    if(health <= 20){
        healthBar->setBrush(QBrush(Qt::red)); //如果生命值较低，设置生命值条的颜色为红色
    }
}

QPointF Character::getDirection() const{
    QPointF direction;
    if (velocity.x() > 0) {
        direction = QPointF(1, 0);
    } else if (velocity.x() < 0) {
        direction = QPointF(-1, 0);}
    return direction;
}

void Character::throwWeapon() {
    if(melee == nullptr){
        return;
    }
    else if (melee != nullptr) {
        //qDebug() << "Throwing weapon, melee is not null";
        melee->unmount();
        melee->setParentItem(parentItem());
        melee->setPos(QPointF(pos().x()+100, pos().y()-50));
        melee->startThrown();
        melee->beThrown = true;
        //qDebug() << "Setting melee pos to:" << pos();
        QPointF direction = getDirection();
        QPointF speed = direction * 0.2;
        if(direction.x()>0){
            melee->setTransform(QTransform().scale(-1, 1), true); // 设置武器的水平翻转
        }
        melee->speed = speed;
        //qDebug() << "Setting melee speed to:" << speed;
        melee->downAcceleration = gravity.getGravity();
        //qDebug() << "Setting melee downAcceleration to:" << gravity.getGravity();
        melee = nullptr;
    }
}

void Character::archery() {
    if(bow == nullptr){
        return;
    }
    bool allNull = true;
    Arrow* selected = nullptr;
    for (Arrow* pointer : arrows) {
        if (pointer != nullptr) {
            allNull = false;
            break;
        }
    }
    if(allNull){
        return;
    }
    for(Arrow* arrow : arrows){
        if(arrow->isVisible() && arrow!=nullptr){
            selected = arrow;
            break;
        }
    }
    if(selected != nullptr){
        removeArrow(selected);
        selected->setRotation(45);
        //selected->setScale(0.3);
        selected->unmount();
        selected->setParentItem(parentItem());
        QPointF direction = getDirection();
        selected->setPos(QPointF(pos().x()+100, pos().y()-100));
        selected->startThrown();
        selected->beThrown = true;
        if(direction.x()>0){
            selected->setTransform(QTransform().scale(1, 1), true); // 设置武器的水平翻转
        }
        if(direction.x()<0){
            selected->setTransform(QTransform().scale(-1, 1), true); // 设置武器的水平翻转
        }
        selected->speed = direction * 0.5;
        selected->downAcceleration = gravity.getGravity();

        isArrowFired = true;  // 标记为已射箭
    }
}

void Character::changeWeapon() {
    // 提前返回，避免后续判断
    if (melee == nullptr || bow == nullptr) {
        return;
    }

    if (melee->isVisible()) {
        // 如果当前显示的是近战武器，切换到弓箭
        melee->setVisible(false);
        bow->setVisible(true);
        setChangeDown(false);
    } else if (bow->isVisible()) {
        // 如果当前显示的是弓箭，切换到近战武器
        bow->setVisible(false);
        melee->setVisible(true);
        if(!arrows.isEmpty()){
            arrows[arrowNum]->setVisible(false);
        }
        setChangeDown(false);
    }
}

void Character::changeArrow() {
    //static int arrowNum = 0;  // 静态变量，用于追踪当前选择的箭矢

    if (arrows.isEmpty()) {  // 如果箭矢列表为空，直接返回
        return;
    }
    qDebug() << "Arrow is not empty";
    // 隐藏当前箭矢
    if (arrows[arrowNum] != nullptr) {
        qDebug() << "ArrowNum is:" << arrowNum;
        arrows[arrowNum]->setVisible(false);
    }

    // 递增箭矢索引
    arrowNum++;
    qDebug() << "ArrowNum is increased to:" << arrowNum;
    if (arrowNum >= arrows.size()) {
        arrowNum = 0;  // 如果超过箭矢数量，重置为第一个箭矢
        qDebug() << "ArrowNum is reset to 0";
    }

    // 显示下一个箭矢
    if (arrows[arrowNum] != nullptr) {
        arrows[arrowNum]->setParentItem(this);
        arrows[arrowNum]->mountToParent();
        arrows[arrowNum]->setVisible(true);
    }
    qDebug() << "ArrowNum is now:" << arrowNum;
    qDebug() << "Finish change";

    // 重置射箭状态，防止切换箭矢后自动射出
    isArrowFired = false;
    setChangeArrowDown(false);
}

void Character::initEffects() {
    fireTimer = new QTimer(this);
    freezeTimer = new QTimer(this);
    thunderTimer = new QTimer(this);

    QGraphicsScene::connect(fireTimer, &QTimer::timeout, [this]() {
        this->updateHealth(1);  // 火焰每秒减少1点血量
    });

    QGraphicsScene::connect(freezeTimer, &QTimer::timeout, [this]() {
        this->beFrozen = false;
        this->frozenEffect->setVisible(false);  // 冻结结束，隐藏特效
        freezeTimer->stop();
    });

    QGraphicsScene::connect(thunderTimer, &QTimer::timeout, [this]() {
        this->updateHealth(1);  // 雷击每秒减少1点血量
    });
}

void Character::startFireEffect() {
    fireTimer->start(1000);  // 每秒触发一次火焰伤害
    QTimer::singleShot(5000, [this]() {  // 5秒后停止火焰效果
        this->onFire = false;
        this->fireEffect->setVisible(false);
        this->fireTimer->stop();
    });
}

void Character::startFrozenEffect() {
    freezeTimer->start(3000);  // 3秒后解除冰冻
    this->setMovable(false);   // 冰冻期间不能移动
    QTimer::singleShot(3000, [this]() {
        this->setMovable(true);  // 3秒后恢复移动能力
    });
}

void Character::startThunderEffect(BattleScene* scene) {
    thunderTimer->start(1000);  // 每秒触发一次雷击伤害
    qDebug() << "Thunder effect started";

    if (melee != nullptr && melee->material == 1) {  // 如果角色持有金属武器
        qDebug() << "Metal weapon detected, unmounting melee weapon";
        melee->unmount();
        melee->setParentItem(parentItem());
        melee->setPos(QPointF(pos().x() + 100, pos().y() - 50));
    }

    // 传播电击效果到铁砖块
    scene->spreadThunderEffect(this);

    QTimer::singleShot(5000, [this]() {  // 5秒后停止雷击效果
        this->beThundered = false;
        this->electrocutedEffect->setVisible(false);
        this->thunderTimer->stop();
    });
}




void Character::updateHealth(qreal damage) {
    health -= damage;
    if (health <= 0) {
        stopAllEffects();  // 人物死亡时停止所有特效
        // 处理人物死亡逻辑
    }
    updateHealthBar();  // 更新血条
}

void Character::stopAllEffects() {
    onFire = false;
    beFrozen = false;
    beThundered = false;

    fireEffect->setVisible(false);
    frozenEffect->setVisible(false);
    electrocutedEffect->setVisible(false);

    fireTimer->stop();
    freezeTimer->stop();
    thunderTimer->stop();
}

void Character::setMovable(bool movable) {
    if (movable) {
        if (!flags().testFlag(QGraphicsItem::ItemIsMovable)) {
            setFlag(QGraphicsItem::ItemIsMovable, true);
        }
    } else {
        if (flags().testFlag(QGraphicsItem::ItemIsMovable)) {
            setFlag(QGraphicsItem::ItemIsMovable, false);
        }
    }
}

