#include "forminventorybag.h"
#include "ui_forminventorybag.h"
#include <QDebug>
#include <QStandardItem>
#include <QMenu>
#include <QAction>
#include <QMessageBox>

FormInventoryBag::FormInventoryBag(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormInventoryBag)
{
    ui->setupUi(this);
    QGraphicsScene *scene = new QGraphicsScene(0, 0,
                                               c_cellsBagWidth * c_pixelsInventoryItem,
                                               c_cellsBagHeight * c_pixelsInventoryItem, this);
//    scene->setItemIndexMethod(QGraphicsScene::NoIndex);

    this->setMinimumSize(c_cellsBagWidth * c_pixelsInventoryItem,
                         c_cellsBagHeight * c_pixelsInventoryItem);
    this->setMaximumSize(c_cellsBagWidth * c_pixelsInventoryItem,
                         c_cellsBagHeight * c_pixelsInventoryItem);

    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
//    ui->graphicsView->setCacheMode(QGraphicsView::CacheBackground);
//    ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
//    QPixmap pim("://backgrounds/playerInventory.png");
//    scene->setBackgroundBrush(pim.scaled(scene->width(), scene->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    ui->graphicsView->setBackgroundBrush(QColor(220, 130, 100));

//    InventoryItem *item = new InventoryItem();
//    item->setImage(QImage("://backgrounds/game.png"));
//    item->setWidth(2);
//    item->setHeight(2);
//    item->setName("Кожаный шлем");
//    item->setType(InventoryItemType::helm);
//    item->setStamina(5);

//    InventoryItem *item2 = new InventoryItem();
//    item2->setImage(QImage("://backgrounds/game.png"));
//    item2->setWidth(4);
//    item2->setHeight(2);
//    item2->setName("Пояс сосания хуёв");
//    item2->setType(InventoryItemType::belt);
//    item2->setArmor(4);

//    InventoryItem *item3 = new InventoryItem();
//    item3->setImage(QImage("://backgrounds/game.png"));
//    item3->setWidth(5);
//    item3->setHeight(5);
//    item3->setName("Дилдак всевластия");
//    item3->setType(InventoryItemType::twoHandedWeapon);
//    item3->setDodge(1);
//    item3->setAgility(-5);
//    item3->setAccuracy(2);

//    addItem(item);
//    addItem(item3);
//    addItem(item2);

}

FormInventoryBag::~FormInventoryBag() {
    delete ui;
}

void FormInventoryBag::init(GameUserType aType, const Player &aPlayer) {
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

void FormInventoryBag::playerToUi() {
    auto scene = ui->graphicsView->scene();

    scene->clear();

    for (int i = 0; i <= c_cellsBagWidth; ++i) {
        scene->addLine(QLineF(0, i * c_pixelsInventoryItem,
                              c_cellsBagHeight * c_pixelsInventoryItem, i * c_pixelsInventoryItem));
    }
    for (int j = 0; j <= c_cellsBagHeight; ++j) {
        scene->addLine(QLineF(j * c_pixelsInventoryItem, 0,
                              j * c_pixelsInventoryItem, c_cellsBagWidth * c_pixelsInventoryItem));
    }

    PlayerInventory *pi = player_.inventory();
    for (auto item: pi->items) {
        addItem(item.first, item.second);
    }

}

void FormInventoryBag::createMenu(QPointF pos, InventoryItemVisual *graphicItem, InventoryItem *item) {
    QMenu *menu = new QMenu();
    QAction *equip = new QAction(tr("Экипировать"));
    QAction *drop = new QAction(tr("Выкинуть"));
    QAction *give = new QAction(tr("Передать"));

//    qDebug() << item->toJson();
    qDebug() << "rcm" << item->name();

    connect(equip, &QAction::triggered, this, [=](bool) {
        switch (item->type()) {
        case InventoryItemType::helm: {
            if (player_.equipment()->helm) {
                if (player_.inventory()->addItem(player_.equipment()->helm)) {
                    player_.equipment()->helm = player_.inventory()->takeItem(item);
                    emit s_itemEquiped(item);
                    playerToUi();
                } else {
                    QMessageBox::warning(this, tr("Ошибка!"), tr("Недостаточно места в инвентаре!"));
                }
            } else {
                player_.equipment()->helm = player_.inventory()->takeItem(item);
                emit s_itemEquiped(item);
                playerToUi();
            }
            break;
        }
        case InventoryItemType::chest: {
            if (player_.equipment()->chest) {
                if (player_.inventory()->addItem(player_.equipment()->chest)) {
                    player_.equipment()->chest = player_.inventory()->takeItem(item);
                    emit s_itemEquiped(item);
                    playerToUi();
                } else {
                    QMessageBox::warning(this, tr("Ошибка!"), tr("Недостаточно места в инвентаре!"));
                }
            } else {
                player_.equipment()->chest = player_.inventory()->takeItem(item);
                emit s_itemEquiped(item);
                playerToUi();
            }
            break;
        }
        case InventoryItemType::pants: {
            if (player_.equipment()->pants) {
                if (player_.inventory()->addItem(player_.equipment()->pants)) {
                    player_.equipment()->pants = player_.inventory()->takeItem(item);
                    emit s_itemEquiped(item);
                    playerToUi();
                } else {
                    QMessageBox::warning(this, tr("Ошибка!"), tr("Недостаточно места в инвентаре!"));
                }
            } else {
                player_.equipment()->pants = player_.inventory()->takeItem(item);
                emit s_itemEquiped(item);
                playerToUi();
            }
            break;
        }
        case InventoryItemType::boots: {
            if (player_.equipment()->boots) {
                if (player_.inventory()->addItem(player_.equipment()->boots)) {
                    player_.equipment()->boots = player_.inventory()->takeItem(item);
                    emit s_itemEquiped(item);
                    playerToUi();
                } else {
                    QMessageBox::warning(this, tr("Ошибка!"), tr("Недостаточно места в инвентаре!"));
                }
            } else {
                player_.equipment()->boots = player_.inventory()->takeItem(item);
                emit s_itemEquiped(item);
                playerToUi();
            }
            break;
        }
        case InventoryItemType::gloves: {
            if (player_.equipment()->gloves) {
                if (player_.inventory()->addItem(player_.equipment()->gloves)) {
                    player_.equipment()->gloves = player_.inventory()->takeItem(item);
                    emit s_itemEquiped(item);
                    playerToUi();
                } else {
                    QMessageBox::warning(this, tr("Ошибка!"), tr("Недостаточно места в инвентаре!"));
                }
            } else {
                player_.equipment()->gloves = player_.inventory()->takeItem(item);
                emit s_itemEquiped(item);
                playerToUi();
            }
            break;
        }
        case InventoryItemType::belt: {
            if (player_.equipment()->belt) {
                if (player_.inventory()->addItem(player_.equipment()->belt)) {
                    player_.equipment()->belt = player_.inventory()->takeItem(item);
                    emit s_itemEquiped(item);
                    playerToUi();
                } else {
                    QMessageBox::warning(this, tr("Ошибка!"), tr("Недостаточно места в инвентаре!"));
                }
            } else {
                player_.equipment()->belt = player_.inventory()->takeItem(item);
                emit s_itemEquiped(item);
                playerToUi();
            }
            break;
        }
        case InventoryItemType::accessories: {

            break;
        }
        case InventoryItemType::oneHandedWeapon: {

            break;
        }
        case InventoryItemType::twoHandedWeapon: {

            break;
        }
        case InventoryItemType::item: {

            break;
        }
        }
    });
    connect(drop, &QAction::triggered, this, [=](bool) {
        //уведомление действительно ли хотите выбросить
    });
    connect(give, &QAction::triggered, this, [=](bool) {
        //узнать какие есть игроки, вывести список, передать
    });

    menu->addAction(equip);
    menu->addAction(drop);
    menu->addAction(give);
    menu->popup(ui->graphicsView->viewport()->mapToGlobal(QPoint(pos.x(), pos.y())));
}

bool FormInventoryBag::addItem(InventoryItem *aItem, QPoint aPoint) {
    InventoryItemVisual *itemVisual = new InventoryItemVisual(aItem);
    connect(itemVisual, &InventoryItemVisual::s_rightClick, this, &FormInventoryBag::createMenu);
    connect(itemVisual, &InventoryItemVisual::s_moved, this, [&](int xOld, int yOld, int xNew, int yNew, QGraphicsItem *item) {
        player_.inventory()->moveItem(QPoint(xOld, yOld), QPoint(xNew, yNew));
    });
    itemVisual->setPosItem(aPoint);
    ui->graphicsView->scene()->addItem(itemVisual);
    return true;
}

bool FormInventoryBag::addItem(InventoryItem *aItem) {
    if (player_.inventory()->addItem(aItem)) {
        playerToUi();
        return true;
    }
    return false;
}
