#ifndef COMMANDDIALOG_H
#define COMMANDDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

class CommandDialog : public QDialog {
    Q_OBJECT

public:
    explicit CommandDialog(QWidget *parent = nullptr);

signals:
    void commandEntered(const QString &command);

private slots:
    void onConfirmButtonClicked();

private:
    QLineEdit *commandLineEdit;
    QPushButton *confirmButton;
    QPushButton *cancelButton;
};

#endif // COMMANDDIALOG_H
