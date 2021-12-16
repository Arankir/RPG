#include "server.h"
#include <QDebug>
#include <QCoreApplication>

MyServer::MyServer(QObject *parent) : QObject(parent) {
    server_ = new QTcpServer(this);
    connect(server_, &QTcpServer::newConnection, this, &MyServer::slotNewConnection);
}

void MyServer::start(quint16 port) {
    if(!server_->listen(QHostAddress::Any, port)) {
        emit s_started(false);
        qDebug() << "server is not started";
    } else {
        emit s_started(true);
        qDebug() << "server is started";
    }
}

void MyServer::slotNewConnection() {
    qDebug() << "client connected";
    while (server_->hasPendingConnections()) {
        QTcpSocket *client = server_->nextPendingConnection();
        sockets_.append(client);
        connect(client, &QTcpSocket::readyRead, this, [&]() {
            MyServer::slotServerRead(client);
        });
        connect(client, &QTcpSocket::disconnected, this, [&]() {
            MyServer::slotClientDisconnected(client);
        });
        emit s_connect(client->peerAddress());

//        client->write("Hello, World!!! I am echo server!\r\n");
    }
}

void MyServer::slotServerRead(QTcpSocket *aClient) {
    Q_UNUSED(aClient);
    qDebug() << "read";
    QTcpSocket *socket = static_cast<QTcpSocket*>(sender());
    while(socket->bytesAvailable() > 0) {
        QByteArray array = socket->readAll();
        RequestToServer rts = RequestToServer::fromJson(QJsonDocument::fromBinaryData(array).object());
        emit s_read(socket->peerAddress(), rts);
//        socket->write(array);
    }
}

void MyServer::slotsWrite(const ReplyToClient &aReply) {
    qDebug() << "writes";
    const QByteArray message = QJsonDocument(aReply.toJson()).toBinaryData();
    int i = 0;
    for (auto client: sockets_) {
        qDebug() << "write" << client->peerAddress() << aReply.toJson();
        client->write(message);
        ++i;
    }
}

int MyServer::slotWrite(const QHostAddress &aAddress, const ReplyToClient &aReply) {
    qDebug() << "write";
    const QByteArray message = QJsonDocument(aReply.toJson()).toBinaryData();
    for (int i = sockets_.count() - 1; i >= 0; --i) {
        if (sockets_[i]->peerAddress() == aAddress) {
            qDebug() << "write" << i;
            return sockets_[i]->write(message);
        }
    }
    qWarning() << "didn't find address" << aAddress;
    return -2;
//    auto iterator = std::find_if(sockets_.begin(),
//                                 sockets_.end(),
//                                 [&](QTcpSocket *socket) {
//                                    return socket->peerAddress() == aAddress;
//                                });
//    if (iterator != sockets_.end()) {
//        qDebug() << "write" << iterator - sockets_.begin();
//        return (*iterator)->write(message);
//    } else {
//        qWarning() << "didn't find address" << aAddress;
//        return -2;
//    }
}

void MyServer::slotClientDisconnected(QTcpSocket *aClient) {
    Q_UNUSED(aClient);
    QTcpSocket *socket = static_cast<QTcpSocket*>(sender());
    emit s_disconnect(socket->peerAddress());
    qDebug() << "disconnected";
    sockets_.removeOne(socket);
    socket->deleteLater();
}
