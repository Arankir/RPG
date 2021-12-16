#include "formgame.h"
#include "ui_formgame.h"
#include <QPainter>
#include <QMessageBox>

const QString c_colorUser = "Aqua";
const QString c_colorGM = "Orange";
const QString c_colorSystem = "Gray";

QString addColor(const QString &aMessage, const QString &aColor) {
    return "<font color=\"" + aColor + "\">" + aMessage + "</font>";
}

void FormGame::setEnableAllChildren(bool aEnabled) {
    for (auto child: this->children()) {
        QWidget *widgetChild = dynamic_cast<QWidget*>(child);
        if (widgetChild) {
            widgetChild->setEnabled(aEnabled);
        }
    }
}

FormGame::FormGame(MyServer *aServer, MyClient *aClient, GameUserType aType, const QString &aTitle, QMainWindow *aReturnScreen, QWidget *aParent) :
QWidget(aParent), ui(new Ui::FormGame), userType_(aType), server_(aServer), client_(aClient), returnScreen_(aReturnScreen) {
    ui->setupUi(this);
    connect(ui->chat, &FormChat::s_sendMessage, this, &FormGame::sendMessage);
    connect(ui->chat, &FormChat::s_sendDices, this, &FormGame::sendDices);
    connect(ui->listWidgetPlayers, &QListWidget::itemDoubleClicked, this, [&](QListWidgetItem *lItem) {
        FormPlayerMiniature *playerMiniature = dynamic_cast<FormPlayerMiniature*>(ui->listWidgetPlayers->itemWidget(lItem));
        if (playerMiniature) {
            showPlayer(playerMiniature->getPlayer());
        }
    });
    setWindowTitle(aTitle);
    setEnableAllChildren(false);

    register_ = new FormRegister(this);
    centralize(this, register_);
}

FormGame::FormGame(MyServer *aServer, QMainWindow *aReturnScreen, QWidget *aParent): FormGame(aServer, nullptr, GameUserType::server, tr("RPG Server"), aReturnScreen, aParent) {
    connect(server_, &MyServer::s_read, this, &FormGame::serverRead);
    connect(server_, &MyServer::s_connect, this, &FormGame::serverOnConnect);
    connect(server_, &MyServer::s_disconnect, this, &FormGame::serverOnDisconnect);
    connect(register_, &FormRegister::s_sendData, this, [&](const QString &nickName) {
        nick_ = nickName;
        setEnableAllChildren(true);
        register_->deleteLater();
    });
}

FormGame::FormGame(MyClient *aClient, QMainWindow *aReturnScreen, QWidget *aParent): FormGame(nullptr, aClient, GameUserType::client, tr("RPG Client"), aReturnScreen, aParent) {
    connect(client_, &MyClient::s_read, this, &FormGame::clientRead);
    connect(register_, &FormRegister::s_sendData, this, [=](const QString &nickName) {
        client_->writeData(RequestToServer::createRegister(nickName));
    });
}

void FormGame::paintEvent(QPaintEvent *e) {
    QPainter painter(this);
    painter.drawPixmap(0, 0, QPixmap("://backgrounds/game.png").scaled(size()));
    QWidget::paintEvent(e);
}

FormGame::~FormGame() {
    delete ui;
}

void FormGame::addUser(QHostAddress aAddress, const Player &aPlayer) {
    auto uig = UserInGame{aAddress, aPlayer};
    users_.append(uig);
    addMiniature(uig);
}

void FormGame::addMiniature(UserInGame aUser) {
    auto item = new QListWidgetItem();
    FormPlayerMiniature *miniature = new FormPlayerMiniature(userType_, aUser.player);
    switch (userType_) {
    case GameUserType::server: {
        connect(miniature, &FormPlayerMiniature::s_kick, this, [&](const Player &lPlayer) {
            auto iterator = std::find_if(users_.begin(), users_.end(), [&](UserInGame lUig){return lUig.player.nickName() == lPlayer.nickName();});
            if (iterator != users_.end()) {
                server_->slotWrite((*iterator).address, ReplyToClient::createKick(tr("Вы были исключены ГеймМастером!")));
            }
        });
        break;
    }
    case GameUserType::client: {

        break;
    }
    default: {

    }
    }

    item->setSizeHint(miniature->sizeHint());
    item->setWhatsThis(QString::number(aUser.player.getIndex()));
    item->setToolTip(aUser.player.nickName());
    ui->listWidgetPlayers->addItem(item);
    ui->listWidgetPlayers->setItemWidget(item, miniature);
}

void FormGame::removeUser(int aIndex) {
    auto iteratorUsers = std::find_if(users_.begin(), users_.end(), [&](UserInGame lUser) {return lUser.player.getIndex() == aIndex;});
    if (iteratorUsers != users_.end()) {
        int userIndex = users_.at(iteratorUsers - users_.begin()).player.getIndex();
        for (int i = 0; i < ui->listWidgetPlayers->count(); ++i) {
            if (ui->listWidgetPlayers->item(i)->whatsThis() == QString::number(userIndex)) {
                ui->listWidgetPlayers->removeItemWidget(ui->listWidgetPlayers->item(i));
                delete ui->listWidgetPlayers->item(i);
                break;
            }
        }
        users_.removeAt(iteratorUsers - users_.begin());
    }
}

void FormGame::serverRead(QHostAddress aAddress, RequestToServer aRequest) {
    qDebug() << "server read" << aAddress << aRequest.requestType << aRequest.value;
    auto iterator = std::find_if(users_.begin(), users_.end(), [&](UserInGame lUser) {return lUser.address == aAddress;});
    if (iterator != users_.end()) {
        switch (stringToCommunicationType(aRequest.requestType)) {
        case CommunicationType::message: {
            serverOnMessage((*iterator).player.nickName(), c_colorUser, aRequest.value.toObject().value("message").toObject().value("message").toString());
            break;
        }
        case CommunicationType::registers: {
            QString nickName = aRequest.value.toObject().value("nickName").toString();
            if (nickName == "") {
                server_->slotWrite(aAddress, ReplyToClient::createRegister(Status::error, tr("Введите имя!"), nickName, true));
                break;
            }
            if (std::any_of(users_.begin(), users_.end(), [&](UserInGame lUser) {return lUser.player.nickName() == nickName;})) {
                server_->slotWrite(aAddress, ReplyToClient::createRegister(Status::error, tr("Такое имя уже занято!"), nickName));
                break;
            }
            if (nickName == nick_) {
                server_->slotWrite(aAddress, ReplyToClient::createRegister(Status::error, tr("Это имя использует ГеймМастер!"), nickName));
                break;
            }

            auto user = std::find_if(users_.begin(), users_.end(), [&](UserInGame lUser) {return lUser.address == aAddress;});
            if (user != users_.end()) {
                user->player.setNickName(nickName);
                int userIndex = users_.at(user - users_.begin()).player.getIndex();
                for (int i = 0; i < ui->listWidgetPlayers->count(); ++i) {
                    if (ui->listWidgetPlayers->item(i)->whatsThis() == QString::number(userIndex)) {
                        auto miniature = dynamic_cast<FormPlayerMiniature*>(ui->listWidgetPlayers->itemWidget(ui->listWidgetPlayers->item(i)));
                        if (miniature) {
                            miniature->setPlayer((*user).player);
                            miniature->playerToUi();
                        }
                        break;
                    }
                }
            }
            QString message = tr("Присоединился игрок %1!").arg(nickName);
            server_->slotWrite(aAddress, ReplyToClient::createRegister(Status::success, tr("Вы успешно присоединились к игре!"), nickName, true));
            server_->slotsWrite(ReplyToClient::createRegister(Status::success, message, nickName));

//                int i = -1;
//                QList<QPair<int, Player>> list;
//                for(const auto &player: users_) {
//                    list.append(std::move(QPair<int, Player>(++i, player.player)));
//                }
//                server_->slotsWrite(ReplyToClient::createUsers(list));
            systemMessage(message);
            break;
        }
        case CommunicationType::dices: {
            int dices = aRequest.value.toObject().value("dices").toInt();
            int count = aRequest.value.toObject().value("count").toInt();

            serverOnDices((*iterator).player.nickName(), c_colorUser, dices, count);
            break;
        }
        default: {
            break;
        }
        }
    } else {
        switch (stringToCommunicationType(aRequest.requestType)) {
        case CommunicationType::registers: {
            server_->slotWrite(aAddress, ReplyToClient::createRegister(Status::error, tr("Неизвестная ошибка!"), aRequest.value.toObject().value("nickName").toString()));
            break;
        }
        default: {
            break;
        }
        }
        qWarning() << "address" << aAddress << "didn't find";
    }
}

void FormGame::clientRead(ReplyToClient aReply) {
    qDebug() << "client read" << aReply.replyType << aReply.value;
    switch (stringToCommunicationType(aReply.replyType)) {
    case CommunicationType::message: {
        ui->chat->addMessage(Message::fromJson(aReply.value.toObject().value("message").toObject()));
//        switch (static_cast<MessageType>(aReply.value.toObject().value("type").toInt())) {
//        case MessageType::dice:
//        case MessageType::standart: {
//            Message message;
//            message.type = MessageType::standart;
//            message.time = QDateTime::currentDateTime();
//            message.message = aReply.value.toObject().value("message").toString();

//            ui->chat->addMessage(message);
//            break;
//        }
//        case MessageType::system: {
//            systemMessage(aReply.value.toObject().value("message").toString());
//            break;
//        }
//        }
//        break;
        break;
    }
    case CommunicationType::registers: {
        switch (stringToStatus(aReply.value.toObject().value("status").toString())) {
        case Status::success: {
            if (aReply.value.toObject().value("isYou").toBool()) { //Успешная регистрация
                systemMessage(aReply.value.toObject().value("description").toString());
                setEnableAllChildren(true);
                nick_ = aReply.value.toObject().value("nickName").toString();
                Player player;
                player.setNickName(aReply.value.toObject().value("nickName").toString());
                addUser(QHostAddress(), player);
                register_->deleteLater();
            } else { //Кто-то присоединился к игре
                Player player;
                player.setNickName(aReply.value.toObject().value("nickName").toString());
                addUser(QHostAddress(), player);
                systemMessage(aReply.value.toObject().value("description").toString());
            }
            break;
        }
        case Status::error: {
            QMessageBox::warning(this, tr("Ошибка!"), aReply.value.toObject().value("description").toString());
            break;
        }
        case Status::unsuccess: {
            auto iterator = std::find_if(users_.begin(), users_.end(), [&](UserInGame lUig){return lUig.player.nickName() == aReply.value.toObject().value("nickName").toString();});
            if (iterator != users_.end()) {
                removeUser((*iterator).player.getIndex());
            }
            systemMessage(aReply.value.toObject().value("description").toString());
            break;
        }
        case Status::unknown: {
            break;
        }
        }
        break;
    }
    case CommunicationType::kick: {
        client_->disconnectFromHost();
        QMessageBox::information(0,tr("Внимание!"),aReply.value.toObject().value("description").toString());
        returnScreen_->show();
        this->deleteLater();
        break;
    }
    case CommunicationType::user: {
        Player player(aReply.value.toObject());
        for (int i = 0; i < ui->listWidgetPlayers->count(); ++i) {
            auto item = ui->listWidgetPlayers->item(i);
            FormPlayerMiniature *playerMiniature = dynamic_cast<FormPlayerMiniature*>(ui->listWidgetPlayers->itemWidget(item));
            if (playerMiniature) {
                if (player.nickName() == playerMiniature->getPlayer().nickName()) {
                    playerMiniature->setPlayer(player);
                    playerMiniature->playerToUi();
                    break;
                }
            }
        }
        if (player.nickName() == nick_) {
//            ui->playerStats->init(userType_, player);
        }
        break;
    }
    case CommunicationType::users: {
        ui->listWidgetPlayers->clear();
        users_.clear();
        qDebug() << 2 << aReply.value.toObject().value("value").toArray();
        for(auto player: aReply.value.toObject().value("value").toArray()) {
            qDebug() << 3 << player.toObject().value("player").toObject();
            addUser(QHostAddress(), Player(player.toObject().value("player").toObject()));
        }
        break;
    }
    case CommunicationType::dices:
    case CommunicationType::unknown: {
        break;
    }
    }
}

void FormGame::systemMessage(const QString &aMessage) {
    ui->chat->addMessage(addColor("*" + aMessage + "*", c_colorSystem));
}

void FormGame::serverOnConnect(QHostAddress aAddress) {
//        auto iterator = std::find_if(users_.begin(), users_.end(), [&](UserInGame lUser) {return lUser.address == address;});
//        if (iterator != users_.end()) {
//            server_->slotWrite(address, ReplyToClient::createKick(tr("Пользователь с таким IP уже существует!")));
//            writeSystemMessage(tr("Гавнюк с IP %1 пытался зайти с 2 окон!").arg(address.toString()));
//            return;
//        }
    qDebug() << aAddress;
    addUser(aAddress, Player());
    server_->slotsWrite(ReplyToClient::createMessage(Message(tr("Подключился новый пользователь!"), MessageType::system)));
    systemMessage(tr("Подключился новый пользователь!"));
}

void FormGame::serverOnDisconnect(QHostAddress aAddress) {
    auto iterator = std::find_if(users_.begin(), users_.end(), [&](UserInGame lUser) {return lUser.address == aAddress;});
    if (iterator != users_.end()) {
        int index = (*iterator).player.getIndex();
        QString nickName = (*iterator).player.nickName();
        removeUser(index);
        if (nickName != "") {
            server_->slotsWrite(ReplyToClient::createRegister(Status::unsuccess, tr("%1 отключился!").arg(nickName), nickName));
        }
        systemMessage(tr("%1 отключился!").arg(nickName));
    } else {
        server_->slotsWrite(ReplyToClient::createMessage(Message(tr("Отключился неизвестный игрок!"), MessageType::system)));
        systemMessage(tr("Отключился неизвестный игрок!"));
    }
}

void FormGame::serverOnMessage(const QString &aNickName, const QString &aColor, const QString &aMessage) {
    if (aMessage != "") {
        Message message(aMessage, MessageType::standart, aNickName, aColor);
//        QString message = addColor(aNickName, aColor) + ": " + aMessage;
        ui->chat->addMessage(message);
        server_->slotsWrite(ReplyToClient::createMessage(message));
    }
}

void FormGame::serverOnDices(const QString &aNickName, const QString &aColor, int aDices, int aCount) {
    qsrand(qrand());
    QStringList results;
    for (int i = 0; i < aCount; ++i) {
        results.append(QString::number(qrand()%(aDices)+1));
    }
    Message message(results.join(","), MessageType::dice, aNickName, aColor, "(d" + QString::number(aDices) + "x" + QString::number(aCount) + ")");
//    QString message = addColor(aNickName, aColor) + "(d" + QString::number(aDices) + "x" + QString::number(aCount) + "): " + results.join(",");
    server_->slotsWrite(ReplyToClient::createMessage(message));
    ui->chat->addMessage(message);
}

void FormGame::serverOnChangeStats(Player aPlayer) {
    for (int i = 0; i < ui->listWidgetPlayers->count(); ++i) {
        auto item = ui->listWidgetPlayers->item(i);
        FormPlayerMiniature *playerMiniature = dynamic_cast<FormPlayerMiniature*>(ui->listWidgetPlayers->itemWidget(item));
        if (playerMiniature) {
            if (aPlayer.getIndex() == playerMiniature->getPlayer().getIndex()) {
                playerMiniature->setPlayer(aPlayer);
                playerMiniature->playerToUi();
                server_->slotsWrite(ReplyToClient::createUser(aPlayer));
                break;
            }
        }
    }
}

void FormGame::sendMessage(const QString &aMessage) {
    if (userType_ == GameUserType::client) {
        client_->writeData(RequestToServer::createMessage(Message(aMessage, MessageType::standart, nick_, c_colorUser)));
    } else {
        serverOnMessage(nick_ + "(GM)", c_colorGM, aMessage);
    }
}

void FormGame::sendDices(int aDices, int aCount) {
    if (userType_ == GameUserType::client) {
        client_->writeData(RequestToServer::createDices(aDices, aCount));
    } else {
        serverOnDices(nick_ + "(GM)", c_colorGM, aDices, aCount);
    }
}

void FormGame::showPlayer(Player aPlayer) {
    if ((userType_ == GameUserType::server) || (aPlayer.nickName() == nick_)) {
        FormPlayer *formPlayer = new FormPlayer();
        connect(formPlayer, &FormPlayer::s_playerStatsChanged, this, &FormGame::serverOnChangeStats);
        formPlayer->init(userType_, aPlayer);
        formPlayer->show();
    } else {
        QMessageBox::warning(this, tr("Ошибка!"), tr("Нельзя смотреть статы других персонажей!"));
    }
}

//Всем поднять или опустить стат, экспу, хп, перед этим проверить всех, если у кого-то меньше нужного, вывести предупреждение
//Вывести сумму на кубиках, когда бросают несколько

void FormGame::on_pushButtonTest_clicked() {
    Player player;
    player.setNickName("TestNickName");
    player.setArmor(1);
    showPlayer(player);
}
