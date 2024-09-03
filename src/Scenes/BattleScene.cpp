//
// Created by gerw on 8/20/24.
//

#include <QDebug>
#include "BattleScene.h"
#include "../Items/Characters/Link.h"
#include "../Items/Characters/Rival.h"
#include "../Items/Maps/battlebackground.h"
#include "../Items/Armors/FlamebreakerArmor.h"
#include "../Items/Gravity.h"
#include "../Items/Blocks/Blocks.h"
#include "../Items/Blocks/Grassblock.h"
#include "../Items/Blocks/Ironblock.h"
#include "../Items/Blocks/Soilblock.h"
#include "../Items/Blocks/Stoneblock.h"
#include <cmath>

BattleScene::BattleScene(QObject *parent) : Scene(parent) {
    // This is useful if you want the scene to have the exact same dimensions as the view
    setSceneRect(0, 0, 1280, 720); //设置场景矩形区域为(0,0,1280,720)
    const int blockWidth = 80; //方块宽度为80
    /*BattleScene::blocks[9][16] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
                         {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                         {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}}; //方块数组初始化*/
    //grassBlock = new Grassblock(); //创建一个草方块对象
    //ironBlock = new Ironblock(); //创建一个铁方块对象
    //soilBlock = new Soilblock(); //创建一个土方块对象
    //stoneBlock = new Stoneblock(); //创建一个石方块对象
    map = new Battlebackground(); //创建一个战场对象
    //map = std::make_shared<Battlebackground>(); // 创建一个战场对象，并赋值给 map
    link = new Link(); //创建一个林克对象
    //link = std::make_shared<Link>(); // 创建一个林克对象，并赋值给 link
    rival = new Rival(); //创建一个对手对象
    //rival = std::make_shared<Rival>(); // 创建一个对手对象，并赋值给 rival
    spareArmor = new FlamebreakerArmor(); //创建一个火焰护甲对象  删除
    //spareArmor = std::make_shared<FlamebreakerArmor>(); // 创建一个火焰护甲对象，并赋值给 spareArmor
    //spareMelee = new WoodShortSword(); //创建一个铁短剑对象
    ironShortSword = new IronShortSword(); //创建一个铁短剑对象
    woodShortSword = new WoodShortSword(); //创建一个木短剑对象
    ironBow = new IronBow(); //创建一个铁弓对象
    normalArrow = new NormalArrow(); //创建一个普通箭对象
    fireArrow = new FireArrow(); //创建一个火箭对象
    fireOfLink = new Fire(); //创建一个火焰对象
    fireOfRival = new Fire(); //创建一个火焰对象
    electrocutedOfLink = new Electrocuted(); //创建一个电击对象
    electrocutedOfRival = new Electrocuted(); //创建一个电击对象
    frozenOfLink = new Frozen(); //创建一个冰冻对象
    frozenOfRival = new Frozen(); //创建一个冰冻对象
    dropItems.push_back(ironShortSword); //添加铁短剑到掉落物品
    dropItems.push_back(woodShortSword); //添加木短剑到掉落物品
    dropItems.push_back(spareArmor); //添加备用护甲到掉落物品
    dropItems.push_back(ironBow);
    dropItems.push_back(normalArrow);
    dropItems.push_back(fireArrow);
    Melees.push_back(ironShortSword);
    Melees.push_back(woodShortSword);
    Armors.push_back(spareArmor);
    //dropItems.push_back(spareMelee); //添加备用近战武器到掉落物品
    //spareMelee = std::make_shared<IronShortSword>(); // 创建一个铁短剑对象，并赋值给 spareMelee
    //healthBarForLink = new HealthBar(link, 100, 10, -50, -220); //创建一个角色血条对象
    //healthBarForLink = std::make_shared<HealthBar>(link, link->health, 10, -50, -220); // 创建一个角色血条对象，并赋值给 healthBarForLink
    //healthBarForRival = new HealthBar(rival, 100, 10, -50, -220); //创建一个对手血条对象
    //healthBarForRival = std::make_shared<HealthBar>(rival, rival->health, 10, -50, -220); // 创建一个对手血条对象，并赋值给 healthBarForRival

    addItem(map); //添加地图
    for(int i=0; i<9; i++) {
        for(int j=0; j<16; j++) {
            switch (blocks[i][j]) {
            case 1:
                blockGrid[i][j] = new Soilblock();
                //blockGrid[i][j] = std::make_shared<Soilblock>();
                break;
            case 2:
                blockGrid[i][j] = new Grassblock();
                //blockGrid[i][j] = std::make_shared<Grassblock>();
                break;
            case 3:
                blockGrid[i][j] = new Ironblock();
                //blockGrid[i][j] = std::make_shared<Ironblock>();
                break;
            case 4:
                blockGrid[i][j] = new Stoneblock();
                //blockGrid[i][j] = std::make_shared<Stoneblock>();
                break;
            default:
                blockGrid[i][j] = nullptr;
                continue;
            }
            blockGrid[i][j]->setPos(j * blockWidth, i * blockWidth);
            addItem(blockGrid[i][j]); // 将方块添加到场景中
        }
    }
    addItem(link); //添加角色
    addItem(rival); //添加对手
    addItem(spareArmor); //添加空护甲
    //addItem(spareMelee); //添加空近战武器
    addItem(ironShortSword); //添加铁短剑
    addItem(woodShortSword); //添加木短剑
    addItem(ironBow); //添加铁弓
    addItem(normalArrow);
    addItem(fireArrow);
    addItem(fireOfLink); //添加火焰
    addItem(fireOfRival); //添加火焰
    addItem(electrocutedOfLink); //添加电击
    addItem(electrocutedOfRival); //添加电击
    addItem(frozenOfLink); //添加冰冻
    addItem(frozenOfRival); //添加冰冻
    map->scaleToFitScene(this); //地图适应场景
    link->setPos(map->getSpawnPosForLink()); //设置角色位置为出生点
    rival->setPos(map->getSpawnPosForRival()); //设置对手位置为出生点
    spareArmor->unmount(); //卸载空护甲
    spareArmor->setPos(sceneRect().left() + (sceneRect().right() - sceneRect().left()) * 0.75, map->getFloorHeight()); //设置空护甲位置
    //spareMelee->unmount(); //卸载空近战武器
    ironShortSword->unmount(); //卸载铁短剑
    woodShortSword->unmount(); //卸载木短剑
    ironShortSword->setPos(sceneRect().left() + (sceneRect().right() - sceneRect().left()) * 0.85, map->getFloorHeight()); //设置铁短剑位置
    woodShortSword->setPos(sceneRect().left() + (sceneRect().right() - sceneRect().left()) * 0.25, map->getFloorHeight()); //设置木短剑位置
    ironBow->unmount(); //卸载铁弓
    ironBow->setScale(0.2); //设置缩放比
    ironBow->setPos(sceneRect().left() + (sceneRect().right() - sceneRect().left()) * 0.5, map->getFloorHeight()*0.5); //设置铁弓位置
    normalArrow->unmount();
    normalArrow->setScale(0.2);
    normalArrow->setPos(sceneRect().left() + (sceneRect().right() - sceneRect().left()) * 0.35, map->getFloorHeight()*0.5);
    fireArrow->unmount();
    fireArrow->setScale(0.2);
    fireArrow->setPos(sceneRect().left() + (sceneRect().right() - sceneRect().left()) * 0.65, map->getFloorHeight()*0.5);
    fireOfLink->unmount(); //卸载火焰
    fireOfLink->setParentItem(link); //设置火焰父节点为角色
    fireOfLink->mountToParent(); //装载火焰
    fireOfRival->unmount(); //卸载火焰
    fireOfRival->setParentItem(rival); //设置火焰父节点为对手
    fireOfRival->mountToParent(); //装载火焰
    electrocutedOfLink->unmount(); //卸载电击
    electrocutedOfLink->setParentItem(link); //设置电击父节点为角色
    electrocutedOfLink->mountToParent(); //装载电击
    electrocutedOfRival->unmount();
    electrocutedOfRival->setParentItem(rival); //设置电击父节点为对手
    electrocutedOfRival->mountToParent(); //装载电击
    frozenOfLink->unmount(); //卸载冰冻
    frozenOfLink->setParentItem(link); //设置冰冻父节点为角色
    frozenOfLink->mountToParent(); //装载冰冻
    frozenOfRival->unmount(); //卸载冰冻
    frozenOfRival->setParentItem(rival); //设置冰冻父节点为对手
    frozenOfRival->mountToParent(); //装载冰冻

} //构造函数，传入父节点

void BattleScene::processInput() {
    Scene::processInput(); //调用基类的处理输入函数
    if (link != nullptr) {
        link->processInput(); //处理角色输入
    }
    if(rival != nullptr){
        rival->processInput(); //处理对手输入
    }
} //处理输入

void BattleScene::keyPressEvent(QKeyEvent *event) {
    if(event->isAutoRepeat()){
        return;
    }
    switch (event->key()) {
    case Qt::Key_A:
        if (link != nullptr) {
            link->setLeftDown(true);
        }
        break;
    case Qt::Key_D:
        if (link != nullptr) {
            link->setRightDown(true);
        }
        break;
    case Qt::Key_S:
        if (link != nullptr) {
            link->setPickDown(true);
        }
        break;
    case Qt::Key_W:
        if (link != nullptr) {
            link->setJumpDown(true);
            link->downSpeed = -1;
            link->downAcceleration = gravity.getGravity();
            //character->downAcceleration = 0.03;
        }
        break;
    case Qt::Key_J:
        if (link != nullptr) {
            if (link->melee != nullptr && link->melee->isVisible()) {
                link->setAttackDown(true);
                attackDone(link, rival);
                rival->updateHealthBar();
            }
            else if(link->bow != nullptr && link->bow->isVisible()){
                link->setThrowDown(true);
            }
        }
        break;
    case Qt::Key_Q:
        if (link != nullptr) {
            link->setThrowDown(true);
        }
        break;
    case Qt::Key_L:
        if (link!=nullptr){
            link->setChangeDown(true);
        }
        break;
    case Qt::Key_K:
        if (link!=nullptr){
            link->setChangeArrowDown(true);
            link->changeArrow();
        }
        break;
    case Qt::Key_Left:
        if (rival != nullptr) {
            rival->setLeftDown(true);
        }
        break;
    case Qt::Key_Right:
        if (rival != nullptr) {
            rival->setRightDown(true);
        }
        break;
    case Qt::Key_Down:
        if (rival != nullptr) {
            rival->setPickDown(true);
        }
        break;
    case Qt::Key_Up:
        if (rival != nullptr) {
            rival->setJumpDown(true);
            rival->downSpeed = -1;
            rival->downAcceleration = gravity.getGravity();
            //character->downAcceleration = 0.03;
        }
        break;
    case Qt::Key_Shift:
        if (rival != nullptr) {
            if (rival->melee != nullptr) {
            rival->setAttackDown(true);
            attackDone(rival, link);
            link->updateHealthBar();
            }
        }
        break;
    default:
        Scene::keyPressEvent(event);
    }
} //按键按下事件

void BattleScene::keyReleaseEvent(QKeyEvent *event) {
    if(event->isAutoRepeat()){
        return;
    }
    switch (event->key()) {
    case Qt::Key_A:
        if (link != nullptr) {
            link->setLeftDown(false);
        }
        break;
    case Qt::Key_D:
        if (link != nullptr) {
            link->setRightDown(false);
        }
        break;
    case Qt::Key_S:
        if (link != nullptr) {
            link->setPickDown(false);
        }
        break;
    case Qt::Key_W:
        if (link != nullptr) {
            link->setJumpDown(false);
        }
        break;
    case::Qt::Key_J:
        if (link != nullptr) {
            link->setAttackDown(false);
            if (link->melee != nullptr) {
                if (!link->isAttackDown()) {
                    link->melee->attackStoped();
                }
            }
        }
        break;
    case Qt::Key_Q:
        if (link != nullptr) {
            link->setThrowDown(false);
        }
        break;
    case Qt::Key_L:
        if (link != nullptr) {
            link->setChangeDown(false);
        }
        break;
    case Qt::Key_K:
        if (link != nullptr) {
            link->setChangeArrowDown(false);
        }
        break;
    case Qt::Key_Left:
        if (rival != nullptr) {
            rival->setLeftDown(false);
        }
        break;
    case Qt::Key_Right:
        if (rival != nullptr) {
            rival->setRightDown(false);
        }
        break;
    case Qt::Key_Down:
        if (rival != nullptr) {
            rival->setPickDown(false);
        }
        break;
    case Qt::Key_Up:
        if (rival != nullptr) {
            rival->setJumpDown(false);
        }
        break;
    case Qt::Key_Shift:
        if (rival != nullptr) {
            rival->setAttackDown(false);
            if(rival->melee != nullptr){
                rival->melee->attackStoped();
            }
        }
        break;
    default:
        Scene::keyReleaseEvent(event);
    }
} //按键释放事件

void BattleScene::update() {
    if(link != nullptr){
        if(link->downSpeed >= 0){
        link->setAcceleration(); //设置加速度
        }
        if(!link->isOnGround()){
            link->downAcceleration = gravity.getGravity();
        }
    //if(character->downSpeed >= 0){
        //gravity.setVelocity(character, deltaTime); //设置速度
        //gravity.setPos(character, deltaTime); //设置位置
    //}
        gravity.setVelocity(link, deltaTime); //设置速度
        gravity.setPos(link, deltaTime); //设置位置
    }
    if(rival != nullptr){
        if(rival->downSpeed >= 0){
            rival->setAcceleration(); //设置加速度
        }
        if(!rival->isOnGround()){
            rival->downAcceleration = gravity.getGravity();
        }
        gravity.setVelocity(rival, deltaTime); //设置速度
        gravity.setPos(rival, deltaTime); //设置位置
    }
    for(Item* item: dropItems){
        if(!item->isOnGround(item))
        gravity.setVelocity(item, deltaTime); //设置速度
        gravity.setPos(item, deltaTime); //设置位置
        if(item->isOnGround(item)){
            item->downSpeed = 0;
            item->downAcceleration = 0;
        }
    }
    Scene::update();
    for(QGraphicsItem *Qitem: items()){
        if(auto item = dynamic_cast<Item *>(Qitem)){
                processThrow(item);
        }
    }
    map->update();
} //更新

void BattleScene::processMovement() {
    Scene::processMovement();
    if (link != nullptr) {
        link->setPos(link->pos() + link->getVelocity() * (double) deltaTime); //设置角色位置为当前位置加上速度乘以时间差
    }
    if (rival != nullptr) {
        rival->setPos(rival->pos() + rival->getVelocity() * (double) deltaTime); //设置对手位置为当前位置加上速度乘以时间差
    }
    for (QGraphicsItem *Qitem: items()) {
        if(auto item = dynamic_cast<Item *>(Qitem))
        {
            if(item->isOnGround(item)){
                item->downSpeed = 0;
                item->downAcceleration = 0;
            }
            else if (auto throwable = dynamic_cast<Throwable *>(item))
            { //如果是可投掷物品
                if (throwable->isThrown()) {
                    auto melee = dynamic_cast<MeleeWeapon *>(throwable);
                    if(melee!=nullptr){
                        melee->setPos(item->pos() + melee->getSpeed() * (double) deltaTime);
                        gravity.setVelocity(melee, deltaTime);
                        auto y = melee->downSpeed * deltaTime + 0.5 * 0.005 * deltaTime * deltaTime;
                        melee->setPos(melee->pos() + QPointF(0, y));
                    }
                    auto arrow = dynamic_cast<Arrow *>(throwable);
                    if(arrow!=nullptr){
                        arrow->setPos(item->pos() + arrow->getSpeed() * (double) deltaTime);
                        gravity.setVelocity(arrow, deltaTime);
                        auto y = arrow->downSpeed * deltaTime + 0.5 * 0.005 * deltaTime * deltaTime;
                        arrow->setPos(arrow->pos() + QPointF(0, y));
                    }
                }
            }
        }
    }
    /*for(QGraphicsItem *Qitem: items()){
        if(auto item = dynamic_cast<Item *>(Qitem)){
            if(item->isOnGround(item) && item->beThrown){
                delete item;
                item = nullptr;
                //link->melee = nullptr;
            }
        }

    }*/
    /*for (Throwable* throwable : itemsToDelete) {
        if(throwable != nullptr){
            qDebug() << "Deleting throwable item.";
            itemsToDelete.removeAll(throwable); // 从待删除列表中移除投掷物
            Melees.removeOne(throwable);
            qDebug() << "Deleting throwable item.";
            delete throwable;
            qDebug() << "Deleted throwable item.";
            //throwable = nullptr;
        }
    }*/
} //处理移动

void BattleScene::processThrow(Item* item){
    auto throwable = dynamic_cast<Throwable *>(item);
    auto melee = dynamic_cast<MeleeWeapon *>(throwable);
    auto arrow = dynamic_cast<Arrow *>(throwable);
    if(melee != nullptr && melee->isVisible() && ((arrow == nullptr) || (arrow != nullptr && !(arrow->isVisible())))){
        QRectF throwAttackRect = QRectF(item->pos().x(), item->pos().y(), -100, 200);
        //qDebug() << "Throwing weapon.";
        if(melee->speed.x() < 0){
            throwAttackRect = QRectF(item->pos().x(), item->pos().y(), 100, 200);
            qDebug() << "Throwing weapon left.";
        }
        if(item->beThrown){
            if(throwAttackRect.contains(rival->pos())){
                qDebug() << "Throw attack hit rival.";
                rival->setHealth(rival->health - 10);
                delete item;
                item = nullptr;
            }
            if(throwAttackRect.contains(link->pos())){
                qDebug() << "Throw attack hit link.";
                link->setHealth(link->health - 10);
                delete item;
                item = nullptr;
            }
        }
        if(item->isOnGround(item) && item->beThrown){
            delete item;
            item = nullptr;
        }
    }
    else if(arrow != nullptr && arrow->isVisible() && ((melee == nullptr) || (melee != nullptr && !(melee->isVisible())))){
        QRectF throwAttackRect = QRectF(item->pos().x()+50, item->pos().y(), -100, 200);
        //qDebug() << "Throwing weapon.";
        if(arrow->speed.x() < 0){
            throwAttackRect = QRectF(item->pos().x()-100, item->pos().y(), -100, 200);
            qDebug() << "Throwing weapon left.";
        }
        if(item->beThrown){
            if(throwAttackRect.contains(rival->pos())){
                qDebug() << "Throw attack hit rival.";
                rival->setHealth(rival->health - 10);
                delete item;
                item = nullptr;
            }
            if(throwAttackRect.contains(link->pos())){
                qDebug() << "Throw attack hit link.";
                link->setHealth(link->health - 10);
                delete item;
                item = nullptr;
            }
        }
        if(item->isOnGround(item) && item->beThrown){
            delete item;
            item = nullptr;
        }
    }
}

void BattleScene::processPicking() {
    Scene::processPicking();
    //qDebug() << "Processing picking.";
    if (link->isPicking()) {
        auto mountable = findNearestUnmountedMountable(link->pos(), 100.); //查找最近的未挂载的可挂载物品，距离阈值为100
        if (mountable != nullptr) {
            Item* tempItem;
            tempItem = dynamic_cast<Item*>(pickupMountable(link, mountable)); //拾取可挂载物品
            if(tempItem != nullptr){
                dropItems.push_back(tempItem);
            }
            //spareArmor = dynamic_cast<Armor *>(pickupMountable(link, mountable)); //拾取可挂载护甲
            //spareMelee = dynamic_cast<MeleeWeapon *>(pickupMountable(link, mountable)); //拾取可挂载近战武器
            //spareBow = dynamic_cast<Bow *>(pickupMountable(link, mountable)); //拾取可挂载弓
            //if(link->bow != nullptr){
                //spareArrow = dynamic_cast<Arrow *>(pickupMountable(link, mountable)); //拾取可挂载箭
            //}
        }
    }
    if (rival->isPicking()) {
        auto mountable = findNearestUnmountedMountable(rival->pos(), 100.); //查找最近的未挂载的可挂载物品，距禒阈值为100
        if (mountable != nullptr) {
            Item* tempItem;
            tempItem = dynamic_cast<Item*>(pickupMountable(link, mountable)); //拾取可挂载物品
            if(tempItem != nullptr){
                dropItems.push_back(tempItem);
            }
            //spareArmor = dynamic_cast<Armor *>(pickupMountable(rival, mountable)); //拾取可挂载护甲
            //spareMelee = dynamic_cast<MeleeWeapon *>(pickupMountable(rival, mountable)); //拾取可挂载近战武器
            //spareBow = dynamic_cast<Bow *>(pickupMountable(rival, mountable)); //拾取可挂载弓
            //if(rival->bow != nullptr){
            //spareArrow = dynamic_cast<Arrow *>(pickupMountable(rival, mountable)); //拾取可挂载箭
            //}
        }
    }
} //处理拾取

Mountable *BattleScene::findNearestUnmountedMountable(const QPointF &pos, qreal distance_threshold) {
    Mountable *nearest = nullptr; //最近的可挂载物品
    qreal minDistance = distance_threshold; //最小距离为距离阈值

    for (QGraphicsItem *item: items()) {
        if (auto mountable = dynamic_cast<Mountable *>(item)) { //如果是可挂载物品
            if (!mountable->isMounted()) {
                qreal distance = QLineF(pos, item->pos()).length(); //计算距离
                if (distance < minDistance) {
                    minDistance = distance; //更新最小距离
                    nearest = mountable; //更新最近的可挂载物品
                }
            }
        }
    }

    return nearest;
} //查找最近的未挂载的可挂载物品

Mountable *BattleScene::pickupMountable(Character *character, Mountable *mountable) {
    // Limitation: currently only supports armor //限制：目前仅支持护甲
    if (auto armor = dynamic_cast<Armor *>(mountable)) {
        return character->pickupArmor(armor); //拾取护甲
    }
    if (auto melee = dynamic_cast<MeleeWeapon *>(mountable)) {
        return character->pickupMelee(melee); //拾取近战武器
    }
    if (auto bow = dynamic_cast<Bow *>(mountable)) {
        return character->pickupBow(bow); //拾取弓
    }
    if (auto arrow = dynamic_cast<Arrow *>(mountable) ) {
        if(character->bow != nullptr)
        {
            return character->pickupArrow(arrow);
        }        //拾取箭
    }
        return nullptr;
} //拾取可挂载物品

bool BattleScene::attackTrue(Character *attacker, Character *victim){
    if(attacker->melee == nullptr){
        return false;
    } else {
        QPointF pos1 = attacker->pos();
        QPointF pos2 = victim->pos();
        qreal attackRange = attacker->melee->attackRange;

        // 计算攻击者与被攻击者的距离
        qreal distance = QLineF(pos1, pos2).length();

        if(distance < attackRange){
            // 计算攻击者朝向的向量
            QPointF directionVector = attacker->getDirection();
            QPointF vectorToVictim = pos2 - pos1;

            // 归一化向量
            vectorToVictim /= QLineF(pos1, pos2).length();

            // 计算两个向量的夹角的余弦值
            qreal dotProduct = QPointF::dotProduct(directionVector, vectorToVictim);

            // 获取两个向量夹角的余弦值对应的弧度
            qreal angleRadians = std::acos(dotProduct);

            // 定义攻击弧的角度
            const qreal attackArcAngleRadians = M_PI / 3; // 60度对应的弧度

            // 判断夹角是否在定义的攻击弧内
            if(angleRadians <= attackArcAngleRadians){
                return true; // 被攻击者在攻击者的前方弧内
            }
        }
    }
    return false;
}

/*bool BattleScene::attackTrue(Character *attacker, Character *victim){
    if(attacker->melee == nullptr){
        return false;
    }else{
        QPointF pos1 = attacker->pos();
        QPointF pos2 = victim->pos();
        qreal minDistance = attacker->melee->attackRange;

        qreal distance = QLineF(pos1, pos2).length();
        if(distance < minDistance){
            return true;
        }
    }
    return false;
}*/

void BattleScene::attackDone(Character *attacker, Character *victim) {
    if (attacker != nullptr && victim != nullptr) {
        //qDebug() << "Attacker and victim are valid.";
        if (attacker->melee != nullptr) {
            //qDebug() << "Attacker has a melee weapon.";
            if (attackTrue(attacker, victim)) {
                //qDebug() << "Attack is successful.";
                victim->health -= attacker->melee->damage;
                //qDebug() << "Victim health is now:" << victim->health;
                //victim->setHealth(victim->health);
            }
        } //else {
            //qDebug() << "Attacker has no melee weapon.";
        //}
    } //else {
        //if (attacker == nullptr) qDebug() << "Attacker is null.";
        //if (victim == nullptr) qDebug() << "Victim is null.";
    //}
}


const int BattleScene::blocks[9][16] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}}; //方块数组初始化
