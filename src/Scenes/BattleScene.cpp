//
// Created by gerw on 8/20/24.
//

#include <QDebug>
#include "BattleScene.h"
#include "../Items/Characters/Link.h"
#include "../Items/Maps/battlebackground.h"
#include "../Items/Armors/FlamebreakerArmor.h"
//#include "../Items/Gravity.h"
#include "../Items/Blocks/Blocks.h"
#include "../Items/Blocks/Grassblock.h"
#include "../Items/Blocks/Ironblock.h"
#include "../Items/Blocks/Soilblock.h"
#include "../Items/Blocks/Stoneblock.h"

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
    character = new Link(); //创建一个林克对象
    spareArmor = new FlamebreakerArmor(); //创建一个火焰护甲对象

    addItem(map); //添加地图
    for(int i=0; i<9; i++) {
        for(int j=0; j<16; j++) {
            switch (blocks[i][j]) {
            case 1:
                blockGrid[i][j] = new Soilblock();
                break;
            case 2:
                blockGrid[i][j] = new Grassblock();
                break;
            case 3:
                blockGrid[i][j] = new Ironblock();
                break;
            case 4:
                blockGrid[i][j] = new Stoneblock();
                break;
            default:
                blockGrid[i][j] = nullptr;
                continue;
            }
            blockGrid[i][j]->setPos(j * blockWidth, i * blockWidth);
            addItem(blockGrid[i][j]); // 将方块添加到场景中
        }
    }
    /*for(int i=0;i<9;i++){
        for(int j=0;j<16;j++){
            if(blocks[i][j]==1){
                soilBlock = new Soilblock();
                soilBlock->setPos(j*blockWidth,i*blockWidth);
                addItem(soilBlock);
            }
            else if(blocks[i][j]==4){
                stoneBlock = new Stoneblock();
                stoneBlock->setPos(j*blockWidth,i*blockWidth);
                addItem(stoneBlock);
            }
            else if(blocks[i][j]==3){
                ironBlock = new Ironblock();
                ironBlock->setPos(j*blockWidth,i*blockWidth);
                addItem(ironBlock);
            }
            else if(blocks[i][j]==2){
                grassBlock = new Grassblock();
                grassBlock->setPos(j*blockWidth,i*blockWidth);
                addItem(grassBlock);
            }
        }
    }性能不好*/
    addItem(character); //添加角色
    addItem(spareArmor); //添加空护甲
    map->scaleToFitScene(this); //地图适应场景
    character->setPos(map->getSpawnPos()); //设置角色位置为出生点
    spareArmor->unmount(); //卸载空护甲
    spareArmor->setPos(sceneRect().left() + (sceneRect().right() - sceneRect().left()) * 0.75, map->getFloorHeight()); //设置空护甲位置
} //构造函数，传入父节点

void BattleScene::processInput() {
    Scene::processInput(); //调用基类的处理输入函数
    if (character != nullptr) {
        character->processInput(); //处理角色输入
    }
} //处理输入

void BattleScene::keyPressEvent(QKeyEvent *event) {
    switch (event->key()) {
    case Qt::Key_A:
        if (character != nullptr) {
            character->setLeftDown(true);
        }
        break;
    case Qt::Key_D:
        if (character != nullptr) {
            character->setRightDown(true);
        }
        break;
    case Qt::Key_J:
        if (character != nullptr) {
            character->setPickDown(true);
        }
        break;
    case Qt::Key_W:
        if (character != nullptr) {
            character->setJumpDown(true);
        }
        break;
    default:
        Scene::keyPressEvent(event);
    }
} //按键按下事件

void BattleScene::keyReleaseEvent(QKeyEvent *event) {
    switch (event->key()) {
    case Qt::Key_A:
        if (character != nullptr) {
            character->setLeftDown(false);
        }
        break;
    case Qt::Key_D:
        if (character != nullptr) {
            character->setRightDown(false);
        }
        break;
    case Qt::Key_J:
        if (character != nullptr) {
            character->setPickDown(false);
        }
        break;
    case Qt::Key_W:
        if (character != nullptr) {
            character->setJumpDown(false);
        }
        break;
    default:
        Scene::keyReleaseEvent(event);
    }
} //按键释放事件

void BattleScene::update() {
    Scene::update();
} //更新

void BattleScene::processMovement() {
    Scene::processMovement();
    if (character != nullptr) {
        character->setPos(character->pos() + character->getVelocity() * (double) deltaTime); //设置角色位置为当前位置加上速度乘以时间差
    }
} //处理移动

void BattleScene::processPicking() {
    Scene::processPicking();
    if (character->isPicking()) {
        auto mountable = findNearestUnmountedMountable(character->pos(), 100.); //查找最近的未挂载的可挂载物品，距离阈值为100
        if (mountable != nullptr) {
            spareArmor = dynamic_cast<Armor *>(pickupMountable(character, mountable)); //拾取可挂载物品
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
    return nullptr;
} //拾取可挂载物品

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
