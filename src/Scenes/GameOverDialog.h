#ifndef GAMEOVERDIALOG_H
#define GAMEOVERDIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>

class GameOverDialog : public QDialog {
    Q_OBJECT

public:
    explicit GameOverDialog(const QString& winner, QWidget *parent = nullptr);

signals:
    void restartGame();
    void quitGame();
};

#endif // GAMEOVERDIALOG_H
