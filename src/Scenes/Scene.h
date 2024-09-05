//
// Created by gerw on 8/20/24.
//

#ifndef QT_PROGRAMMING_2024_SCENE_H
#define QT_PROGRAMMING_2024_SCENE_H

#include <QGraphicsScene>
#include <QTimer>

class Scene : public QGraphicsScene {
Q_OBJECT

public:
    explicit Scene(QObject *parent); //构造函数，传入父节点

    void startLoop(); //开始循环

    virtual void processInput(); //处理输入

    virtual void processMovement(); //处理移动

    virtual void processPicking();  //处理拾取

    //virtual void processThrow(Item* item); //处理投掷

protected slots:

    virtual void update(); //更新

protected:
    qint64 deltaTime{}; //时间差

private:
    QTimer *timer; //计时器
    qint64 lastTime{-1}; //上次时间，初始化为-1，表示第一帧
};


#endif //QT_PROGRAMMING_2024_SCENE_H
