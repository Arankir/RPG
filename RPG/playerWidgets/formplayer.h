#ifndef FORMPLAYER_H
#define FORMPLAYER_H

#include <QWidget>
#include "class/player.h"
#include "class/structs.h"

namespace Ui {
class FormPlayer;
}

class FormPlayer : public QWidget {
    Q_OBJECT

public:
    explicit FormPlayer(QWidget *parent = nullptr);
    ~FormPlayer();

    void init(GameUserType aType, const Player &aPlayer);

signals:
    void s_playerStatsChanged(Player player);

private slots:
    void on_pushButtonAddItem_clicked();

private:
    Ui::FormPlayer *ui;

    Player player_;
    GameUserType type_;
};

#endif // FORMPLAYER_H
