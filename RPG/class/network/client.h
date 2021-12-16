#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QDateTime>
#include "class/structs.h"

class MyClient : public QTcpSocket {
    Q_OBJECT
public:
    explicit MyClient(QObject *parent = nullptr);
    bool connect(const QHostAddress &, quint16 port);
    void read();
    bool writeData(const RequestToServer &data);

signals:
    void s_read(ReplyToClient);

private:
    QByteArray buffer_;
    QDateTime lastUpdate_;

};

#endif // CLIENT_H
