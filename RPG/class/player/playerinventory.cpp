#include "playerinventory.h"

QJsonObject PlayerInventory::toJson() {
    QJsonArray array;
    for (auto item: items) {
        QJsonObject objItem;
        objItem["item"] = item.first->toJson();
        objItem["posX"] = item.second.x();
        objItem["posY"] = item.second.y();
        array.append(std::move(objItem));
    }

    QJsonObject obj;
    obj["array"] = array;
    return obj;
}

void PlayerInventory::fromJson(const QJsonObject &aObject) {
    auto array = aObject.value("array").toArray();
    for (auto val: array) {
        QJsonObject objItem = val.toObject();
        InventoryItem *item = new InventoryItem();
        item->fromJson(objItem.value("item").toObject());
        items.append(std::move(QPair<InventoryItem*, QPoint>(item, QPoint(objItem.value("posX").toInt(),
                                                                          objItem.value("posY").toInt()))));
    }
}

bool PlayerInventory::addItem(InventoryItem *aItem, QPoint aPoint) {
    auto points = accessPoints(aItem);
    bool isAvailable = std::any_of(points.begin(),
                                    points.end(),
                                    [&](QPoint lPoint) {
                                        return lPoint == aPoint;
                                    });
    if (isAvailable) {
        items.append(std::move(QPair<InventoryItem*, QPoint>(aItem, aPoint)));
        return true;
    }
    return false;
}

bool PlayerInventory::addItem(InventoryItem *aItem) {
    auto points = accessPoints(aItem);
    if (points.count() > 0) {
        items.append(std::move(QPair<InventoryItem*, QPoint>(aItem, points[0])));
        return true;
    }
    return false;
}

bool PlayerInventory::moveItem(QPoint oldPosition, QPoint newPosition) {
//    qDebug() << 1 << oldPosition << newPosition;
//    qDebug() << toJson();
    auto iterator = std::find_if(items.begin(),
                                 items.end(),
                                 [&](QPair<InventoryItem*, QPoint> lItem) {
                                    return lItem.second.x() <= oldPosition.x() &&
                                            lItem.second.y() <= oldPosition.y() &&
                                            lItem.second.x() + lItem.first->width() >= oldPosition.x() &&
                                            lItem.second.y() + lItem.first->height() >= oldPosition.y();
                                 });
    if (iterator != items.end()) {
//        qDebug() << 2;
        auto points = accessPoints(iterator->first);
//        qDebug() << points;
        bool isAvailable = std::any_of(points.begin(),
                                        points.end(),
                                        [&](QPoint lPoint) {
                                            return lPoint == newPosition;
                                        });
        if (isAvailable) {
//            qDebug() << 3;
            iterator->second = newPosition;
            return true;
        }
    }
    return false;
}

InventoryItem *PlayerInventory::takeItem(InventoryItem *aItem) {
    if (aItem == nullptr) {
        return nullptr;
    }
    auto iterator = std::find_if(items.begin(),
                                 items.end(),
                                 [=](QPair<InventoryItem*, QPoint> lItem) {
                                    if (lItem.first != nullptr) {
                                        return *(lItem.first) == *aItem;
                                    }
                                    return false;
                                 });
    if (iterator != items.end()) {
        return items.takeAt(iterator - items.begin()).first;
    }
    return nullptr;
}

void PlayerInventory::removeItem(QPoint aPoint) {
    auto iterator = std::find_if(items.begin(),
                                 items.end(),
                                 [&](QPair<InventoryItem*, QPoint> lItem) {
                                    return lItem.second.x() >= aPoint.x() &&
                                            lItem.second.y() >= aPoint.y() &&
                                            lItem.second.x() + lItem.first->width() <= aPoint.x() &&
                                            lItem.second.y() + lItem.first->height() <= aPoint.y();
                                 });
    if (iterator != items.end()) {
        items.removeAt(iterator - items.begin());
    }
}

QList<QPoint> PlayerInventory::accessPoints(InventoryItem *aItem) {
    QList<QList<int>> map;
    for (int i = 0; i < c_cellsBagWidth; ++i) {
        QList<int> column;
        for (int j = 0; j < c_cellsBagHeight; ++j) {
            column.append(0);
        }
        map.append(std::move(column));
    }

    for (int i = 0; i < c_cellsBagWidth; ++i) {
        for (int j = c_cellsBagHeight - aItem->height() + 1; j < c_cellsBagHeight; ++j) {
            map[i][j] = -1;
        }
    }

    for (int i = c_cellsBagWidth - aItem->width() + 1; i < c_cellsBagWidth; ++i) {
        for (int j = 0; j < c_cellsBagHeight; ++j) {
            map[i][j] = -1;
        }
    }

    for (auto item: items) {
        if (item.first != aItem) {
            int itemX = item.second.x();
            int itemY = item.second.y();
            for (int i = itemX; i < itemX + item.first->width(); ++i) {
                for (int j = itemY; j < itemY + item.first->height(); ++j) {
                    map[i][j] = 1;
                }
            }
        }
    }

//    for (int i = 0; i < c_cellsBagHeight; ++i) {
//        qDebug() << map[0][i] << map[1][i] << map[2][i] << map[3][i] << map[4][i] << map[5][i] << map[6][i] << map[7][i] << map[8][i] << map[9][i];
//    }

    QList<QPoint> result;
    for (int j = 0; j < c_cellsBagHeight - aItem->height() + 1; ++j) {
        for (int i = 0; i < c_cellsBagWidth - aItem->width() + 1; ++i) {
            if (map[i][j] == 0) {
                bool isAvailable = true;
                for (int ii = i; ii < i + aItem->width(); ++ii) {
                    for (int ji = j; ji < j + aItem->height(); ++ji) {
                        if (map[ii][ji] > 0) {
                            isAvailable = false;
                        }
                    }
                }
                if (isAvailable) {
                    result.append(QPoint(i, j));
                }
            }
        }
    }
//    qDebug() << result;
    return result;
}
