//
// Created by gerw on 8/20/24.
//

#ifndef MYGAME_H
#define MYGAME_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QShortcut>
#include "Scenes/BattleScene.h"
#include "Scenes/Scene.h"
#include "Scenes/CommandDialog.h"

class MyGame : public QMainWindow {
    Q_OBJECT

public:
    explicit MyGame(QWidget *parent = nullptr);

private slots:
    void showCommandDialog();
    void processCommand(const QString &command);

private:
    QGraphicsView *view;
    BattleScene *battleScene;
    QShortcut *cheatShortcut;
    CommandDialog *commandDialog;
};

#endif // MYGAME_H
