#include "CommandDialog.h"

    CommandDialog::CommandDialog(QWidget *parent) : QDialog(parent) {
    setWindowTitle("Enter Cheat Code");

    commandLineEdit = new QLineEdit(this);
    confirmButton = new QPushButton("Confirm", this);
    cancelButton = new QPushButton("Cancel", this);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(commandLineEdit);

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(confirmButton);
    buttonLayout->addWidget(cancelButton);
    mainLayout->addLayout(buttonLayout);

    setLayout(mainLayout);

    connect(confirmButton, &QPushButton::clicked, this, &CommandDialog::onConfirmButtonClicked);
    connect(cancelButton, &QPushButton::clicked, this, &QDialog::reject);
}

void CommandDialog::onConfirmButtonClicked() {
    emit commandEntered(commandLineEdit->text());
    close();
}
