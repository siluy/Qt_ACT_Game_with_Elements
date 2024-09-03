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

    map = new Battlebackground(); //创建一个战场对象

    link = new Link(); //创建一个林克对象
    rival = new Rival(); //创建一个对手对象
    link->initEffects();
    rival->initEffects();
    Characters.push_back(link);
    Characters.push_back(rival);

    spareArmor = new FlamebreakerArmor(); //创建一个火焰护甲对象

    ironShortSword = new IronShortSword(); //创建一个铁短剑对象
    woodShortSword = new WoodShortSword(); //创建一个木短剑对象
    fireSword = new FireSword(); //创建一个火焰剑对象
    iceSword = new IceSword(); //创建一个冰剑对象
    thunderSword = new ThunderSword(); //创建一个雷剑对象

    ironBow = new IronBow(); //创建一个铁弓对象

    normalArrow = new NormalArrow(); //创建一个普通箭对象
    fireArrow = new FireArrow(); //创建一个火箭对象

    fireOfLink = new Fire();
    frozenOfLink = new Frozen();
    electrocutedOfLink = new Electrocuted();

    fireOfRival = new Fire();
    frozenOfRival = new Frozen();
    electrocutedOfRival = new Electrocuted();

    link->fireEffect = fireOfLink;
    link->frozenEffect = frozenOfLink;
    link->electrocutedEffect = electrocutedOfLink;

    rival->fireEffect = fireOfRival;
    rival->frozenEffect = frozenOfRival;
    rival->electrocutedEffect = electrocutedOfRival;

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

    addItem(map); //添加地图
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 16; j++) {
            switch (blocks[i][j]) {
            case 1:
                blockGrid[i][j] = new Soilblock();
                break;
            case 2:
                blockGrid[i][j] = new Grassblock();
                break;
            case 3:
                blockGrid[i][j] = new Ironblock();
                blockGrid[i][j]->electrocuted = new Electrocuted();
                blockGrid[i][j]->electrocuted->setScale(1.5);
                blockGrid[i][j]->electrocuted->setParentItem(blockGrid[i][j]);
                blockGrid[i][j]->electrocuted->setPos(20 - blockGrid[i][j]->electrocuted->boundingRect().width() / 2,
                                                      20 - blockGrid[i][j]->electrocuted->boundingRect().height() / 2);
                blockGrid[i][j]->electrocuted->setVisible(0);
                //blockGrid[i][j]->electrocuted->setZValue(1);
                break;
            case 4:
                blockGrid[i][j] = new Stoneblock();
                blockGrid[i][j]->fire = new Fire();
                blockGrid[i][j]->fire->setScale(0.6);
                blockGrid[i][j]->fire->setParentItem(blockGrid[i][j]);
                blockGrid[i][j]->fire->setPos(80 - blockGrid[i][j]->fire->boundingRect().width() / 2,
                                              90 - blockGrid[i][j]->fire->boundingRect().height() / 2);
                blockGrid[i][j]->fire->setVisible(0);
                //blockGrid[i][j]->fire->setZValue(1);
                break;
            default:
                blockGrid[i][j] = nullptr;
                continue;
            }

            // 在将效果添加到场景之前设置方块的位置
            blockGrid[i][j]->setPos(j * blockWidth, i * blockWidth);

            //将方块添加到场景
            addItem(blockGrid[i][j]);

            //现在添加效果（只添加一次，作为开关情况的一部分）
            if (blockGrid[i][j]->electrocuted != nullptr) {
                addItem(blockGrid[i][j]->electrocuted);
            }

            if (blockGrid[i][j]->fire != nullptr) {
                addItem(blockGrid[i][j]->fire);
            }
        }
    }



    addItem(link); //添加角色
    addItem(rival); //添加对手

    addItem(spareArmor); //添加空护甲


    addItem(ironShortSword); //添加铁短剑
    addItem(woodShortSword); //添加木短剑
    addItem(fireSword); //添加火剑
    addItem(iceSword); //添加冰剑
    addItem(thunderSword); //添加雷剑

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

    ironShortSword->unmount(); //卸载铁短剑
    woodShortSword->unmount(); //卸载木短剑
    fireSword->unmount(); //卸载火剑
    iceSword->unmount(); //卸载冰剑
    thunderSword->unmount(); //卸载雷剑
    ironShortSword->setPos(sceneRect().left() + (sceneRect().right() - sceneRect().left()) * 0.85, map->getFloorHeight()); //设置铁短剑位置
    woodShortSword->setPos(sceneRect().left() + (sceneRect().right() - sceneRect().left()) * 0.25, map->getFloorHeight()); //设置木短剑位置
    fireSword->setPos(sceneRect().left() + (sceneRect().right() - sceneRect().left()) * 0.65, map->getFloorHeight()); //设置火剑位置
    iceSword->setPos(sceneRect().left() + (sceneRect().right() - sceneRect().left()) * 0.45, map->getFloorHeight()); //设置冰剑位置
    thunderSword->setPos(sceneRect().left() + (sceneRect().right() - sceneRect().left()) * 0.05, map->getFloorHeight()); //设置雷剑位置

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
        if (link != nullptr && link->beFrozen == false) {
            link->setLeftDown(true);
        }
        break;
    case Qt::Key_D:
        if (link != nullptr && link->beFrozen == false) {
            link->setRightDown(true);
        }
        break;
    case Qt::Key_S:
        if (link != nullptr && link->beFrozen == false) {
            link->setPickDown(true);
        }
        break;
    case Qt::Key_W:
        if (link != nullptr && link->beFrozen == false) {
            link->setJumpDown(true);
            link->downSpeed = -1;
            link->downAcceleration = gravity.getGravity();
            //character->downAcceleration = 0.03;
        }
        break;
    case Qt::Key_J:
        if (link != nullptr && link->beFrozen == false) {
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
        if (link != nullptr && link->beFrozen == false) {
            link->setThrowDown(true);
        }
        break;
    case Qt::Key_L:
        if (link != nullptr && link->beFrozen == false){
            link->setChangeDown(true);
        }
        break;
    case Qt::Key_K:
        if (link!=nullptr && link->beFrozen == false){
            link->setChangeArrowDown(true);
            link->changeArrow();
        }
        break;
    case Qt::Key_Left:
        if (rival != nullptr && rival->beFrozen == false) {
            rival->setLeftDown(true);
        }
        break;
    case Qt::Key_Right:
        if (rival != nullptr && rival->beFrozen == false) {
            rival->setRightDown(true);
        }
        break;
    case Qt::Key_Down:
        if (rival != nullptr && rival->beFrozen == false) {
            rival->setPickDown(true);
        }
        break;
    case Qt::Key_Up:
        if (rival != nullptr && rival->beFrozen == false) {
            rival->setJumpDown(true);
            rival->downSpeed = -1;
            rival->downAcceleration = gravity.getGravity();
            //character->downAcceleration = 0.03;
        }
        break;
    case Qt::Key_Shift:
        if (rival != nullptr && rival->beFrozen == false) {
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
            else if(link->bow != nullptr && link->bow->isVisible()){
                link->setThrowDown(false);
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
    for(Character* character: Characters){
        if(character->beThundered){
            spreadThunderEffect(character);
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
    if (auto throwable = dynamic_cast<Throwable*>(item)) {
        // 基于不同类型的投掷物进行处理
        if (auto melee = dynamic_cast<MeleeWeapon*>(throwable)) {
            processMeleeThrow(melee);
        } else if (auto arrow = dynamic_cast<Arrow*>(throwable)) {
            processArrowThrow(arrow);
        }
    }
}

void BattleScene::processMeleeThrow(MeleeWeapon* melee) {
    if (melee != nullptr && melee->isVisible()) {
        QRectF throwAttackRect = QRectF(melee->pos().x(), melee->pos().y(), -100, 200);
        if (melee->speed.x() < 0) {
            throwAttackRect = QRectF(melee->pos().x(), melee->pos().y(), 100, 200);
            qDebug() << "Throwing weapon left.";
        }

        if (melee->beThrown) {
            if (throwAttackRect.contains(rival->pos())) {
                applyMeleeEffect(melee, rival);
                delete melee;
                melee = nullptr;
            }
            if (throwAttackRect.contains(link->pos())) {
                applyMeleeEffect(melee, link);
                delete melee;
                melee = nullptr;
            }
        }
        if(melee){
            if (melee->isOnGround(melee) && melee->beThrown) {
                delete melee;
                melee = nullptr;
            }
        }
    }
}

void BattleScene::processArrowThrow(Arrow* arrow) {
    if (arrow != nullptr && arrow->isVisible()) {
        QRectF throwAttackRect = QRectF(arrow->pos().x() + 50, arrow->pos().y(), -100, 200);
        if (arrow->speed.x() < 0) {
            throwAttackRect = QRectF(arrow->pos().x() - 100, arrow->pos().y(), -100, 200);
            qDebug() << "Throwing arrow left.";
        }

        if (arrow->beThrown) {
            if (throwAttackRect.contains(rival->pos())) {
                applyArrowEffect(arrow, rival);
                delete arrow;
                arrow = nullptr;
            }
            if (throwAttackRect.contains(link->pos())) {
                applyArrowEffect(arrow, link);
                delete arrow;
                arrow = nullptr;
            }
        }
        if(arrow){
            if (arrow->isOnGround(arrow) && arrow->beThrown) {
                delete arrow;
                arrow = nullptr;
            }
        }
    }
}

void BattleScene::applyMeleeEffect(MeleeWeapon* melee, Character* victim) {
    if (melee) {
        int damage = melee->damage;
        if (victim->beFrozen) {
            damage *= 2;  // 冻结状态下双倍伤害
            victim->beFrozen = false;
            victim->frozenEffect->setVisible(false);
            victim->setMovable(true);  // 恢复移动能力
        }
        victim->setHealth(victim->health - damage);
        qDebug() << "Victim health: " << victim->health;

        // 根据 element 属性应用效果
        int element = melee->element;
        if (auto fireWeapon = dynamic_cast<FireSword*>(melee)) {
            element = fireWeapon->element;
        } else if (auto iceWeapon = dynamic_cast<IceSword*>(melee)) {
            element = iceWeapon->element;
        } else if (auto thunderWeapon = dynamic_cast<ThunderSword*>(melee)) {
            element = thunderWeapon->element;
        }

        switch (element) {
        case 1:  // 火属性
            victim->onFire = true;
            victim->fireEffect->setVisible(true);
            victim->startFireEffect();
            break;
        case 2:  // 冰属性
            victim->beFrozen = true;
            victim->frozenEffect->setVisible(true);
            victim->startFrozenEffect();
            break;
        case 3:  // 雷属性
            victim->beThundered = true;
            victim->electrocutedEffect->setVisible(true);
            victim->startThunderEffect(this);
            break;
        default:
            break;
        }
    }
}


void BattleScene::applyArrowEffect(Arrow* arrow, Character* victim) {
    if (arrow) {
        int damage = arrow->damage;
        if (victim->beFrozen) {
            damage *= 2;  // 冻结状态下双倍伤害
            victim->beFrozen = false;
            victim->frozenEffect->setVisible(false);
            victim->setMovable(true);  // 恢复移动能力
        }
        victim->setHealth(victim->health - damage);

        // 根据 element 属性应用效果
        int element = arrow->element;
        if (auto fireArrow = dynamic_cast<FireArrow*>(arrow)) {
            element = fireArrow->element;
        }

        switch (element) {
        case 1:  // 火属性
            victim->onFire = true;
            victim->fireEffect->setVisible(true);
            victim->startFireEffect();
            break;
        case 2:  // 冰属性
            victim->beFrozen = true;
            victim->frozenEffect->setVisible(true);
            victim->startFrozenEffect();
            break;
        case 3:  // 雷属性
            victim->beThundered = true;
            victim->electrocutedEffect->setVisible(true);
            victim->startThunderEffect(this);
            break;
        default:
            break;
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
            tempItem = dynamic_cast<Item*>(pickupMountable(rival, mountable)); //拾取可挂载物品
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
    qDebug() << "Attacking!";
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
                qDebug() << "Attacked!";
                return true; // 被攻击者在攻击者的前方弧内
            }
        }
    }
    return false;
}

void BattleScene::attackDone(Character *attacker, Character *victim) {
    if (attacker != nullptr && victim != nullptr) {
        if (attacker->melee != nullptr) {
            int element = attacker->melee->element;  // 获取 element 属性

            // 检查并获取派生类的 element 值
            if (auto fireWeapon = dynamic_cast<FireSword*>(attacker->melee)) {
                element = fireWeapon->element;
            } else if (auto iceWeapon = dynamic_cast<IceSword*>(attacker->melee)) {
                element = iceWeapon->element;
            } else if (auto thunderWeapon = dynamic_cast<ThunderSword*>(attacker->melee)) {
                element = thunderWeapon->element;
            }

            int damage = attacker->melee->damage;
            if (victim->beFrozen) {
                damage *= 2;  // 冻结状态下双倍伤害
                victim->beFrozen = false;
                victim->frozenEffect->setVisible(false);
                victim->setMovable(true);  // 恢复移动能力
                qDebug() << "Victim unfrozen.";
            }

            if (element == 0) {
                if (attackTrue(attacker, victim)) {
                    victim->health -= damage;
                }
            } else if (element == 1) {
                if (attackTrue(attacker, victim)) {
                    victim->health -= damage;
                    victim->onFire = true;
                    victim->fireEffect->setVisible(true);
                    victim->startFireEffect();
                }
            } else if (element == 2) {
                if (attackTrue(attacker, victim)) {
                    victim->health -= damage;
                    victim->beFrozen = true;
                    victim->frozenEffect->setVisible(true);
                    victim->startFrozenEffect();
                }
            } else if (element == 3) {
                if (attackTrue(attacker, victim)) {
                    victim->health -= damage;
                    victim->beThundered = true;
                    victim->electrocutedEffect->setVisible(true);
                    victim->startThunderEffect(this);
                }
            }
        }
    }
}

void BattleScene::spreadThunderEffect(Character* character) {
    QPointF pos = character->pos();
    int x = pos.x() / 80;
    int y = pos.y() / 80;

    // 检查角色是否站在铁砖块上
    if (blocks[y][x] == 3 && blockGrid[y][x]->electrocuted != nullptr) {
        // 设置当前铁砖块的雷电效果为可见
        blockGrid[y][x]->electrocuted->setVisible(true);

        // 向左和向右传播雷电效果
        propagateThunderEffect(x, y, -1); // 向左传播
        propagateThunderEffect(x, y, 1);  // 向右传播
    }
}

void BattleScene::propagateThunderEffect(int startX, int y, int direction) {
    int x = startX + direction;
    while (x >= 0 && x < 16) {
        // 检查是否为铁砖块
        if (blocks[y][x] == 3 && blockGrid[y][x]->electrocuted != nullptr) {
            blockGrid[y][x]->electrocuted->setVisible(true);
        } else {
            break;  // 不是铁砖块，停止传播
        }
        x += direction;
    }
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

