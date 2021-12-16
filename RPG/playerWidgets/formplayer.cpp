#include "formplayer.h"
#include "ui_formplayer.h"
#include <QFileDialog>
#include <QMessageBox>

FormPlayer::FormPlayer(QWidget *parent) :
QWidget(parent),
ui(new Ui::FormPlayer) {
    ui->setupUi(this);
    connect(ui->stats, &FormPlayerStats::s_playerStatsChanged, this, &FormPlayer::s_playerStatsChanged);
    connect(ui->bag, &FormInventoryBag::s_itemEquiped, this, [&](InventoryItem *lItem) {
        qDebug() << "equip";
        ui->inventory->playerToUi();
    });
}

FormPlayer::~FormPlayer() {
    delete ui;
}

void FormPlayer::init(GameUserType aType, const Player &aPlayer) {
    player_ = aPlayer;
    type_ = aType;
    this->setWindowTitle(player_.nickName());
    ui->stats->init(type_, player_);
    ui->inventory->init(type_, player_);
    ui->bag->init(type_, player_);
    if (type_ != GameUserType::server) {
        ui->pushButtonAddItem->setVisible(false);
    }
}

void FormPlayer::on_pushButtonAddItem_clicked() {
    if (type_ == GameUserType::server) {
        QString fileName = QFileDialog::getOpenFileName(this, tr("Выберите файл с предметом"), Paths::desktop(), "*.itm");
        if (fileName == "") {
            return;
        }

        QFile file(fileName);
        file.open(QFile::ReadOnly);
        InventoryItem *item = new InventoryItem();
        item->fromJson(QJsonDocument::fromJson(file.readAll()).object());
        file.close();

        if (!ui->bag->addItem(item)) {
            QMessageBox::warning(this, tr("Ошибка!"), tr("Не удалось добавить предмет!"));
        }
    }
}
