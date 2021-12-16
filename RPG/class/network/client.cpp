#include "client.h"
#include <QHostAddress>
#include <QDataStream>
#include <QDateTime>

MyClient::MyClient(QObject *parent) : QTcpSocket(parent) {
    QObject::connect(this, &QTcpSocket::readyRead, this, &MyClient::read);
}

bool MyClient::connect(const QHostAddress &host, quint16 port) {
    this->connectToHost(host, port);
    qDebug() << "connecting" << host;
    return this->waitForConnected();
}

void MyClient::read() {
    if (lastUpdate_.addSecs(5) < QDateTime::currentDateTime()) {
        buffer_.clear();
    }

    buffer_ += this->readAll();
    lastUpdate_ = QDateTime::currentDateTime();

    if (QJsonDocument::fromBinaryData(buffer_).isNull()) {
        return;
    }
//    qDebug() << 1 << array;
    ReplyToClient rtc = ReplyToClient::fromJson(QJsonDocument::fromBinaryData(buffer_).object());
    buffer_.clear();
//    qDebug() << QString(array);
    emit s_read(rtc);
}

QByteArray intToArray(qint32 source) {//Use qint32 to ensure that the number have 4 bytes
    //Avoid use of cast, this is the Qt way to serialize objects
    QByteArray temp;
    QDataStream data(&temp, QIODevice::ReadWrite);
    data << source;
    return temp;
}

bool MyClient::writeData(const RequestToServer &data) {
    if(this->state() == QAbstractSocket::ConnectedState) {
//        this->write(intToArray(data.size())); //write size of data
        this->write(QJsonDocument(data.toJson()).toBinaryData()); //write the data itself
        return this->waitForBytesWritten();
    } else
        return false;
}
