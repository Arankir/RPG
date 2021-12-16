#include "playerequipment.h"

QJsonObject PlayerEquipment::toJson() {
    QJsonObject obj;
    if (helm) {
        obj["helm"] = helm->toJson();
    }
    if (chest) {
        obj["chest"] = chest->toJson();
    }
    if (pants) {
        obj["pants"] = pants->toJson();
    }
    if (gloves) {
        obj["gloves"] = gloves->toJson();
    }
    if (accessories1) {
        obj["accessories1"] = accessories1->toJson();
    }
    if (accessories2) {
        obj["accessories2"] = accessories2->toJson();
    }
    if (accessories3) {
        obj["accessories3"] = accessories3->toJson();
    }
    if (accessories4) {
        obj["accessories4"] = accessories4->toJson();
    }
    if (hand1) {
        obj["hand1"] = hand1->toJson();
    }
    if (hand2) {
        obj["hand2"] = hand2->toJson();
    }
    if (boots) {
        obj["boots"] = boots->toJson();
    }
    if (belt) {
        obj["belt"] = belt->toJson();
    }
    return obj;
}

void PlayerEquipment::fromJson(const QJsonObject &aObject) {
    if (aObject.value("helm").toString() != "") {
        helm = new InventoryItem();
        helm->fromJson(aObject.value("helm").toObject());
    }
    if (aObject.value("chest").toString() != "") {
        chest = new InventoryItem();
        chest->fromJson(aObject.value("chest").toObject());
    }
    if (aObject.value("pants").toString() != "") {
        pants = new InventoryItem();
        pants->fromJson(aObject.value("pants").toObject());
    }
    if (aObject.value("gloves").toString() != "") {
        gloves = new InventoryItem();
        gloves->fromJson(aObject.value("gloves").toObject());
    }
    if (aObject.value("accessories1").toString() != "") {
        accessories1 = new InventoryItem();
        accessories1->fromJson(aObject.value("accessories1").toObject());
    }
    if (aObject.value("accessories2").toString() != "") {
        accessories2 = new InventoryItem();
        accessories2->fromJson(aObject.value("accessories2").toObject());
    }
    if (aObject.value("accessories3").toString() != "") {
        accessories3 = new InventoryItem();
        accessories3->fromJson(aObject.value("accessories3").toObject());
    }
    if (aObject.value("accessories4").toString() != "") {
        accessories4 = new InventoryItem();
        accessories4->fromJson(aObject.value("accessories4").toObject());
    }
    if (aObject.value("hand1").toString() != "") {
        hand1 = new InventoryItem();
        hand1->fromJson(aObject.value("hand1").toObject());
    }
    if (aObject.value("hand2").toString() != "") {
        hand2 = new InventoryItem();
        hand2->fromJson(aObject.value("hand2").toObject());
    }
    if (aObject.value("boots").toString() != "") {
        boots = new InventoryItem();
        boots->fromJson(aObject.value("boots").toObject());
    }
    if (aObject.value("belt").toString() != "") {
        belt = new InventoryItem();
        belt->fromJson(aObject.value("belt").toObject());
    }
}

int PlayerEquipment::maxHealthPoints() const {
    int value = 0;
    if (helm) {
        value += helm->maxHealthPoints();
    }
    if (chest) {
        value += chest->maxHealthPoints();
    }
    if (pants) {
        value += pants->maxHealthPoints();
    }
    if (gloves) {
        value += gloves->maxHealthPoints();
    }
    if (accessories1) {
        value += accessories1->maxHealthPoints();
    }
    if (accessories2) {
        value += accessories2->maxHealthPoints();
    }
    if (accessories3) {
        value += accessories3->maxHealthPoints();
    }
    if (accessories4) {
        value += accessories4->maxHealthPoints();
    }
    if (hand1) {
        value += hand1->maxHealthPoints();
    }
    if (hand2) {
        value += hand2->maxHealthPoints();
    }
    if (boots) {
        value += boots->maxHealthPoints();
    }
    if (belt) {
        value += belt->maxHealthPoints();
    }
    return value;
}

int PlayerEquipment::maxManaPoints() const {
    int value = 0;
    if (helm) {
        value += helm->maxManaPoints();
    }
    if (chest) {
        value += chest->maxManaPoints();
    }
    if (pants) {
        value += pants->maxManaPoints();
    }
    if (gloves) {
        value += gloves->maxManaPoints();
    }
    if (accessories1) {
        value += accessories1->maxManaPoints();
    }
    if (accessories2) {
        value += accessories2->maxManaPoints();
    }
    if (accessories3) {
        value += accessories3->maxManaPoints();
    }
    if (accessories4) {
        value += accessories4->maxManaPoints();
    }
    if (hand1) {
        value += hand1->maxManaPoints();
    }
    if (hand2) {
        value += hand2->maxManaPoints();
    }
    if (boots) {
        value += boots->maxManaPoints();
    }
    if (belt) {
        value += belt->maxManaPoints();
    }
    return value;
}

int PlayerEquipment::armor() const {
    int value = 0;
    if (helm) {
        value += helm->armor();
    }
    if (chest) {
        value += chest->armor();
    }
    if (pants) {
        value += pants->armor();
    }
    if (gloves) {
        value += gloves->armor();
    }
    if (accessories1) {
        value += accessories1->armor();
    }
    if (accessories2) {
        value += accessories2->armor();
    }
    if (accessories3) {
        value += accessories3->armor();
    }
    if (accessories4) {
        value += accessories4->armor();
    }
    if (hand1) {
        value += hand1->armor();
    }
    if (hand2) {
        value += hand2->armor();
    }
    if (boots) {
        value += boots->armor();
    }
    if (belt) {
        value += belt->armor();
    }
    return value;
}

int PlayerEquipment::strength() const {
    int value = 0;
    if (helm) {
        value += helm->strength();
    }
    if (chest) {
        value += chest->strength();
    }
    if (pants) {
        value += pants->strength();
    }
    if (gloves) {
        value += gloves->strength();
    }
    if (accessories1) {
        value += accessories1->strength();
    }
    if (accessories2) {
        value += accessories2->strength();
    }
    if (accessories3) {
        value += accessories3->strength();
    }
    if (accessories4) {
        value += accessories4->strength();
    }
    if (hand1) {
        value += hand1->strength();
    }
    if (hand2) {
        value += hand2->strength();
    }
    if (boots) {
        value += boots->strength();
    }
    if (belt) {
        value += belt->strength();
    }
    return value;
}

int PlayerEquipment::agility() const {
    int value = 0;
    if (helm) {
        value += helm->agility();
    }
    if (chest) {
        value += chest->agility();
    }
    if (pants) {
        value += pants->agility();
    }
    if (gloves) {
        value += gloves->agility();
    }
    if (accessories1) {
        value += accessories1->agility();
    }
    if (accessories2) {
        value += accessories2->agility();
    }
    if (accessories3) {
        value += accessories3->agility();
    }
    if (accessories4) {
        value += accessories4->agility();
    }
    if (hand1) {
        value += hand1->agility();
    }
    if (hand2) {
        value += hand2->agility();
    }
    if (boots) {
        value += boots->agility();
    }
    if (belt) {
        value += belt->agility();
    }
    return value;
}

int PlayerEquipment::intelligence() const {
    int value = 0;
    if (helm) {
        value += helm->intelligence();
    }
    if (chest) {
        value += chest->intelligence();
    }
    if (pants) {
        value += pants->intelligence();
    }
    if (gloves) {
        value += gloves->intelligence();
    }
    if (accessories1) {
        value += accessories1->intelligence();
    }
    if (accessories2) {
        value += accessories2->intelligence();
    }
    if (accessories3) {
        value += accessories3->intelligence();
    }
    if (accessories4) {
        value += accessories4->intelligence();
    }
    if (hand1) {
        value += hand1->intelligence();
    }
    if (hand2) {
        value += hand2->intelligence();
    }
    if (boots) {
        value += boots->intelligence();
    }
    if (belt) {
        value += belt->intelligence();
    }
    return value;
}

int PlayerEquipment::stamina() const {
    int value = 0;
    if (helm) {
        value += helm->stamina();
    }
    if (chest) {
        value += chest->stamina();
    }
    if (pants) {
        value += pants->stamina();
    }
    if (gloves) {
        value += gloves->stamina();
    }
    if (accessories1) {
        value += accessories1->stamina();
    }
    if (accessories2) {
        value += accessories2->stamina();
    }
    if (accessories3) {
        value += accessories3->stamina();
    }
    if (accessories4) {
        value += accessories4->stamina();
    }
    if (hand1) {
        value += hand1->stamina();
    }
    if (hand2) {
        value += hand2->stamina();
    }
    if (boots) {
        value += boots->stamina();
    }
    if (belt) {
        value += belt->stamina();
    }
    return value;
}

int PlayerEquipment::closeCombat() const {
    int value = 0;
    if (helm) {
        value += helm->closeCombat();
    }
    if (chest) {
        value += chest->closeCombat();
    }
    if (pants) {
        value += pants->closeCombat();
    }
    if (gloves) {
        value += gloves->closeCombat();
    }
    if (accessories1) {
        value += accessories1->closeCombat();
    }
    if (accessories2) {
        value += accessories2->closeCombat();
    }
    if (accessories3) {
        value += accessories3->closeCombat();
    }
    if (accessories4) {
        value += accessories4->closeCombat();
    }
    if (hand1) {
        value += hand1->closeCombat();
    }
    if (hand2) {
        value += hand2->closeCombat();
    }
    if (boots) {
        value += boots->closeCombat();
    }
    if (belt) {
        value += belt->closeCombat();
    }
    return value;
}

int PlayerEquipment::accuracy() const {
    int value = 0;
    if (helm) {
        value += helm->accuracy();
    }
    if (chest) {
        value += chest->accuracy();
    }
    if (pants) {
        value += pants->accuracy();
    }
    if (gloves) {
        value += gloves->accuracy();
    }
    if (accessories1) {
        value += accessories1->accuracy();
    }
    if (accessories2) {
        value += accessories2->accuracy();
    }
    if (accessories3) {
        value += accessories3->accuracy();
    }
    if (accessories4) {
        value += accessories4->accuracy();
    }
    if (hand1) {
        value += hand1->accuracy();
    }
    if (hand2) {
        value += hand2->accuracy();
    }
    if (boots) {
        value += boots->accuracy();
    }
    if (belt) {
        value += belt->accuracy();
    }
    return value;
}

int PlayerEquipment::movement() const {
    int value = 0;
    if (helm) {
        value += helm->movement();
    }
    if (chest) {
        value += chest->movement();
    }
    if (pants) {
        value += pants->movement();
    }
    if (gloves) {
        value += gloves->movement();
    }
    if (accessories1) {
        value += accessories1->movement();
    }
    if (accessories2) {
        value += accessories2->movement();
    }
    if (accessories3) {
        value += accessories3->movement();
    }
    if (accessories4) {
        value += accessories4->movement();
    }
    if (hand1) {
        value += hand1->movement();
    }
    if (hand2) {
        value += hand2->movement();
    }
    if (boots) {
        value += boots->movement();
    }
    if (belt) {
        value += belt->movement();
    }
    return value;
}

int PlayerEquipment::dodge() const {
    int value = 0;
    if (helm) {
        value += helm->dodge();
    }
    if (chest) {
        value += chest->dodge();
    }
    if (pants) {
        value += pants->dodge();
    }
    if (gloves) {
        value += gloves->dodge();
    }
    if (accessories1) {
        value += accessories1->dodge();
    }
    if (accessories2) {
        value += accessories2->dodge();
    }
    if (accessories3) {
        value += accessories3->dodge();
    }
    if (accessories4) {
        value += accessories4->dodge();
    }
    if (hand1) {
        value += hand1->dodge();
    }
    if (hand2) {
        value += hand2->dodge();
    }
    if (boots) {
        value += boots->dodge();
    }
    if (belt) {
        value += belt->dodge();
    }
    return value;
}
