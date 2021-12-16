#ifndef PLAYEREQUIPMENT_H
#define PLAYEREQUIPMENT_H
#include "class/player/inventoryitem.h"

struct PlayerEquipment {
    InventoryItem *helm = nullptr;
    InventoryItem *chest = nullptr;
    InventoryItem *pants = nullptr;
    InventoryItem *boots = nullptr;
    InventoryItem *gloves = nullptr;
    InventoryItem *belt = nullptr;
    InventoryItem *accessories1 = nullptr;
    InventoryItem *accessories2 = nullptr;
    InventoryItem *accessories3 = nullptr;
    InventoryItem *accessories4 = nullptr;
    InventoryItem *hand1 = nullptr;
    InventoryItem *hand2 = nullptr;

    QJsonObject toJson();
    void fromJson(const QJsonObject&);

    int maxHealthPoints() const;
    int maxManaPoints() const;
    int armor() const;
    int strength() const;
    int agility() const;
    int intelligence() const;
    int stamina() const;
    int closeCombat() const;
    int accuracy() const;
    int movement() const;
    int dodge() const;
};

#endif // PLAYEREQUIPMENT_H
