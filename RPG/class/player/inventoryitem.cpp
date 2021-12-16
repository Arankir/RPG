#include "inventoryitem.h"
#include <QBuffer>

QString inventoryItemTypeToString(InventoryItemType type) {
    switch (type) {
    case InventoryItemType::helm: {
        return QObject::tr("Шлем");
    }
    case InventoryItemType::chest: {
        return QObject::tr("Нагрудник");
    }
    case InventoryItemType::pants: {
        return QObject::tr("Штаны");
    }
    case InventoryItemType::boots: {
        return QObject::tr("Ботинки");
    }
    case InventoryItemType::gloves: {
        return QObject::tr("Перчатки");
    }
    case InventoryItemType::belt: {
        return QObject::tr("Пояс");
    }
    case InventoryItemType::accessories: {
        return QObject::tr("Аксессуар");
    }
    case InventoryItemType::oneHandedWeapon: {
        return QObject::tr("Одноручное");
    }
    case InventoryItemType::twoHandedWeapon: {
        return QObject::tr("Двуручное");
    }
    case InventoryItemType::item: {
        return QObject::tr("");
    }
    }
}

InventoryItemType stringToInventoryItemType(QString type) {
    if (type == QObject::tr("Шлем")) {
        return InventoryItemType::helm;
    } else if (type == QObject::tr("Нагрудник")) {
        return InventoryItemType::chest;
    } else if (type == QObject::tr("Штаны")) {
        return InventoryItemType::pants;
    } else if (type == QObject::tr("Ботинки")) {
        return InventoryItemType::boots;
    } else if (type == QObject::tr("Перчатки")) {
        return InventoryItemType::gloves;
    } else if (type == QObject::tr("Пояс")) {
        return InventoryItemType::belt;
    } else if (type == QObject::tr("Аксессуар")) {
        return InventoryItemType::accessories;
    } else if (type == QObject::tr("Одноручное")) {
        return InventoryItemType::oneHandedWeapon;
    } else if (type == QObject::tr("Двуручное")) {
        return InventoryItemType::twoHandedWeapon;
    } else  {
        return InventoryItemType::item;
    }
}

InventoryItem::InventoryItem() {

}

bool InventoryItem::operator==(const InventoryItem &aItem) const {
    return this->toJson() == aItem.toJson();
}

QJsonObject InventoryItem::toJson() const {
    QBuffer buffer;
    buffer.open(QIODevice::WriteOnly);
    image_.scaled(width_ * c_pixelsInventoryItem, height_ * c_pixelsInventoryItem).save(&buffer, "PNG");

    QJsonObject obj;
    obj["name"] = name_;
//    obj["image"] = QString::fromUtf8(buffer.data().toBase64());
    obj["type"] = inventoryItemTypeToString(type_);
    obj["width"] = width_;
    obj["height"] = height_;
    obj["maxHealthPoints"] = maxHealthPoints_;
    obj["maxManaPoints"] = maxManaPoints_;
    obj["armor"] = armor_;
    obj["strength"] = strength_;
    obj["agility"] = agility_;
    obj["intelligence"] = intelligence_;
    obj["stamina"] = stamina_;
    obj["closeCombat"] = closeCombat_;
    obj["accuracy"] = accuracy_;
    obj["movement"] = movement_;
    obj["dodge"] = dodge_;
    return obj;
}

void InventoryItem::fromJson(const QJsonObject &aObject) {
    name_ = aObject.value("name").toString();
    image_.loadFromData(QByteArray::fromBase64(aObject.value("image").toString().toUtf8()), "PNG");
    type_ = stringToInventoryItemType(aObject.value("type").toString());
    width_ = aObject.value("width").toInt();
    height_ = aObject.value("height").toInt();
    maxHealthPoints_ = aObject.value("maxHealthPoints").toInt();
    maxManaPoints_ = aObject.value("maxManaPoints").toInt();
    armor_ = aObject.value("armor").toInt();
    strength_ = aObject.value("strength").toInt();
    agility_ = aObject.value("agility").toInt();
    intelligence_ = aObject.value("intelligence").toInt();
    stamina_ = aObject.value("stamina").toInt();
    closeCombat_ = aObject.value("closeCombat").toInt();
    accuracy_ = aObject.value("accuracy").toInt();
    movement_ = aObject.value("movement").toInt();
    dodge_ = aObject.value("dodge").toInt();
}

const QString InventoryItem::text() {
    QString text = name();

    if (!inventoryItemTypeToString(type()).isEmpty()) {
        text += "<br>" + inventoryItemTypeToString(type());
    }

    QStringList list;
    if (maxHealthPoints() > 0) {
        list.append(QObject::tr("Здоровье: <font color=\"#00ff00\">+%1</font>").arg(maxHealthPoints()));
    } else if (maxHealthPoints() < 0) {
        list.append(QObject::tr("Здоровье: <font color=\"#ff0000\">%1</font>").arg(maxHealthPoints()));
    }
    if (maxManaPoints() > 0) {
        list.append(QObject::tr("Мана: <font color=\"#00ff00\">+%1</font>").arg(maxManaPoints()));
    } else if (maxManaPoints() < 0) {
        list.append(QObject::tr("Мана: <font color=\"#ff0000\">%1</font>").arg(maxManaPoints()));
    }
    if (armor() > 0) {
        list.append(QObject::tr("Броня: <font color=\"#00ff00\">+%1</font>").arg(armor()));
    } else if (armor() < 0) {
        list.append(QObject::tr("Броня: <font color=\"#ff0000\">%1</font>").arg(armor()));
    }
    if (strength() > 0) {
        list.append(QObject::tr("Сила: <font color=\"#00ff00\">+%1</font>").arg(strength()));
    } else if (strength() < 0) {
        list.append(QObject::tr("Сила: <font color=\"#ff0000\">%1</font>").arg(strength()));
    }
    if (agility() > 0) {
        list.append(QObject::tr("Ловкость: <font color=\"#00ff00\">+%1</font>").arg(agility()));
    } else if (agility() < 0) {
        list.append(QObject::tr("Ловкость: <font color=\"#ff0000\">%1</font>").arg(agility()));
    }
    if (intelligence() > 0) {
        list.append(QObject::tr("Интеллект: <font color=\"#00ff00\">+%1</font>").arg(intelligence()));
    } else if (intelligence() < 0) {
        list.append(QObject::tr("Интеллект: <font color=\"#ff0000\">%1</font>").arg(intelligence()));
    }
    if (stamina() > 0) {
        list.append(QObject::tr("Выносливость: <font color=\"#00ff00\">+%1</font>").arg(stamina()));
    } else if (stamina() < 0) {
        list.append(QObject::tr("Выносливость: <font color=\"#ff0000\">%1</font>").arg(stamina()));
    }
    if (closeCombat() > 0) {
        list.append(QObject::tr("Ближний бой: <font color=\"#00ff00\">+%1</font>").arg(closeCombat()));
    } else if (closeCombat() < 0) {
        list.append(QObject::tr("Ближний бой: <font color=\"#ff0000\">%1</font>").arg(closeCombat()));
    }
    if (accuracy() > 0) {
        list.append(QObject::tr("Точность: <font color=\"#00ff00\">+%1</font>").arg(accuracy()));
    } else if (accuracy() < 0) {
        list.append(QObject::tr("Точность: <font color=\"#ff0000\">%1</font>").arg(accuracy()));
    }
    if (movement() > 0) {
        list.append(QObject::tr("Движение: <font color=\"#00ff00\">+%1</font>").arg(movement()));
    } else if (movement() < 0) {
        list.append(QObject::tr("Движение: <font color=\"#ff0000\">%1</font>").arg(movement()));
    }
    if (dodge() > 0) {
        list.append(QObject::tr("Уклонение: <font color=\"#00ff00\">+%1</font>").arg(dodge()));
    } else if (dodge() < 0) {
        list.append(QObject::tr("Уклонение: <font color=\"#ff0000\">%1</font>").arg(dodge()));
    }

    if (list.size() > 0) {
        text += "<br><br>" + list.join("<br>");
    }
    return text;
}

int InventoryItem::maxHealthPoints() const {
    return maxHealthPoints_;
}

void InventoryItem::setMaxHealthPoints(int maxHealthPoints) {
    maxHealthPoints_ = maxHealthPoints;
}

int InventoryItem::maxManaPoints() const {
    return maxManaPoints_;
}

void InventoryItem::setMaxManaPoints(int maxManaPoints) {
    maxManaPoints_ = maxManaPoints;
}

int InventoryItem::armor() const {
    return armor_;
}

void InventoryItem::setArmor(int armor) {
    armor_ = armor;
}

int InventoryItem::strength() const {
    return strength_;
}

void InventoryItem::setStrength(int strength) {
    strength_ = strength;
}

int InventoryItem::agility() const {
    return agility_;
}

void InventoryItem::setAgility(int agility) {
    agility_ = agility;
}

int InventoryItem::intelligence() const {
    return intelligence_;
}

void InventoryItem::setIntelligence(int intelligence) {
    intelligence_ = intelligence;
}

int InventoryItem::stamina() const {
    return stamina_;
}

void InventoryItem::setStamina(int stamina) {
    stamina_ = stamina;
}

int InventoryItem::closeCombat() const {
    return closeCombat_;
}

void InventoryItem::setCloseCombat(int closeCombat) {
    closeCombat_ = closeCombat;
}

int InventoryItem::accuracy() const {
    return accuracy_;
}

void InventoryItem::setAccuracy(int accuracy) {
    accuracy_ = accuracy;
}

int InventoryItem::movement() const {
    return movement_;
}

void InventoryItem::setMovement(int movement) {
    movement_ = movement;
}

int InventoryItem::dodge() const {
    return dodge_;
}

void InventoryItem::setDodge(int dodge) {
    dodge_ = dodge;
}

InventoryItemType InventoryItem::type() const {
    return type_;
}

void InventoryItem::setType(const InventoryItemType &type) {
    type_ = type;
}

int InventoryItem::width() const {
    return width_;
}

void InventoryItem::setWidth(int width) {
    width_ = width;
}

int InventoryItem::height() const {
    return height_;
}

void InventoryItem::setHeight(int height) {
    height_ = height;
}

QImage InventoryItem::image() const {
    return image_;
}

void InventoryItem::setImage(const QImage &image) {
    image_ = image;
}

QString InventoryItem::name() const {
    return name_;
}

void InventoryItem::setName(const QString &name) {
    name_ = name;
}
