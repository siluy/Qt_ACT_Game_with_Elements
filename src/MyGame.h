//
// Created by gerw on 8/20/24.
//

#ifndef QT_PROGRAMMING_2024_MYGAME_H
#define QT_PROGRAMMING_2024_MYGAME_H

#include <QGraphicsView>
#include <QMainWindow>
#include "Scenes/Scene.h"

class MyGame : public QMainWindow {
Q_OBJECT

public:
    explicit MyGame(QWidget *parent = nullptr); //构造函数，传入父节点

private:
    Scene *battleScene;  //战斗场景
    QGraphicsView *view; //视图
}; //MyGame类继承自QMainWindow类，表示我的游戏


#endif //QT_PROGRAMMING_2024_MYGAME_H
