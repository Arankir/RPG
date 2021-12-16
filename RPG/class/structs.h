#ifndef STRUCTS_H
#define STRUCTS_H
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QWidget>
#include "class/player.h"
#include <QDateTime>

enum class GameUserType {
    client,
    server,
    unknown
};

enum class Status {
    error,
    success,
    unsuccess,
    unknown
};

enum class CommunicationType {
    message,
    registers,
    dices,
    kick,
    user,
    users,
    unknown
};

enum class MessageType {
    standart,
    system,
    dice
};

struct Message {
    Message(): time(QDateTime::currentDateTime()) {};
    Message(const QString &message, MessageType type, const QString &sender = QString(), QColor color = QColor(), const QString &additions = QString());

    MessageType type;
    QDateTime time;
    QColor senderColor;
    QString sender;
    QString additions;
    QString message;

    QJsonObject toJson() const;
    static Message fromJson(const QJsonObject &object);
};

//enum class MessageType {
//    userMessage = 1,
//    systemMessage = 2,
//    dices = 3
//};

QString statusToString(Status aStatus);
Status stringToStatus(QString aStatus);
QString communicationTypeToString(CommunicationType communication);
CommunicationType stringToCommunicationType(QString aCommunication);
bool centralize(const QWidget *parent, QWidget *child);

struct RequestToServer {
    QString requestType;
    QJsonValue value;

    QJsonObject toJson() const;
    static RequestToServer fromJson(const QJsonObject &);

    static RequestToServer createMessage(const Message &message);
    static RequestToServer createRegister(const QString &nickName);
    static RequestToServer createDices(int aDices, int aCount);
};

struct ReplyToClient {
    QString replyType;
    QJsonValue value;

    QJsonObject toJson() const;
    static ReplyToClient fromJson(QJsonObject);

    static ReplyToClient createMessage(const Message &message);
    static ReplyToClient createRegister(Status status, const QString &description, const QString &nickName, bool isYou = false);
    static ReplyToClient createDices(int dices, QList<int> values);
    static ReplyToClient createKick(const QString &message);
    static ReplyToClient createUser(Player player);
    static ReplyToClient createUsers(QList<QPair<int, Player> > players);

public:
};

#endif // STRUCTS_H
