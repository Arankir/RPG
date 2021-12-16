#ifndef FORMINVENTORYBAG_H
#define FORMINVENTORYBAG_H

#include <QWidget>
#include <class/widgets/inventoryitemvisual.h>
#include <formgame.h>
#include <class/player.h>

namespace Ui {
class FormInventoryBag;
}

class FormInventoryBag : public QWidget {
    Q_OBJECT

public:
    explicit FormInventoryBag(QWidget *parent = nullptr);
    ~FormInventoryBag();
    bool addItem(InventoryItem *item, QPoint aPoint);

    void createMenu(QPointF pos, InventoryItemVisual *graphicItem, InventoryItem *item);
    void init(GameUserType aType, const Player &aPlayer);
    void playerToUi();
    bool addItem(InventoryItem *aItem);

signals:
    void s_itemEquiped(InventoryItem *aItem);

private:
    Ui::FormInventoryBag *ui;

    GameUserType type_;
    Player player_;
};

#endif // FORMINVENTORYBAG_H
