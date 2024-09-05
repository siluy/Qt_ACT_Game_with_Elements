#include "GameOverDialog.h"

GameOverDialog::GameOverDialog(const QString& winner, QWidget *parent) : QDialog(parent) {
    setWindowTitle("Game Over");

    QLabel *label = new QLabel(winner, this);
    label->setAlignment(Qt::AlignCenter);

    QPushButton *restartButton = new QPushButton("重新开始", this);
    QPushButton *quitButton = new QPushButton("退出游戏", this);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(label);
    layout->addWidget(restartButton);
    layout->addWidget(quitButton);

    connect(restartButton, &QPushButton::clicked, this, &GameOverDialog::restartGame);
    connect(quitButton, &QPushButton::clicked, this, &GameOverDialog::quitGame);
}

