#ifndef FORMCHAT_H
#define FORMCHAT_H

#include <QWidget>
#include "class/structs.h"
#include "class/settings.h"

namespace Ui {
class FormChat;
}

class FormChat : public QWidget {
    Q_OBJECT

public:
    explicit FormChat(QWidget *parent = nullptr);
    ~FormChat();
    void addMessage(const QString &message, const QColor &aColor = Qt::black, const QFont::Weight aFont = QFont::Weight::Normal);
    void addMessage(const Message &aMessage);

    void messagesToUi();

signals:
    void s_sendMessage(const QString &message);
    void s_sendDices(int dices, int count);

private slots:
    void messageToUi(const Message &message);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::FormChat *ui;
    void keyPressEvent(QKeyEvent *event);

    QList<Message> messages_;

    QString lastMessage_;
};

#endif // FORMCHAT_H
