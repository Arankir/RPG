#include "player.h"
#include <QBuffer>
#include <QDebug>

int newIndex() {
    static int index = 0;
    return ++index;
}

Player::Player():
equipment_(new PlayerEquipment),
inventory_(new PlayerInventory),
index_(newIndex()) {
    equipment_->helm = new InventoryItem();
    equipment_->helm->setImage(QImage("://backgrounds/game.png"));
    equipment_->helm->setWidth(2);
    equipment_->helm->setHeight(2);
    equipment_->helm->setName("Кожаный шлем");
    equipment_->helm->setType(InventoryItemType::helm);
    equipment_->helm->setStamina(5);
}

Player::Player(const QJsonObject &aObject):
equipment_(new PlayerEquipment),
inventory_(new PlayerInventory),
index_(newIndex()) {
    fromJson(aObject);
}

Player::Player(const Player &player) {
    nickName_ = player.nickName_;
    avatar_ = player.avatar_;
    healthPoints_ = player.healthPoints_;
    maxHealthPoints_ = player.maxHealthPoints_;
    manaPoints_ = player.manaPoints_;
    maxManaPoints_ = player.maxManaPoints_;
    level_ = player.level_;
    exp_ = player.exp_;
    armor_ = player.armor_;
    strength_ = player.strength_;
    agility_ = player.agility_;
    intelligence_ = player.intelligence_;
    stamina_ = player.stamina_;
    closeCombat_ = player.closeCombat_;
    accuracy_ = player.accuracy_;
    movement_ = player.movement_;
    dodge_ = player.dodge_;
    equipment_ = player.equipment_;
    inventory_ = player.inventory_;
    index_ = player.index_;
}

QJsonObject Player::toJson() {
    QBuffer buffer;
    buffer.open(QIODevice::WriteOnly);
    avatar_.save(&buffer, "PNG");

    QJsonObject obj;
    obj["nickName"] = nickName_;
    obj["avatar"] = QString::fromUtf8(buffer.data().toBase64());
    obj["level"] = level_;
    obj["exp"] = exp_;
    obj["healthPoints"] = healthPoints_;
    obj["maxHealthPoints"] = maxHealthPoints_;
    obj["manaPoints"] = manaPoints_;
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
    obj["equipment"] = equipment_->toJson();
    obj["inventory"] = inventory_->toJson();
    return obj;
}

void Player::fromJson(const QJsonObject &aObject) {
    nickName_ = aObject.value("nickName").toString();
    avatar_.loadFromData(QByteArray::fromBase64(aObject.value("avatar").toString().toUtf8()), "PNG");
    healthPoints_ = aObject.value("healthPoints").toInt();
    maxHealthPoints_ = aObject.value("maxHealthPoints").toInt();
    manaPoints_ = aObject.value("manaPoints").toInt();
    maxManaPoints_ = aObject.value("maxManaPoints").toInt();
    level_ = aObject.value("level").toInt();
    exp_ = aObject.value("exp").toInt();
    armor_ = aObject.value("armor").toInt();
    strength_ = aObject.value("strength").toInt();
    agility_ = aObject.value("agility").toInt();
    intelligence_ = aObject.value("intelligence").toInt();
    stamina_ = aObject.value("stamina").toInt();
    closeCombat_ = aObject.value("closeCombat").toInt();
    accuracy_ = aObject.value("accuracy").toInt();
    movement_ = aObject.value("movement").toInt();
    dodge_ = aObject.value("dodge").toInt();
    equipment_->fromJson(aObject.value("equipment").toObject());
    inventory_->fromJson(aObject.value("inventory").toObject());
}

QString Player::nickName() const {
    return nickName_;
}

void Player::setNickName(const QString &nickName) {
    nickName_ = nickName;
}

int Player::healthPoints() const {
    return healthPoints_;
}

void Player::setHealthPoints(int healthPoints) {
    healthPoints_ = healthPoints;
}

int Player::maxHealthPoints() const {
    return maxHealthPoints_ + strength_ + equipment_->maxHealthPoints();
}

void Player::setMaxHealthPoints(int maxHealthPoints) {
    maxHealthPoints_ = maxHealthPoints;
}

int Player::baseMaxHealthPoints() const {
    return maxHealthPoints_;
}

int Player::manaPoints() const {
    return manaPoints_;
}

void Player::setManaPoints(int manaPoints) {
    manaPoints_ = manaPoints;
}

int Player::baseMaxManaPoints() const {
    return maxManaPoints_;
}

int Player::maxManaPoints() const {
    return maxManaPoints_ + intelligence_ + equipment_->maxManaPoints();
}

void Player::setMaxManaPoints(int maxManaPoints) {
    maxManaPoints_ = maxManaPoints;
}

int Player::getIndex() const {
    return index_;
}

int Player::level() const {
    return level_ + (exp() / c_expPerLevel);
}

void Player::setLevel(int level) {
    level_ = level;
}

int Player::baseLevel() const {
    return level_;
}

QImage Player::avatar() const {
    return avatar_;
}

void Player::setAvatar(const QImage &avatar) {
    avatar_ = avatar;
}

int Player::armor() const {
    return armor_ + equipment_->armor();
}

void Player::setArmor(int armor) {
    armor_ = armor;
}

int Player::baseArmor() const {
    return armor_;
}

int Player::strength() const {
    return strength_ + strengthPoints() + equipment_->strength();
}

void Player::setStrength(int strength) {
    strength_ = strength;
}

int Player::baseStrength() const {
    return strength_;
}

int Player::agility() const {
    return agility_ + agilityPoints() + equipment_->agility();
}

void Player::setAgility(int agility) {
    agility_ = agility;
}

int Player::baseAgility() const {
    return agility_;
}

int Player::intelligence() const {
    return intelligence_ + intelligencePoints() + equipment_->intelligence();
}

void Player::setIntelligence(int intelligence) {
    intelligence_ = intelligence;
}

int Player::baseIntelligence() const {
    return intelligence_;
}

int Player::stamina() const {
    return stamina_ + staminaPoints() + equipment_->stamina();
}

void Player::setStamina(int stamina) {
    stamina_ = stamina;
}

int Player::baseStamina() const {
    return stamina_;
}

int Player::closeCombat() const {
    return closeCombat_ + strength_ + equipment_->closeCombat();
}

void Player::setCloseCombat(int closeCombat) {
    closeCombat_ = closeCombat;
}

int Player::baseCloseCombat() const {
    return closeCombat_;
}

int Player::accuracy() const {
    return accuracy_ + agility_ + equipment_->accuracy();
}

void Player::setAccuracy(int accuracy) {
    accuracy_ = accuracy;
}

int Player::baseAccuracy() const {
    return accuracy_;
}

int Player::movement() const {
    return movement_ + stamina_ + equipment_->movement();
}

void Player::setMovement(int movement) {
    movement_ = movement;
}

int Player::baseMovement() const {
    return movement_;
}

int Player::dodge() const {
    return dodge_ + agility_ + equipment_->dodge();
}

void Player::setDodge(int dodge) {
    dodge_ = dodge;
}

int Player::baseDodge() const {
    return dodge_;
}

int Player::undistributedPoints() const {
    return undistributedPointsGmAdded() + (level() * c_pointsPerLevel) - distributedPoints();
}

int Player::distributedPoints() const {
    return strengthPoints() + agilityPoints() + intelligencePoints() + staminaPoints();
}

int Player::strengthPoints() const {
    return strengthPoints_;
}

void Player::setStrengthPoints(int strengthPoints) {
    strengthPoints_ = strengthPoints;
}

int Player::agilityPoints() const {
    return agilityPoints_;
}

void Player::setAgilityPoints(int agilityPoints) {
    agilityPoints_ = agilityPoints;
}

int Player::intelligencePoints() const {
    return intelligencePoints_;
}

void Player::setIntelligencePoints(int intelligencePoints) {
    intelligencePoints_ = intelligencePoints;
}

int Player::staminaPoints() const {
    return staminaPoints_;
}

void Player::setStaminaPoints(int staminaPoints) {
    staminaPoints_ = staminaPoints;
}

PlayerEquipment *Player::equipment() const {
    return equipment_;
}

PlayerInventory *Player::inventory() const {
    return inventory_;
}

int Player::undistributedPointsGmAdded() const {
    return undistributedPointsGmAdded_;
}

void Player::setUndistributedPointsGmAdded(int undistributedPointsGmAdded) {
    undistributedPointsGmAdded_ = undistributedPointsGmAdded;
}

int Player::exp() const {
    return exp_;
}

void Player::setExp(int exp) {
    exp_ = exp;
}
