#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <class/structs.h>

class MyServer : public QObject {
    Q_OBJECT
public:
    explicit MyServer(QObject *parent = 0);

    void start(quint16 port);
public slots:
    void slotNewConnection();
    void slotServerRead(QTcpSocket *aClient);
    int slotWrite(const QHostAddress &aAddress, const ReplyToClient &aReply);
    void slotsWrite(const ReplyToClient &aReply);
    void slotClientDisconnected(QTcpSocket *aClient);

signals:
    void s_started(bool);
    void s_connect(QHostAddress);
    void s_read(QHostAddress, RequestToServer);
    void s_disconnect(QHostAddress);

private:
    QTcpServer *server_;
    QList<QTcpSocket*> sockets_;
};

#endif // SERVER_H
