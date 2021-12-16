#include "formplayerinventory.h"
#include "ui_formplayerinventory.h"
#include <QPainter>
#include <QFileDialog>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMessageBox>

FormPlayerInventory::FormPlayerInventory(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormPlayerInventory) {
    ui->setupUi(this);
}

void FormPlayerInventory::paintEvent(QPaintEvent *e) {
    QPainter painter(this);
    painter.drawPixmap(0, 0, QPixmap("://backgrounds/playerInventory.png").scaled(size()));
    QWidget::paintEvent(e);
}

FormPlayerInventory::~FormPlayerInventory() {
    delete ui;
}

void FormPlayerInventory::init(GameUserType aType, const Player &aPlayer) {
    type_ = aType;
    player_ = aPlayer;
    switch (type_) {
    case GameUserType::client: {

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

void FormPlayerInventory::playerToUi() {
    PlayerEquipment *pi = player_.equipment();
    if (InventoryItem *item = pi->helm) {
        ui->labelHelm->setPixmap(QPixmap::fromImage(item->image().scaled(item->width() * c_pixelsInventoryItem, item->height() * c_pixelsInventoryItem)));
        ui->labelHelm->setToolTip(item->text());
    }
    if (InventoryItem *item = pi->chest) {
        ui->labelChest->setPixmap(QPixmap::fromImage(item->image().scaled(item->width() * c_pixelsInventoryItem, item->height() * c_pixelsInventoryItem)));
        ui->labelChest->setToolTip(item->text());
    }
    if (InventoryItem *item = pi->gloves) {
        ui->labelGloves->setPixmap(QPixmap::fromImage(item->image().scaled(item->width() * c_pixelsInventoryItem, item->height() * c_pixelsInventoryItem)));
        ui->labelGloves->setToolTip(item->text());
    }
    if (InventoryItem *item = pi->pants) {
        ui->labelPants->setPixmap(QPixmap::fromImage(item->image().scaled(item->width() * c_pixelsInventoryItem, item->height() * c_pixelsInventoryItem)));
        ui->labelPants->setToolTip(item->text());
    }
    if (InventoryItem *item = pi->boots) {
        ui->labelBoots->setPixmap(QPixmap::fromImage(item->image().scaled(item->width() * c_pixelsInventoryItem, item->height() * c_pixelsInventoryItem)));
        ui->labelBoots->setToolTip(item->text());
    }
    if (InventoryItem *item = pi->belt) {
        ui->labelBelt->setPixmap(QPixmap::fromImage(item->image().scaled(item->width() * c_pixelsInventoryItem, item->height() * c_pixelsInventoryItem)));
        ui->labelBelt->setToolTip(item->text());
    }
    if (InventoryItem *item = pi->hand1) {
        ui->labelHand1->setPixmap(QPixmap::fromImage(item->image().scaled(item->width() * c_pixelsInventoryItem, item->height() * c_pixelsInventoryItem)));
        ui->labelHand1->setToolTip(item->text());
    }
    if (InventoryItem *item = pi->hand2) {
        ui->labelHand2->setPixmap(QPixmap::fromImage(item->image().scaled(item->width() * c_pixelsInventoryItem, item->height() * c_pixelsInventoryItem)));
        ui->labelHand2->setToolTip(item->text());
    }
    if (InventoryItem *item = pi->accessories1) {
        ui->labelAccessories1->setPixmap(QPixmap::fromImage(item->image().scaled(item->width() * c_pixelsInventoryItem, item->height() * c_pixelsInventoryItem)));
        ui->labelAccessories1->setToolTip(item->text());
    }
    if (InventoryItem *item = pi->accessories2) {
        ui->labelAccessories2->setPixmap(QPixmap::fromImage(item->image().scaled(item->width() * c_pixelsInventoryItem, item->height() * c_pixelsInventoryItem)));
        ui->labelAccessories2->setToolTip(item->text());
    }
    if (InventoryItem *item = pi->accessories3) {
        ui->labelAccessories3->setPixmap(QPixmap::fromImage(item->image().scaled(item->width() * c_pixelsInventoryItem, item->height() * c_pixelsInventoryItem)));
        ui->labelAccessories3->setToolTip(item->text());
    }
    if (InventoryItem *item = pi->accessories4) {
        ui->labelAccessories4->setPixmap(QPixmap::fromImage(item->image().scaled(item->width() * c_pixelsInventoryItem, item->height() * c_pixelsInventoryItem)));
        ui->labelAccessories4->setToolTip(item->text());
    }
}
