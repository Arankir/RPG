#include "formchat.h"
#include "ui_formchat.h"
#include <QGraphicsOpacityEffect>
#include <QKeyEvent>
#include <QDialog>

const QColor c_timeColor = Qt::gray;

QString timeToString(const QDateTime &aTime) {
    return aTime.toString("hh:mm");
}

FormChat::FormChat(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormChat)
{
    ui->setupUi(this);
//    QGraphicsOpacityEffect *ope = new QGraphicsOpacityEffect(ui->textEditMessages);
//    ope->setOpacity(0.5);
//    ui->textEditMessages->setWindowOpacity(0.5);
    ui->textEditMessages->setStyleSheet("background: rgba(0,0,0,100); ");
}

FormChat::~FormChat() {
    delete ui;
}

void FormChat::keyPressEvent(QKeyEvent *event) {
    if((event->key() == Qt::Key_Enter) || (event->key() == Qt::Key_Return)) {
        if (ui->lineEditMessage == qApp->focusWidget()) {
            on_pushButton_clicked();
        }
    } else if(event->key() == Qt::Key_Up) {
        if (ui->lineEditMessage == qApp->focusWidget()) {
            ui->lineEditMessage->setText(lastMessage_);
        }
    } {
        QWidget::keyPressEvent(event);
    }
}

void FormChat::addMessage(const QString &aMessage, const QColor &aColor, const QFont::Weight aFont) {
//    ui->textEditMessages->append(aMessage);
    // save
    int fw = ui->textEditMessages->fontWeight();
    QColor tc = ui->textEditMessages->textColor();
    // append
    ui->textEditMessages->setFontWeight(aFont);
    ui->textEditMessages->setTextColor(aColor);
    ui->textEditMessages->append( aMessage );
    // restore
    ui->textEditMessages->setFontWeight(fw);
    ui->textEditMessages->setTextColor(tc);
}

void FormChat::addMessage(const Message &aMessage) {
    messages_.append(aMessage);
    messageToUi(aMessage);
}

void FormChat::messageToUi(const Message &aMessage) {
    ui->textEditMessages->moveCursor (QTextCursor::End);
    QString message;
    qDebug() << Settings::timeOnChat();
    if (Settings::timeOnChat()) {
        qDebug() << message;
        message += "<font color=\"" + c_timeColor.name() + "\">" + timeToString(aMessage.time) + "</font> ";
    }
    qDebug() << message;
    switch (aMessage.type) {
    case MessageType::standart: {
        message += "<font color=\"" + aMessage.senderColor.name() + "\">" + aMessage.sender + "</font>" + aMessage.message;
        break;
    }
    case MessageType::system: {
        message += "<font color=\"" + aMessage.senderColor.name() + "\">" + aMessage.message + "</font>";
        break;
    }
    case MessageType::dice: {
        message += "<font color=\"" + aMessage.senderColor.name() + "\">" + aMessage.sender + aMessage.additions + "</font>" + aMessage.message;
        break;
    }
    }
    ui->textEditMessages->append(message);
    ui->textEditMessages->moveCursor (QTextCursor::End);
}

void FormChat::messagesToUi() {
    ui->textEditMessages->clear();
    for (auto &message: messages_) {
        messageToUi(message);
    }
}

void FormChat::on_pushButton_clicked() {
    //????????????????????
    //ui->textEditMessages->append("\n" + ui->lineEditMessage->text());
    QString message = ui->lineEditMessage->text();
    ui->lineEditMessage->clear();
    lastMessage_ = message;
    emit s_sendMessage(message);
}

void FormChat::on_pushButton_2_clicked() {
    emit s_sendDices(ui->spinBox->value(), ui->spinBox_2->value());
}
