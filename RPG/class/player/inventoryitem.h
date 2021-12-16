#ifndef INVENTORYITEM_H
#define INVENTORYITEM_H
#include <QMimeData>
#include <QImage>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QDebug>

const int c_pixelsInventoryItem = 29;

enum class InventoryItemType {
    helm,
    chest,
    pants,
    boots,
    gloves,
    belt,
    accessories,
    oneHandedWeapon,
    twoHandedWeapon,
    item
};

QString inventoryItemTypeToString(InventoryItemType type);
InventoryItemType stringToInventoryItemType(QString type);

class InventoryItem {
public:
    InventoryItem();

    bool operator==(const InventoryItem &aItem) const;

    QJsonObject toJson() const;
    void fromJson(const QJsonObject&);

    const QString text();

    int maxHealthPoints() const;
    void setMaxHealthPoints(int maxHealthPoints);

    int maxManaPoints() const;
    void setMaxManaPoints(int maxManaPoints);

    int armor() const;
    void setArmor(int armor);

    int strength() const;
    void setStrength(int strength);

    int agility() const;
    void setAgility(int agility);

    int intelligence() const;
    void setIntelligence(int intelligence);

    int stamina() const;
    void setStamina(int stamina);

    int closeCombat() const;
    void setCloseCombat(int closeCombat);

    int accuracy() const;
    void setAccuracy(int accuracy);

    int movement() const;
    void setMovement(int movement);

    int dodge() const;
    void setDodge(int dodge);

    InventoryItemType type() const;
    void setType(const InventoryItemType &type);

    int width() const;
    void setWidth(int width);

    int height() const;
    void setHeight(int height);

    QImage image() const;
    void setImage(const QImage &image);

    QString name() const;
    void setName(const QString &name);

    friend QDebug operator<<(QDebug dbg, const InventoryItem &a) {
        QStringList list;
        list += "name=" + a.name_;
        list += "(" + QString::number(a.width_) + "," + QString::number(a.height_) + ")";
        if (a.maxHealthPoints_ > 0) {
            list += "maxHP=" + QString::number(a.maxHealthPoints_);
        }
        if (a.maxManaPoints_ > 0) {
            list += "maxMP=" + QString::number(a.maxManaPoints_);
        }
        if (a.armor_ > 0) {
            list += "armor=" + QString::number(a.armor_);
        }
        if (a.strength_ > 0) {
            list += "str=" + QString::number(a.strength_);
        }
        if (a.agility_ > 0) {
            list += "agi=" + QString::number(a.agility_);
        }
        if (a.intelligence_ > 0) {
            list += "int=" + QString::number(a.intelligence_);
        }
        if (a.stamina_ > 0) {
            list += "stmn=" + QString::number(a.stamina_);
        }
        if (a.closeCombat_ > 0) {
            list += "cc=" + QString::number(a.closeCombat_);
        }
        if (a.accuracy_ > 0) {
            list += "acc=" + QString::number(a.accuracy_);
        }
        if (a.movement_ > 0) {
            list += "mov=" + QString::number(a.movement_);
        }
        if (a.dodge_ > 0) {
            list += "dod=" + QString::number(a.dodge_);
        }
        dbg.nospace() << "InventoryItem(name=" << a.name_ << ", " << list.join(",") << ")\n";
        return dbg.space();
    }

private:
    InventoryItemType type_ = InventoryItemType::item;
    int width_;
    int height_;
    QImage image_;

    QString name_;

    int maxHealthPoints_ = 0;
    int maxManaPoints_ = 0;
    int armor_ = 0;

    int strength_ = 0;
    int agility_ = 0;
    int intelligence_ = 0;
    int stamina_ = 0;

    int closeCombat_ = 0;
    int accuracy_ = 0;
    int movement_ = 0;
    int dodge_ = 0;
};

#endif // INVENTORYITEM_H
