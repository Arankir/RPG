#include "formplayerminiature.h"
#include "ui_formplayerminiature.h"

FormPlayerMiniature::FormPlayerMiniature(GameUserType type, Player &aPlayer, QWidget *parent) :
QWidget(parent),
ui(new Ui::FormPlayerMiniature),
type_(type),
player_(aPlayer) {
    ui->setupUi(this);
    if (type_ == GameUserType::client) {
        ui->pushButtonKick->setVisible(false);
    }
    playerToUi();
}

FormPlayerMiniature::~FormPlayerMiniature() {
    delete ui;
}

void FormPlayerMiniature::playerToUi() {
    ui->labelAvatar->setPixmap(QPixmap::fromImage(player_.avatar()));
    ui->labelNick->setText(player_.nickName());
    ui->progressBarHp->setMaximum(player_.maxHealthPoints());
    ui->progressBarHp->setValue(player_.healthPoints());
    ui->progressBarMp->setMaximum(player_.maxManaPoints());
    ui->progressBarMp->setValue(player_.manaPoints());
    ui->progressBarExp->setValue(player_.exp() % 1000);
}

void FormPlayerMiniature::setPlayer(const Player &aPlayer) {
    player_ = aPlayer;
}

Player FormPlayerMiniature::getPlayer() {
    return player_;
}

void FormPlayerMiniature::on_pushButtonKick_clicked() {
    emit s_kick(player_);
}
