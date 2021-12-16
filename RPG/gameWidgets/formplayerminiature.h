#ifndef FORMPLAYERMINIATURE_H
#define FORMPLAYERMINIATURE_H

#include <QWidget>
#include "class/player.h"
#include "class/structs.h"

namespace Ui {
class FormPlayerMiniature;
}

class FormPlayerMiniature : public QWidget {
    Q_OBJECT

public:
    explicit FormPlayerMiniature(GameUserType type, Player &player, QWidget *parent = nullptr);
    ~FormPlayerMiniature();

public slots:
    void playerToUi();
    void setPlayer(const Player&);
    Player getPlayer();

private slots:
    void on_pushButtonKick_clicked();

signals:
    void s_kick(Player);

private:
    Ui::FormPlayerMiniature *ui;
    GameUserType type_;
    Player player_;
};

#endif // FORMPLAYERMINIATURE_H
