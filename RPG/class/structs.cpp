#include "structs.h"
#include <QDebug>

QString statusToString(Status aStatus) {
    switch (aStatus) {
    case Status::error: {
        return "error";
    }
    case Status::success: {
        return "success";
    }
    case Status::unsuccess: {
        return "unsuccess";
    }
    case Status::unknown: {
        return "";
    }
    }
    return "";
}

Status stringToStatus(QString aStatus) {
    if (aStatus == "error") {
        return Status::error;
    } else if (aStatus == "success") {
        return Status::success;
    }
    return Status::unknown;
}

QString communicationTypeToString(CommunicationType aCommunication) {
    switch (aCommunication) {
    case CommunicationType::message: {
        return "chatMessage";
    }
    case CommunicationType::registers: {
        return "register";
    }
    case CommunicationType::dices: {
        return "dices";
    }
    case CommunicationType::kick: {
        return "kick";
    }
    case CommunicationType::user: {
        return "user";
    }
    case CommunicationType::users: {
        return "users";
    }
    case CommunicationType::unknown: {
        return "";
    }
    }
    return "";
}

CommunicationType stringToCommunicationType(QString aCommunication) {
    if (aCommunication == "chatMessage") {
        return CommunicationType::message;
    } else if (aCommunication == "register") {
        return CommunicationType::registers;
    } else if (aCommunication == "dices") {
        return CommunicationType::dices;
    } else if (aCommunication == "kick") {
        return CommunicationType::kick;
    } else if (aCommunication == "user") {
        return CommunicationType::user;
    } else if (aCommunication == "users") {
        return CommunicationType::users;
    }
    return CommunicationType::unknown;
}

bool centralize(const QWidget *parent, QWidget *child) {
    QRect parentGeometry = parent->geometry();
    QSize childSize = child->sizeHint();
    QRect result(((parentGeometry.width() / 2) - (childSize.width() / 2)),
                ((parentGeometry.height() / 2) - (childSize.height() / 2)),
                childSize.width(),
                childSize.height());
    child->setGeometry(result);
    return true;
}

QJsonObject RequestToServer::toJson() const {
    QJsonObject object;
    object["type"] = this->requestType;
    object["value"] = this->value;
    return object;
}

RequestToServer RequestToServer::fromJson(const QJsonObject &aObject) {
    RequestToServer reply;
    reply.requestType = aObject.value("type").toString();
    reply.value = aObject.value("value");
    return reply;
}

RequestToServer RequestToServer::createMessage(const Message &aMessage) {
    RequestToServer rts;
    rts.requestType = communicationTypeToString(CommunicationType::message);
    QJsonObject object;
    object["message"] = aMessage.toJson();
    rts.value = object;
    return rts;
}

RequestToServer RequestToServer::createRegister(const QString &aNickName) {
    RequestToServer rts;
    rts.requestType = communicationTypeToString(CommunicationType::registers);
    QJsonObject object;
    object["nickName"] = aNickName;
    rts.value = object;
    return rts;
}

RequestToServer RequestToServer::createDices(int aDices, int aCount) {
    RequestToServer rts;
    rts.requestType = communicationTypeToString(CommunicationType::dices);
    QJsonObject object;
    object["dices"] = aDices;
    object["count"] = aCount;
    rts.value = object;
    return rts;
}

QJsonObject ReplyToClient::toJson() const {
    QJsonObject object;
    object["type"] = this->replyType;
    object["value"] = this->value;
    return object;
}

ReplyToClient ReplyToClient::fromJson(QJsonObject aObject) {
    ReplyToClient reply;
    reply.replyType = aObject.value("type").toString();
    reply.value = aObject.value("value");
    return reply;
}

ReplyToClient ReplyToClient::createMessage(const Message &aMessage) {
    ReplyToClient rtc;
    rtc.replyType = communicationTypeToString(CommunicationType::message);
    QJsonObject object;
    object["message"] = aMessage.toJson();
    rtc.value = object;
    return rtc;
}

ReplyToClient ReplyToClient::createRegister(Status aStatus, const QString &aDescription, const QString &aNickName, bool aIsYou) {
    ReplyToClient rtcReturn;
    rtcReturn.replyType = communicationTypeToString(CommunicationType::registers);
    QJsonObject object;
    object["status"] = statusToString(aStatus);
    object["nickName"] = aNickName;
    object["description"] = aDescription;
    object["isYou"] = aIsYou;
    rtcReturn.value = object;
    return rtcReturn;
}

ReplyToClient ReplyToClient::createDices(int aDices, QList<int> aValues) {
    ReplyToClient rtcReturn;
    rtcReturn.replyType = communicationTypeToString(CommunicationType::dices);
    QJsonObject object;
    object["dices"] = aDices;
    QJsonArray jValues;
    for(int value: aValues) {
        jValues.append(value);
    }
    object["values"] = jValues;
    rtcReturn.value = object;
    return rtcReturn;
}

ReplyToClient ReplyToClient::createKick(const QString &aMessage) {
    ReplyToClient rtcReturn;
    rtcReturn.replyType = communicationTypeToString(CommunicationType::kick);
    QJsonObject object;
    object["description"] = aMessage;
    rtcReturn.value = object;
    return rtcReturn;
}

ReplyToClient ReplyToClient::createUser(Player aPlayer) {
    ReplyToClient rtcReturn;
    rtcReturn.replyType = communicationTypeToString(CommunicationType::user);
    rtcReturn.value = aPlayer.toJson();
    return rtcReturn;
}

ReplyToClient ReplyToClient::createUsers(QList<QPair<int, Player>> aPlayers) {
    ReplyToClient rtcReturn;
    rtcReturn.replyType = communicationTypeToString(CommunicationType::users);
    QJsonObject object;
    QJsonArray jValues;
    for(auto value: aPlayers) {
        QJsonObject jPlayer;
        jPlayer["id"] = value.first;
        jPlayer["player"] = value.second.toJson();
        jValues.append(jPlayer);
    }
    object["values"] = jValues;
    rtcReturn.value = object;
    qDebug() << 11 << object;
    return rtcReturn;
}

Message::Message(const QString &aMessage, MessageType aType, const QString &aSender, QColor aColor, const QString &aAdditions):
type(aType), time(QDateTime::currentDateTime()), senderColor(aColor), sender(aSender), additions(aAdditions), message(aMessage) {

}

QJsonObject Message::toJson() const {
    QJsonObject object;
    object["type"] = static_cast<int>(this->type);
    object["time"] = this->time.toString("yyyy.MM.dd hh:mm:ss");
    object["sender"] = this->sender;
    object["senderColor"] = this->senderColor.name();
    object["additions"] = this->additions;
    object["message"] = this->message;
    return object;
}

Message Message::fromJson(const QJsonObject &aObject) {
    Message message;
    message.type = static_cast<MessageType>(aObject.value("type").toInt());
    message.time = QDateTime::fromString(aObject.value("time").toString(), "yyyy.MM.dd hh:mm:ss");
    message.sender = aObject.value("sender").toString();
    message.senderColor.setNamedColor(aObject.value("senderColor").toString());
    message.additions = aObject.value("additions").toString();
    message.message = aObject.value("message").toString();
    return message;
}
