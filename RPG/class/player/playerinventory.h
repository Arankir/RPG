#ifndef PLAYERINVENTORY_H
#define PLAYERINVENTORY_H
#include "class/player/inventoryitem.h"

const int c_cellsBagWidth = 10;
const int c_cellsBagHeight = 10;

struct PlayerInventory {
    QList<QPair<InventoryItem*, QPoint>> items;

    QJsonObject toJson();
    void fromJson(const QJsonObject&);

    bool addItem(InventoryItem*, QPoint);
    bool addItem(InventoryItem*);
    bool moveItem(QPoint oldPosition, QPoint newPosition);
    InventoryItem *takeItem(InventoryItem *aItem);
    void removeItem(QPoint);

private:
    QList<QPoint> accessPoints(InventoryItem*);
};

#endif // PLAYERINVENTORY_H
