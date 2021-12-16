#include "formplayerstats.h"
#include "ui_formplayerstats.h"
#include <QFileDialog>
#include "class/settings.h"

const QColor c_increasedStat = QColor(0, 255, 0);
const QColor c_standartStat  = QColor(0, 0, 0);
const QColor c_decreasedStat = QColor(255, 0, 0);
const QSize c_avatarSize = QSize(32, 32);

FormPlayerStats::FormPlayerStats(QWidget *parent) :
QWidget(parent),
ui(new Ui::FormPlayerStats),
type_(GameUserType::unknown),
player_() {
    ui->setupUi(this);
}

FormPlayerStats::~FormPlayerStats() {
    delete ui;
}

void FormPlayerStats::init(GameUserType aType, const Player &aPlayer) {
    type_ = aType;
    player_ = aPlayer;
    switch (type_) {
    case GameUserType::client: {
        ui->spinBoxLvl->setVisible(false);
        ui->spinBoxExp->setVisible(false);
        ui->spinBoxArmor->setVisible(false);
        ui->spinBoxStrength->setVisible(false);
        ui->spinBoxAgility->setVisible(false);
        ui->spinBoxIntelligence->setVisible(false);
        ui->spinBoxStamina->setVisible(false);
        ui->spinBoxCloseCombat->setVisible(false);
        ui->spinBoxAccuracy->setVisible(false);
        ui->spinBoxMovement->setVisible(false);
        ui->spinBoxDodge->setVisible(false);

        ui->labelHPSlashGM->setVisible(false);
        ui->labelMPSlashGM->setVisible(false);

        ui->spinBoxHpNow->setVisible(false);
        ui->spinBoxHpMax->setVisible(false);
        ui->spinBoxMpNow->setVisible(false);
        ui->spinBoxMpMax->setVisible(false);

        ui->pushButtonApply->setVisible(false);
        ui->pushButtonLoadAvatar->setVisible(false);
        ui->spinBoxPoints->setVisible(false);
        break;
    }
    case GameUserType::server: {
        break;
    }
    default: {

    }
    }

    playerToUi();
}

bool FormPlayerStats::isInit() {
    return type_ != GameUserType::unknown && player_.nickName() != "";
}

void FormPlayerStats::playerToUi() {
    if (isInit()) {
        ui->labelAvatar->setPixmap(QPixmap::fromImage(player_.avatar()));

        ui->labelStatHP->setText(QString("%1/%2").arg(QString::number(player_.healthPoints()),
                                                      QString::number(player_.maxHealthPoints())));
        ui->spinBoxHpNow->setValue(player_.healthPoints());
        ui->spinBoxHpMax->setValue(player_.baseMaxHealthPoints());

        ui->labelStatMP->setText(QString("%1/%2").arg(QString::number(player_.manaPoints()),
                                                      QString::number(player_.maxManaPoints())));
        ui->spinBoxMpNow->setValue(player_.manaPoints());
        ui->spinBoxMpMax->setValue(player_.baseMaxManaPoints());

        ui->labelStatLvl->setText(QString::number(player_.level()));
        ui->spinBoxLvl->setValue(player_.baseLevel());

        ui->labelStatExp->setText(QString::number(player_.exp()));
        ui->labelStatExp->setToolTip(QString::number(player_.exp()));
        ui->spinBoxExp->setValue(player_.exp());

        ui->labelStatArmor->setText(QString::number(player_.armor()));
        ui->spinBoxArmor->setValue(player_.baseArmor());

        ui->labelStatStrength->setText(QString::number(player_.strength()));
        ui->spinBoxStrength->setValue(player_.baseStrength());

        ui->labelStatAgility->setText(QString::number(player_.agility()));
        ui->spinBoxAgility->setValue(player_.baseAgility());

        ui->labelStatIntelligence->setText(QString::number(player_.intelligence()));
        ui->spinBoxIntelligence->setValue(player_.baseIntelligence());

        ui->labelStatStamina->setText(QString::number(player_.stamina()));
        ui->spinBoxStamina->setValue(player_.baseStamina());

        ui->labelStatCloseCombat->setText(QString::number(player_.closeCombat()));
        ui->spinBoxCloseCombat->setValue(player_.baseCloseCombat());

        ui->labelStatAccuracy->setText(QString::number(player_.accuracy()));
        ui->spinBoxAccuracy->setValue(player_.baseAccuracy());

        ui->labelStatMovement->setText(QString::number(player_.movement()));
        ui->spinBoxMovement->setValue(player_.baseMovement());

        ui->labelStatDodge->setText(QString::number(player_.dodge()));
        ui->spinBoxDodge->setValue(player_.baseDodge());

        ui->labelStatPoints->setText(QString::number(player_.undistributedPoints()));
        ui->spinBoxPoints->setValue(player_.undistributedPointsGmAdded());

        bool enablePoints = player_.undistributedPoints() > 0;
        ui->pushButtonAddAgility->setVisible(enablePoints);
        ui->pushButtonAddStamina->setVisible(enablePoints);
        ui->pushButtonAddStrength->setVisible(enablePoints);
        ui->pushButtonAddIntelegence->setVisible(enablePoints);
    }
}

void FormPlayerStats::uiToPlayer() {
    if (isInit()) {
        player_.setMaxHealthPoints(ui->spinBoxHpMax->value());
        player_.setHealthPoints(ui->spinBoxHpNow->value());
        player_.setMaxManaPoints(ui->spinBoxMpMax->value());
        player_.setManaPoints(ui->spinBoxMpNow->value());
        player_.setLevel(ui->spinBoxLvl->value());
        player_.setExp(ui->spinBoxExp->value());
        player_.setArmor(ui->spinBoxArmor->value());
        player_.setStrength(ui->spinBoxStrength->value());
        player_.setAgility(ui->spinBoxAgility->value());
        player_.setIntelligence(ui->spinBoxIntelligence->value());
        player_.setStamina(ui->spinBoxStamina->value());
        player_.setCloseCombat(ui->spinBoxCloseCombat->value());
        player_.setAccuracy(ui->spinBoxAccuracy->value());
        player_.setMovement(ui->spinBoxMovement->value());
        player_.setDodge(ui->spinBoxDodge->value());
        player_.setUndistributedPointsGmAdded(ui->spinBoxPoints->value());
    }
}

Player FormPlayerStats::getPlayer() {
    return player_;
}

void FormPlayerStats::setPlayer(const Player &aPlayer) {
    player_ = aPlayer;
}

void FormPlayerStats::on_pushButtonApply_clicked() {
    if (type_ == GameUserType::server) {
        uiToPlayer();
        emit s_playerStatsChanged(player_);
        playerToUi();
    }
}

void FormPlayerStats::on_pushButtonLoadAvatar_clicked() {
    QString fileName = QFileDialog::getOpenFileName(this,tr("Выберите файл для загрузки"), Paths::desktop(), "*.png");
    if (fileName == "") {
        return;
    }
    QImage avatar;
    avatar.load(fileName);
    avatar = avatar.scaled(c_avatarSize);
    player_.setAvatar(avatar);
    ui->labelAvatar->setPixmap(QPixmap::fromImage(player_.avatar()));
}

void FormPlayerStats::on_pushButtonAddStrength_clicked() {
    player_.setStrengthPoints(player_.strengthPoints() + 1);
    playerToUi();
}

void FormPlayerStats::on_pushButtonAddAgility_clicked() {
    player_.setAgilityPoints(player_.agilityPoints() + 1);
    playerToUi();
}

void FormPlayerStats::on_pushButtonAddIntelegence_clicked() {
    player_.setIntelligencePoints(player_.intelligencePoints() + 1);
    playerToUi();
}

void FormPlayerStats::on_pushButtonAddStamina_clicked() {
    player_.setStaminaPoints(player_.staminaPoints() + 1);
    playerToUi();
}
