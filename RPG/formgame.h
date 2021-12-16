#ifndef FORMGAME_H
#define FORMGAME_H

#include <QWidget>
#include <QMainWindow>
#include <QListWidgetItem>
#include "class/network/server.h"
#include "class/network/client.h"
#include "gameWidgets/formregister.h"
#include "gameWidgets/formplayerminiature.h"
#include "class/player.h"
#include "playerWidgets/formplayer.h"

struct UserInGame {
    QHostAddress address;
    Player player;
};

namespace Ui {
class FormGame;
}

class FormGame : public QWidget {
    Q_OBJECT

public:
    explicit FormGame(MyServer *server, QMainWindow *returnScreen, QWidget *parent = nullptr);
    explicit FormGame(MyClient *client, QMainWindow *returnScreen, QWidget *parent = nullptr);
    ~FormGame();

    void paintEvent(QPaintEvent *e) override;
    void sendMessage(const QString &aMessage);
    void sendDices(int aDices, int aCount);
    void showPlayer(Player aPlayer);
    void serverRead(QHostAddress aAdress, RequestToServer aMessage);
    void clientRead(ReplyToClient aMessage);
    void systemMessage(const QString &aMessage);
private slots:
    void on_pushButtonTest_clicked();

private:
    explicit FormGame(MyServer *server, MyClient *client, GameUserType type, const QString &title, QMainWindow *returnScreen, QWidget *parent = nullptr);
    void addUser(QHostAddress aAddress, const Player &nickName);
    void removeUser(int aIndex);
    void addMiniature(UserInGame aPlayer);
    void setEnableAllChildren(bool aEnabled);
    Ui::FormGame *ui;

    GameUserType userType_ = GameUserType::unknown;
    MyServer *server_;
    QList<UserInGame> users_;
    MyClient *client_;

    QString nick_;
    FormRegister *register_;
    QMainWindow *returnScreen_;

    void serverOnConnect(QHostAddress address);
    void serverOnDisconnect(QHostAddress aAddress);
    void serverOnMessage(const QString &aNickName, const QString &aColor, const QString &aMessage);
    void serverOnDices(const QString &aNickName, const QString &aColor, int aDices, int aCount);
    void serverOnChangeStats(Player aPlayer);
};

#endif // FORMGAME_H
