#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QJsonObject>
#include <QJsonArray>
#include <QImage>
#include "class/player/playerequipment.h"
#include "class/player/playerinventory.h"

const int c_expPerLevel = 1000;
const int c_pointsPerLevel = 4;

class Player {
public:
    explicit Player();
    explicit Player(const QJsonObject&);
    Player(const Player &player);

    QImage avatar() const;
    void setAvatar(const QImage &avatar);

    QString nickName() const;
    void setNickName(const QString &nickName);

    int exp() const;
    void setExp(int exp);

    int healthPoints() const;
    void setHealthPoints(int healthPoints);

    int manaPoints() const;
    void setManaPoints(int manaPoints);

    QJsonObject toJson();
    void fromJson(const QJsonObject&);

    int getIndex() const;

    int level() const;
    void setLevel(int level);
    int baseLevel() const;

    int maxHealthPoints() const;
    void setMaxHealthPoints(int maxHealthPoints);
    int baseMaxHealthPoints() const;

    int maxManaPoints() const;
    void setMaxManaPoints(int maxManaPoints);
    int baseMaxManaPoints() const;

    int armor() const;
    void setArmor(int armor);
    int baseArmor() const;

    int strength() const;
    void setStrength(int strength);
    int baseStrength() const;

    int agility() const;
    void setAgility(int agility);
    int baseAgility() const;

    int intelligence() const;
    void setIntelligence(int intelligence);
    int baseIntelligence() const;

    int stamina() const;
    void setStamina(int stamina);
    int baseStamina() const;

    int closeCombat() const;
    void setCloseCombat(int closeCombat);
    int baseCloseCombat() const;

    int accuracy() const;
    void setAccuracy(int accuracy);
    int baseAccuracy() const;

    int movement() const;
    void setMovement(int movement);
    int baseMovement() const;

    int dodge() const;
    void setDodge(int dodge);
    int baseDodge() const;

    int distributedPoints() const;
    int undistributedPoints() const;

    int undistributedPointsGmAdded() const;
    void setUndistributedPointsGmAdded(int undistributedPointsGmAdded);

    int strengthPoints() const;
    void setStrengthPoints(int strengthPoints);
    int agilityPoints() const;
    void setAgilityPoints(int agilityPoints);
    int intelligencePoints() const;
    void setIntelligencePoints(int intelligencePoints);
    int staminaPoints() const;
    void setStaminaPoints(int staminaPoints);

    PlayerEquipment *equipment() const;

    PlayerInventory *inventory() const;

private:
    QString nickName_;
    int level_ = 1;
    int exp_ = 0;
    QImage avatar_;
    int healthPoints_ = 3;
    int maxHealthPoints_ = 3;
    int manaPoints_ = 1;
    int maxManaPoints_ = 1;
    int armor_ = 0;

    int strength_ = 1;
    int agility_ = 1;
    int intelligence_ = 1;
    int stamina_ = 1;

    int closeCombat_ = 1;
    int accuracy_ = 1;
    int movement_ = 1;
    int dodge_ = 1;

    int undistributedPointsGmAdded_ = 0;
    int strengthPoints_ = 0;
    int agilityPoints_ = 0;
    int intelligencePoints_ = 0;
    int staminaPoints_ = 0;

    PlayerEquipment *equipment_;
    PlayerInventory *inventory_;

   //лвл, аватарка с компа ГМ, броня, есть базовые, есть вычисляемые
//    Ближний бой:       4+  3+  2+
//    Меткость:          4+  3+  2+
//    Движение:          4+  3+  2+
//    Уклонение:         4+  3+  2+

//    Здоровье:        2-3 4-5 6-7
//    Мана:            4-5 6-7 7-8

//    Сила.           1-2. 3-4. 5-6.
//    Ловкость.       1-2. 3-4. 5-6.
//    Интелект.       1-2. 3-4. 5-6.
//    Выносливость.   1-2. 3-4. 5-6.

    int index_;
};

#endif // PLAYER_H
