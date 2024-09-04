//
// Created by gerw on 8/20/24.
//
#include "MyGame.h"
#include "Scenes/BattleScene.h"
#include <QDebug>

MyGame::MyGame(QWidget *parent) : QMainWindow(parent) {
    battleScene = new BattleScene(this);
    view = new QGraphicsView(this);
    view->setScene(battleScene);

    // Set the view's window size to 1280x720
    view->setFixedSize((int) view->scene()->width(), (int) view->scene()->height());
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setCentralWidget(view);
    setFixedSize(view->sizeHint());

    battleScene->startLoop();

    // Initialize CommandDialog
    commandDialog = new CommandDialog(this);

    // Bind the "/" key to show the command dialog
    cheatShortcut = new QShortcut(QKeySequence("/"), this);
    connect(cheatShortcut, &QShortcut::activated, this, &MyGame::showCommandDialog);

    // Connect the dialog's commandEntered signal to the processCommand slot
    connect(commandDialog, &CommandDialog::commandEntered, this, &MyGame::processCommand);
}

void MyGame::showCommandDialog() {
    commandDialog->show();
}

void MyGame::processCommand(const QString &command) {
    qDebug() << "Cheat code entered:" << command;
    battleScene->spawnItem(command);  // Assuming spawnItem is a method in BattleScene
}
