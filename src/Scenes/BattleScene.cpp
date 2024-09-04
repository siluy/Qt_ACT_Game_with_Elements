//
// Created by gerw on 8/20/24.
//

#include <QDebug>
#include "BattleScene.h"

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
    spawnTimer = new QTimer(this);
    connect(spawnTimer, &QTimer::timeout, this, &BattleScene::spawnRandomItem);
    spawnTimer->start(2000); // 两秒触发一次
    const int blockWidth = 80; //方块宽度为80

    map = new Battlebackground(); //创建一个战场对象

    link = new Link(); //创建一个林克对象
    rival = new Rival(); //创建一个对手对象
    link->initEffects();
    rival->initEffects();
    Characters.push_back(link);
    Characters.push_back(rival);

    //spareArmor = new FlamebreakerArmor(); //创建一个火焰护甲对象
    flamebreakerArmor = new FlamebreakerArmor(); //创建一个火焰护甲对象
    //oldShirt = new OldShirt(); //创建一个旧衬衫对象
    //iceArmor = new IceArmor(); //创建一个冰护甲对象
    //thunderArmor = new ThunderArmor(); //创建一个雷护甲对象

    //ironShortSword = new IronShortSword(); //创建一个铁短剑对象
    //woodShortSword = new WoodShortSword(); //创建一个木短剑对象
    //ironLongSword = new IronLongSword(); //创建一个铁长剑对象
    //woodLongSword = new WoodLongSword(); //创建一个木长剑对象
    //ironStaff = new IronStaff(); //创建一个铁杖对象
    //woodStaff = new WoodStaff(); //创建一个木杖对象
    //fireSword = new FireSword(); //创建一个火焰剑对象
    //iceSword = new IceSword(); //创建一个冰剑对象
    thunderSword = new ThunderSword(); //创建一个雷剑对象

    //ironBow = new IronBow(); //创建一个铁弓对象
    //woodBow = new WoodBow(); //创建一个木弓对象
    //ironStrongBow = new IronStrongBow(); //创建一个铁强弓对象
    //woodStrongBow = new WoodStrongBow(); //创建一个木强弓对象
    //ironHandBow = new IronHandBow(); //创建一个铁手弓对象
    woodHandBow = new WoodHandBow(); //创建一个木手弓对象

    //normalArrow = new NormalArrow(); //创建一个普通箭对象
    //fireArrow = new FireArrow(); //创建一个火箭对象
    iceArrow = new IceArrow(); //创建一个冰箭对象
    //thunderArrow = new ThunderArrow(); //创建一个雷箭对象

    flameCap = new FlameCap(); //创建一个火帽对象
    //iceCap = new IceCap(); //创建一个冰帽对象
    //thunderCap = new ThunderCap(); //创建一个雷帽对象
    //capOfTheHero = new CapOfTheHero(); //创建一个英雄帽对象

    flameTrousers = new FlameTrousers(); //创建一个火裤对象
    //iceTrousers = new IceTrousers(); //创建一个冰裤对象
    //thunderTrousers = new ThunderTrousers(); //创建一个雷裤对象
    //wellWornTrousers = new WellWornTrousers(); //创建一个破旧裤对象

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

    //dropItems.push_back(ironShortSword); //添加铁短剑到掉落物品
    //dropItems.push_back(woodShortSword); //添加木短剑到掉落物品
    //dropItems.push_back(ironLongSword);
    //dropItems.push_back(woodLongSword); //添加木长剑到掉落物品
    //dropItems.push_back(ironStaff); //添加铁杖到掉落物品
    //dropItems.push_back(woodStaff); //添加木杖到掉落物品
    //dropItems.push_back(fireSword); //添加火剑到掉落物品
    //dropItems.push_back(iceSword); //添加冰剑到掉落物品
    dropItems.push_back(thunderSword); //添加雷剑到掉落物品

    //dropItems.push_back(ironBow); //添加铁弓到掉落物品
    //dropItems.push_back(woodBow);
    //dropItems.push_back(ironStrongBow); //添加铁强弓到掉落物品
    //dropItems.push_back(woodStrongBow); //添加木强弓到掉落物品
    //dropItems.push_back(ironHandBow); //添加铁手弓到掉落物品
    dropItems.push_back(woodHandBow); //添加木手弓到掉落物品

    //dropItems.push_back(spareArmor); //添加备用护甲到掉落物品
    dropItems.push_back(flamebreakerArmor);
    //dropItems.push_back(oldShirt); //添加旧衬衫到掉落物品
    //dropItems.push_back(iceArmor); //添加冰护甲到掉落物品
    //dropItems.push_back(thunderArmor); //添加雷护甲到掉落物品

    //dropItems.push_back(iceCap); //添加冰帽到掉落物品
    //dropItems.push_back(thunderCap); //添加雷帽到掉落物品
    dropItems.push_back(flameCap);
    //dropItems.push_back(capOfTheHero); //添加英雄帽到掉落物品

    //dropItems.push_back(normalArrow);
    //dropItems.push_back(fireArrow);
    dropItems.push_back(iceArrow);
    //dropItems.push_back(thunderArrow);

    //Melees.push_back(ironShortSword);
    //Melees.push_back(woodShortSword);
    //Armors.push_back(spareArmor);
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

    //addItem(spareArmor); //添加空护甲
    addItem(flamebreakerArmor); //添加火焰护甲
    //addItem(oldShirt); //添加旧衬衫
    //addItem(iceArmor); //添加冰护甲
    //addItem(thunderArmor); //添加雷护甲

    addItem(flameCap); //添加火帽
    //addItem(iceCap); //添加冰帽
    //addItem(thunderCap); //添加雷帽
    //addItem(capOfTheHero); //添加英雄帽

    addItem(flameTrousers); //添加火裤
    //addItem(iceTrousers); //添加冰裤
    //addItem(thunderTrousers); //添加雷裤
    //addItem(wellWornTrousers); //添加破旧裤

    //addItem(ironShortSword); //添加铁短剑
    //addItem(woodShortSword); //添加木短剑
    //addItem(ironLongSword); //添加铁长剑
    //addItem(woodLongSword); //添加木长剑
    //addItem(ironStaff); //添加铁杖
    //addItem(woodStaff); //添加木杖
    //addItem(fireSword); //添加火剑
    //addItem(iceSword); //添加冰剑
    addItem(thunderSword); //添加雷剑

    //addItem(ironBow); //添加铁弓
    //addItem(woodBow); //添加木弓
    //addItem(ironStrongBow); //添加铁强弓
    //addItem(woodStrongBow); //添加木强弓
    //addItem(ironHandBow); //添加铁手弓
    addItem(woodHandBow); //添加木手弓

    //addItem(normalArrow);
    //addItem(fireArrow);
    addItem(iceArrow);
    //addItem(thunderArrow);

    addItem(fireOfLink); //添加火焰
    addItem(fireOfRival); //添加火焰
    addItem(electrocutedOfLink); //添加电击
    addItem(electrocutedOfRival); //添加电击
    addItem(frozenOfLink); //添加冰冻
    addItem(frozenOfRival); //添加冰冻

    map->scaleToFitScene(this); //地图适应场景

    link->setPos(map->getSpawnPosForLink()); //设置角色位置为出生点
    rival->setPos(map->getSpawnPosForRival()); //设置对手位置为出生点

    //spareArmor->unmount(); //卸载空护甲
    //spareArmor->setPos(sceneRect().left() + (sceneRect().right() - sceneRect().left()) * 0.75, map->getFloorHeight()); //设置空护甲位置
    flamebreakerArmor->unmount(); //卸载火焰护甲
    flamebreakerArmor->setPos(sceneRect().left() + (sceneRect().right() - sceneRect().left()) * 0.75, map->getFloorHeight()); //设置火焰护甲位置
    //iceArmor->unmount(); //卸载冰护甲
    //iceArmor->setPos(sceneRect().left() + (sceneRect().right() - sceneRect().left()) * 0.75, map->getFloorHeight()); //设置冰护甲位置
    //thunderArmor->unmount(); //卸载雷护甲
    //thunderArmor->setPos(sceneRect().left() + (sceneRect().right() - sceneRect().left()) * 0.75, map->getFloorHeight()); //设置雷护甲位置
    //oldShirt->unmount(); //卸载旧衬衫
    //oldShirt->setPos(sceneRect().left() + (sceneRect().right() - sceneRect().left()) * 0.75, map->getFloorHeight()); //设置旧衬衫位置

    //ironShortSword->unmount(); //卸载铁短剑
    //woodShortSword->unmount(); //卸载木短剑
    //ironLongSword->unmount(); //卸载铁长剑
    //woodLongSword->unmount(); //卸载木长剑
    //ironStaff->unmount(); //卸载铁杖
    //woodStaff->unmount(); //卸载木杖
    //fireSword->unmount(); //卸载火剑
    //iceSword->unmount(); //卸载冰剑
    thunderSword->unmount(); //卸载雷剑
    //ironShortSword->setPos(sceneRect().left() + (sceneRect().right() - sceneRect().left()) * 0.25, map->getFloorHeight()); //设置铁短剑位置
    //woodShortSword->setPos(sceneRect().left() + (sceneRect().right() - sceneRect().left()) * 0.25, map->getFloorHeight()); //设置木短剑位置
    //ironLongSword->setPos(sceneRect().left() + (sceneRect().right() - sceneRect().left()) * 0.25, map->getFloorHeight()); //设置铁长剑位置
    //woodLongSword->setPos(sceneRect().left() + (sceneRect().right() - sceneRect().left()) * 0.25, map->getFloorHeight()); //设置木长剑位置
    //ironStaff->setPos(sceneRect().left() + (sceneRect().right() - sceneRect().left()) * 0.25, map->getFloorHeight()); //设置铁杖位置
    //woodStaff->setPos(sceneRect().left() + (sceneRect().right() - sceneRect().left()) * 0.25, map->getFloorHeight()); //设置木杖位置
    //fireSword->setPos(sceneRect().left() + (sceneRect().right() - sceneRect().left()) * 0.25, map->getFloorHeight()); //设置火剑位置
    //iceSword->setPos(sceneRect().left() + (sceneRect().right() - sceneRect().left()) * 0.25, map->getFloorHeight()); //设置冰剑位置
    thunderSword->setPos(sceneRect().left() + (sceneRect().right() - sceneRect().left()) * 0.25, map->getFloorHeight()); //设置雷剑位置

    //ironBow->unmount(); //卸载铁弓
    //ironBow->setScale(0.2); //设置缩放比
    //ironBow->setPos(sceneRect().left() + (sceneRect().right() - sceneRect().left()) * 0.5, map->getFloorHeight()*0.5); //设置铁弓位置
    //woodBow->unmount(); //卸载木弓
    //woodBow->setScale(0.2); //设置缩放比
    //woodBow->setPos(sceneRect().left() + (sceneRect().right() - sceneRect().left()) * 0.5, map->getFloorHeight()*0.5); //设置木弓位置
    //ironStrongBow->unmount(); //卸载铁强弓
    //ironStrongBow->setScale(0.2); //设置缩放比
    //ironStrongBow->setPos(sceneRect().left() + (sceneRect().right() - sceneRect().left()) * 0.5, map->getFloorHeight()*0.5); //设置铁强弓位置
    //woodStrongBow->unmount(); //卸载木强弓
    //woodStrongBow->setScale(0.2); //设置缩放比
    //woodStrongBow->setPos(sceneRect().left() + (sceneRect().right() - sceneRect().left()) * 0.5, map->getFloorHeight()*0.5); //设置木强弓位置
    //ironHandBow->unmount(); //卸载铁手弓
    //ironHandBow->setScale(0.2); //设置缩放比
    //ironHandBow->setPos(sceneRect().left() + (sceneRect().right() - sceneRect().left()) * 0.5, map->getFloorHeight()*0.5); //设置铁手弓位置
    woodHandBow->unmount(); //卸载木手弓
    woodHandBow->setScale(0.2); //设置缩放比
    woodHandBow->setPos(sceneRect().left() + (sceneRect().right() - sceneRect().left()) * 0.5, map->getFloorHeight()*0.5); //设置木手弓位置

    //normalArrow->unmount();
    //normalArrow->setScale(0.2);
    //normalArrow->setPos(sceneRect().left() + (sceneRect().right() - sceneRect().left()) * 0.35, map->getFloorHeight()*0.5);
    //fireArrow->unmount();
    //fireArrow->setScale(0.2);
    //fireArrow->setPos(sceneRect().left() + (sceneRect().right() - sceneRect().left()) * 0.35, map->getFloorHeight()*0.5);
    iceArrow->unmount();
    iceArrow->setScale(0.2);
    iceArrow->setPos(sceneRect().left() + (sceneRect().right() - sceneRect().left()) * 0.35, map->getFloorHeight()*0.5);
    //thunderArrow->unmount();
    //thunderArrow->setScale(0.2);
    //thunderArrow->setPos(sceneRect().left() + (sceneRect().right() - sceneRect().left()) * 0.35, map->getFloorHeight()*0.5);

    flameCap->unmount(); //卸载火帽
    flameCap->setPos(sceneRect().left() + (sceneRect().right() - sceneRect().left()) * 0.15, map->getFloorHeight()); //设置火帽位置
    //iceCap->unmount(); //卸载冰帽
    //iceCap->setPos(sceneRect().left() + (sceneRect().right() - sceneRect().left()) * 0.15, map->getFloorHeight()); //设置冰帽位置
    //thunderCap->unmount(); //卸载雷帽
   // thunderCap->setPos(sceneRect().left() + (sceneRect().right() - sceneRect().left()) * 0.15, map->getFloorHeight()); //设置雷帽位置
    //capOfTheHero->unmount(); //卸载英雄帽
    //capOfTheHero->setPos(sceneRect().left() + (sceneRect().right() - sceneRect().left()) * 0.15, map->getFloorHeight()); //设置英雄帽位置

    flameTrousers->unmount(); //卸载火裤
    flameTrousers->setPos(sceneRect().left() + (sceneRect().right() - sceneRect().left()) * 0.45, map->getFloorHeight()); //设置火裤位置
    //iceTrousers->unmount(); //卸载冰裤
    //iceTrousers->setPos(sceneRect().left() + (sceneRect().right() - sceneRect().left()) * 0.45, map->getFloorHeight()); //设置冰裤位置
    //thunderTrousers->unmount(); //卸载雷裤
    //thunderTrousers->setPos(sceneRect().left() + (sceneRect().right() - sceneRect().left()) * 0.45, map->getFloorHeight()); //设置雷裤位置
    //wellWornTrousers->unmount(); //卸载破旧裤
    //wellWornTrousers->setPos(sceneRect().left() + (sceneRect().right() - sceneRect().left()) * 0.45, map->getFloorHeight()); //设置破旧裤位置

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
        if(character->onFire){
            spreadFire(character->pos().y()/80, character->pos().x()/80);
            if(character->melee != nullptr && character->melee->isVisible()){
                qDebug() << "Character have a melee.";
                if(character->melee->material == 2){
                    qDebug() << "Character have a wood melee.";
                    character->melee->unmount();
                    delete character->melee;
                    character->melee = nullptr;
                }
            }
            if(character->bow != nullptr && character->bow->isVisible()){
                qDebug() << "Character have a bow.";
                if(character->bow->material == 2){
                    qDebug() << "Character have a wood bow.";
                    character->bow->unmount();
                    delete character->bow;
                    character->bow = nullptr;
                }
            }
        }
        // 检查是否在燃烧的石头方块上
        if(character->onFire==false){
            int blockX = static_cast<int>(character->pos().x()) / 80;
            int blockY = static_cast<int>(character->pos().y()) / 80;
            int absence = 30;
            int n_blockY = static_cast<int>(character->pos().y() + absence) / 80;
            int n_blockX = static_cast<int>(character->pos().x() + absence) / 80;
            if (blockGrid[blockY][blockX] != nullptr && (blocks[blockY][blockX] == 4 || blocks[n_blockY][blockX] == 4
                                                         || blocks[n_blockY][n_blockX] == 4 || blocks[blockY][n_blockX] == 4)
                && blockGrid[blockY][blockX]->fire->isVisible()) {
                character->onFire = true;
                character->fireEffect->setVisible(1);
                character->startFireEffect();
            }
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
                igniteBlockIfLanded(melee);
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
                igniteBlockIfLanded(arrow);
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
            // 仅对石头砖块触发火焰扩散
            //{
                //int i = victim->y() / 80;
                //int j = victim->x() / 80;
                //if (blocks[i][j] == 4) {
                    //spreadFire(i, j);
                //}
            //}
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
        qDebug() << "Victim health: " << victim->health;

        // 根据 element 属性应用效果
        int element = arrow->element;
        if (auto fireArrow = dynamic_cast<FireArrow*>(arrow)) {
            element = fireArrow->element;

        }else if(auto iceArrow = dynamic_cast<IceArrow*>(arrow)){
            element = iceArrow->element;
        }else if(auto thunderArrow = dynamic_cast<ThunderArrow*>(arrow)){
            element = thunderArrow->element;
        }

        switch (element) {
        case 1:  // 火属性
            victim->onFire = true;
            victim->fireEffect->setVisible(true);
            victim->startFireEffect();
            //{
            // 仅对石头砖块触发火焰扩散
                //int i = victim->y() / 80;
                //int j = victim->x() / 80;
                //if (blocks[i][j] == 4) {
                    //spreadFire(i, j);
                //}
            //}
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
    if (auto cap = dynamic_cast<HeadEquipment *>(mountable)) {
        return character->pickupHeadEquipment(cap); //拾取帽子
    }
    if (auto trousers = dynamic_cast<LegEquipment *>(mountable)) {
        return character->pickupLegEquipment(trousers); //拾取裤子
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

void BattleScene::spreadFire(int i, int j) {
    if (i < 0 || i >= 9 || j < 0 || j >= 16 || blocks[i][j] != 4) {
        return;  // 确保只处理石头砖块
    }
    qDebug() << "Spreading fire to block (" << i << ", " << j << ")";
    auto stoneBlock = dynamic_cast<Stoneblock*>(blockGrid[i][j]);
    if (stoneBlock == nullptr || stoneBlock->fire == nullptr || stoneBlock->fire->isVisible()) {
        return;  // 如果砖块已经燃烧或不是石头，退出
    }

    // 设置火焰可见
    stoneBlock->fire->setVisible(true);

    // 延时扩散火焰到相邻的石头砖块
    QTimer::singleShot(1000, [this, i, j]() {
        //spreadFire(i + 1, j);
        //spreadFire(i - 1, j);
        spreadFire(i, j + 1);
        spreadFire(i, j - 1);
    });

    // 延时删除燃尽的砖块
    QTimer::singleShot(5000, [this, i, j]() {
        if (blockGrid[i][j] != nullptr) {  // 确保砖块仍然存在
            delete blockGrid[i][j];
            blockGrid[i][j] = nullptr;
            Item::blocks[i][j] = 0;
        }
    });
}


void BattleScene::igniteBlockIfLanded(Item* item) {
    int blockX = static_cast<int>(item->pos().x()) / 80;
    int blockY = static_cast<int>(item->pos().y()) / 80;
    if (blockGrid[blockY][blockX] != nullptr && blocks[blockY][blockX] == 4) {
        //blockGrid[blockY][blockX]->fire->setVisible(true);
        spreadFire(blockY, blockX);
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

void BattleScene::spawnItem(const QString &itemType) {
    Item *newItem = nullptr;

    if (itemType == "WoodShortSword") {
        newItem = new WoodShortSword();
    } else if (itemType == "IronShortSword") {
        newItem = new IronShortSword();
    } else if (itemType == "IronLongSword"){
        newItem = new IronLongSword();
    } else if (itemType == "WoodLongSword") {
        newItem = new WoodLongSword();
    } else if (itemType == "IronStaff") {
        newItem = new IronStaff();
    } else if (itemType == "WoodStaff") {
        newItem = new WoodStaff();
    } else if (itemType == "IronBow") {
        newItem = new IronBow();
    } else if (itemType == "NormalArrow") {
        newItem = new NormalArrow();
    } else if (itemType == "FireArrow") {
        newItem = new FireArrow();
    } else if (itemType == "IceArrow") {
        newItem = new IceArrow();
    } else if (itemType == "ThunderArrow") {
        newItem = new ThunderArrow();
    } else if (itemType == "FlameArmor") {
        newItem = new FlamebreakerArmor();
    } else if (itemType == "OldShirt") {
        newItem = new OldShirt();
    } else if (itemType == "FireSword") {
        newItem = new FireSword();
    } else if (itemType == "IceArmor") {
        newItem = new IceArmor();
    } else if (itemType == "ThunderArmor") {
        newItem = new ThunderArmor();
    } else if (itemType == "IceSword") {
        newItem = new IceSword();
    } else if (itemType == "ThunderSword") {
        newItem = new ThunderSword();
    } else if (itemType == "IronBow") {
        newItem = new IronBow();
    } else if (itemType == "WoodBow") {
        newItem = new WoodBow();
    } else if (itemType == "IronStrongBow") {
        newItem = new IronStrongBow();
    } else if (itemType == "WoodStrongBow") {
        newItem = new WoodStrongBow();
    } else if (itemType == "IronHandBow") {
        newItem = new IronHandBow();
    } else if (itemType == "WoodHandBow") {
        newItem = new WoodHandBow();
    } else if (itemType == "CapOfTheHero") {
        newItem = new CapOfTheHero();
    } else if (itemType == "FlameCap") {
        newItem = new FlameCap();
    } else if (itemType == "IceCap") {
        newItem = new IceCap();
    } else if (itemType == "ThunderCap") {
        newItem = new ThunderCap();
    } else if (itemType == "FlameTrousers") {
        newItem = new FlameTrousers();
    } else if (itemType == "IceTrousers") {
        newItem = new IceTrousers();
    } else if (itemType == "ThunderTrousers") {
        newItem = new ThunderTrousers();
    } else if (itemType == "WellWornTrousers") {
        newItem = new WellWornTrousers();
    } else {
        qDebug() << "Unknown cheat code:" << itemType;
    }
    auto newMountable = dynamic_cast<Mountable *>(newItem);
    if (newMountable) {
        newItem->setPos(100, 100);  // Example position
        addItem(newItem);
        dropItems.append(newItem);
        newMountable->unmount();
    } else {
        qDebug() << "Unknown cheat code:" << itemType;
    }
}

void BattleScene::spawnRandomItem() {
    int randomItemIndex = QRandomGenerator::global()->bounded(0, 31); // 生成0到11之间的随机数
    int randomXPosition = QRandomGenerator::global()->bounded(0, 1280); // 随机生成X位置

    Item *newItem = nullptr;

    switch (randomItemIndex) {
    case 0:
        newItem = new WoodShortSword();
        break;
    case 1:
        newItem = new WoodLongSword();
        break;
    case 2:
        newItem = new WoodStaff();
        break;
    case 3:
        newItem = new ThunderSword();
        break;
    case 4:
        newItem = new FireSword();
        break;
    case 5:
        newItem = new IceSword();
        break;
    case 6:
        newItem = new IronStaff();
        break;
    case 7:
        newItem = new IronLongSword();
        break;
    case 8:
        newItem = new IronShortSword();
        break;
    case 9:
        newItem = new IronBow();
        break;
    case 10:
        newItem = new IronStrongBow();
        break;
    case 11:
        newItem = new IronHandBow();
        break;
    case 12:
        newItem = new WoodBow();
        break;
    case 13:
        newItem = new WoodStrongBow();
        break;
    case 14:
        newItem = new WoodHandBow();
        break;
    case 15:
        newItem = new NormalArrow();
        break;
    case 16:
        newItem = new FireArrow();
        break;
    case 17:
        newItem = new IceArrow();
        break;
    case 18:
        newItem = new ThunderArrow();
        break;
    case 19:
        newItem = new FlamebreakerArmor();
        break;
    case 20:
        newItem = new IceArmor();
        break;
    case 21:
        newItem = new ThunderArmor();
        break;
    case 22:
        newItem = new OldShirt();
        break;
    case 23:
        newItem = new CapOfTheHero();
        break;
    case 24:
        newItem = new FlameCap();
        break;
    case 25:
        newItem = new IceCap();
        break;
    case 26:
        newItem = new ThunderCap();
        break;
    case 27:
        newItem = new FlameTrousers();
        break;
    case 28:
        newItem = new IceTrousers();
        break;
    case 29:
        newItem = new ThunderTrousers();
        break;
    case 30:
        newItem = new WellWornTrousers();
        break;
    default:
        //newItem = new Item(); // 默认物品，防止出错
        break;
    }

    if (newItem) {
        newItem->setPos(randomXPosition, 0); // 设置物品初始位置
        addItem(newItem); // 添加到场景
        dropItems.append(newItem);

        //applyGravity(newItem);

        // 在3秒后移除物品，如果未被拾取
        QTimer::singleShot(3000, [this, newItem]() {
            removeItemAfterDelay(newItem);
        });
    }
}

void BattleScene::removeItemAfterDelay(Item* item) {
    if (dropItems.contains(item)) {
        dropItems.removeOne(item);
        removeItem(item);
        delete item;
    }
}
