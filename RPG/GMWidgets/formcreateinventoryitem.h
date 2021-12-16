#ifndef FORMCREATEINVENTORYITEM_H
#define FORMCREATEINVENTORYITEM_H

#include <QWidget>
#include "class/structs.h"
#include "class/settings.h"
#include "class/player/inventoryitem.h"

namespace Ui {
class FormCreateInventoryItem;
}

class FormCreateInventoryItem : public QWidget {
    Q_OBJECT

public:
    explicit FormCreateInventoryItem(QWidget *parent = nullptr);
    ~FormCreateInventoryItem();

private slots:
    void on_pushButtonLoadImage_clicked();

    void on_pushButtonSave_clicked();

    void on_spinBoxWidth_valueChanged(int arg1);

    void on_spinBoxHeight_valueChanged(int arg1);

private:
    Ui::FormCreateInventoryItem *ui;
    QImage image_;

    void setImage();
};

#endif // FORMCREATEINVENTORYITEM_H
