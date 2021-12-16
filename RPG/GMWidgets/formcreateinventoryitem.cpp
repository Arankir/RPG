#include "formcreateinventoryitem.h"
#include "ui_formcreateinventoryitem.h"
#include <QFileDialog>
#include <QMessageBox>

QStringList types() {
    return QStringList {inventoryItemTypeToString(InventoryItemType::item),
                        inventoryItemTypeToString(InventoryItemType::helm),
                        inventoryItemTypeToString(InventoryItemType::chest),
                        inventoryItemTypeToString(InventoryItemType::pants),
                        inventoryItemTypeToString(InventoryItemType::boots),
                        inventoryItemTypeToString(InventoryItemType::gloves),
                        inventoryItemTypeToString(InventoryItemType::belt),
                        inventoryItemTypeToString(InventoryItemType::accessories),
                        inventoryItemTypeToString(InventoryItemType::oneHandedWeapon),
                        inventoryItemTypeToString(InventoryItemType::twoHandedWeapon)};
}

FormCreateInventoryItem::FormCreateInventoryItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormCreateInventoryItem)
{
    ui->setupUi(this);

    ui->comboBoxType->addItems(types());
    ui->comboBoxType->setCurrentIndex(0);
}

FormCreateInventoryItem::~FormCreateInventoryItem() {
    delete ui;
}

void FormCreateInventoryItem::on_pushButtonLoadImage_clicked() {
    QString fileName = QFileDialog::getOpenFileName(this, tr("Выберите файл для загрузки"), Paths::desktop(), "*.png");
    if (fileName == "") {
        return;
    }
    image_.load(fileName);
    setImage();
}

void FormCreateInventoryItem::on_pushButtonSave_clicked() {
    if (image_.isNull()) {
        QMessageBox::warning(this, tr("Ошибка!"), tr("Не задана картинка!"));
        return;
    }
    QString fileName = QFileDialog::getSaveFileName(this, tr("Выберите файл для сохранения"), Paths::desktop(), "*.itm");
    if (fileName == "") {
        return;
    }

    InventoryItem item;
    item.setWidth(ui->spinBoxWidth->value());
    item.setHeight(ui->spinBoxHeight->value());
    item.setImage(image_);
    item.setName(ui->lineEditName->text());
    item.setType(stringToInventoryItemType(ui->comboBoxType->currentText()));
    item.setMaxHealthPoints(ui->spinBoxHpMax->value());
    item.setMaxManaPoints(ui->spinBoxMpMax->value());
    item.setArmor(ui->spinBoxArmor->value());
    item.setStrength(ui->spinBoxStrength->value());
    item.setAgility(ui->spinBoxAgility->value());
    item.setIntelligence(ui->spinBoxIntelligence->value());
    item.setStamina(ui->spinBoxStamina->value());
    item.setCloseCombat(ui->spinBoxCloseCombat->value());
    item.setAccuracy(ui->spinBoxAccuracy->value());
    item.setMovement(ui->spinBoxMovement->value());
    item.setDodge(ui->spinBoxDodge->value());

    QFile file(fileName);
    file.open(QFile::WriteOnly);
    file.write(QJsonDocument(item.toJson()).toJson());
    file.close();
}

void FormCreateInventoryItem::setImage() {
    ui->labelImage->setPixmap(QPixmap::fromImage(image_.scaled(ui->spinBoxWidth->value() * c_pixelsInventoryItem,
                                                               ui->spinBoxHeight->value() * c_pixelsInventoryItem)));
}

void FormCreateInventoryItem::on_spinBoxWidth_valueChanged(int arg1) {
    setImage();
}

void FormCreateInventoryItem::on_spinBoxHeight_valueChanged(int arg1) {
    setImage();
}
