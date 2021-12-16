#ifndef FORMPLAYERSTATS_H
#define FORMPLAYERSTATS_H

#include <QWidget>
#include "class/player.h"
#include "class/structs.h"

namespace Ui {
class FormPlayerStats;
}

class FormPlayerStats : public QWidget {
    Q_OBJECT

public:
    explicit FormPlayerStats(QWidget *parent = nullptr);
    void init(GameUserType aType, const Player &aPlayer);
    ~FormPlayerStats();

    void playerToUi();
    void uiToPlayer();

    Player getPlayer();
    void setPlayer(const Player &player);
    bool isInit();

signals:
    void s_playerStatsChanged(Player player);

private slots:
    void on_pushButtonApply_clicked();

    void on_pushButtonLoadAvatar_clicked();

    void on_pushButtonAddStrength_clicked();

    void on_pushButtonAddAgility_clicked();

    void on_pushButtonAddIntelegence_clicked();

    void on_pushButtonAddStamina_clicked();

private:
    Ui::FormPlayerStats *ui;
    GameUserType type_;
    Player player_;
};

#endif // FORMPLAYERSTATS_H
