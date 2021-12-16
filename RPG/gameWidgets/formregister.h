#ifndef FORMREGISTER_H
#define FORMREGISTER_H

#include <QWidget>

namespace Ui {
class FormRegister;
}

class FormRegister : public QWidget {
    Q_OBJECT

public:
    explicit FormRegister(QWidget *parent = nullptr);
    ~FormRegister();

signals:
    void s_sendData(const QString &nickName);

private slots:
    void on_pushButtonSend_clicked();
    
private:
    Ui::FormRegister *ui;
    void keyPressEvent(QKeyEvent *event);
};

#endif // FORMREGISTER_H
