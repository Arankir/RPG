#ifndef FORMPLAYERINVENTORY_H
#define FORMPLAYERINVENTORY_H

#include <QWidget>
#include "class/settings.h"
#include "class/player.h"
#include "class/structs.h"

namespace Ui {
class FormPlayerInventory;
}

class FormPlayerInventory : public QWidget {
    Q_OBJECT

public:
    explicit FormPlayerInventory(QWidget *parent = nullptr);
    ~FormPlayerInventory();

    void init(GameUserType aType, const Player &aPlayer);

    void paintEvent(QPaintEvent *e);

    void playerToUi();
private:
    Ui::FormPlayerInventory *ui;

    GameUserType type_;
    Player player_;
};

#endif // FORMPLAYERINVENTORY_H
