#include "formregister.h"
#include "ui_formregister.h"
#include <QKeyEvent>

FormRegister::FormRegister(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormRegister)
{
    ui->setupUi(this);
}

FormRegister::~FormRegister() {
    delete ui;
}

void FormRegister::keyPressEvent(QKeyEvent *event) {
    if((event->key() == Qt::Key_Enter) || (event->key() == Qt::Key_Return)) {
        if (ui->lineEdit == qApp->focusWidget()) {
            on_pushButtonSend_clicked();
        }
    } else {
        QWidget::keyPressEvent(event);
    }
}

void FormRegister::on_pushButtonSend_clicked() {
    emit s_sendData(ui->lineEdit->text());
}
