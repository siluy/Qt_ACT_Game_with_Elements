//
// Created by gerw on 8/20/24.
//

#include <QDateTime>
#include "Scene.h"

Scene::Scene(QObject *parent) : QGraphicsScene(parent), timer(new QTimer(this)) {
    connect(timer, &QTimer::timeout, this, &Scene::update);
}

void Scene::update() {
    auto currentTime = QDateTime::currentDateTime().toMSecsSinceEpoch(); //得到当前时间
    if (lastTime == -1) { // first frame //如果是第一帧，时间差为0
        deltaTime = 0;
    } else {
        deltaTime = currentTime - lastTime; //否则，时间差为当前时间减去上次时间
    }
    lastTime = currentTime; //更新上次时间为当前时间


    processInput();
    processMovement();
    processPicking();
}

void Scene::startLoop() {
    timer->start(1000 / 90); // 90FPS //开始计时器，每秒90帧
}

void Scene::processInput() {

}

void Scene::processMovement() {

}

void Scene::processPicking() {

}

void Scene::processThrow(Item* item) {

}

