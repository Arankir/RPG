#include "inventoryitemvisual.h"
#include <QGraphicsSceneDragDropEvent>
#include <QGraphicsSceneMouseEvent>
#include <QMimeData>
#include <QPainter>
#include <QDebug>
#include <QToolTip>
#include <QGraphicsScene>

InventoryItemVisual::InventoryItemVisual(InventoryItem *item, QObject *parent):
QObject(parent), QGraphicsItem(), item_(item) {
    if (item_) {
        this->setToolTip(item_->text());
    } else {
        this->setToolTip(tr("Неизвестный предмет"));
    }
}

QRectF InventoryItemVisual::boundingRect() const {
    if (item_) {
        return QRectF(-halfSize().width(),
                      -halfSize().height(),
                      (item_->width() * c_pixelsInventoryItem),
                      (item_->height() * c_pixelsInventoryItem));
    } else {
        return QRectF();
    }
}

void InventoryItemVisual::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);
    if (item_) {
        if (!item_->image().isNull()) {
            painter->drawImage(QPointF(-halfSize().width(), -halfSize().height()),
                               item_->image().scaled(item_->width() * c_pixelsInventoryItem, item_->height() * c_pixelsInventoryItem));
            return;
        }
    }
    painter->setPen(Qt::black);
    painter->setBrush(Qt::green);
    painter->drawRect(-c_pixelsInventoryItem, -c_pixelsInventoryItem,
                      c_pixelsInventoryItem * 2, c_pixelsInventoryItem * 2);
}

void InventoryItemVisual::setPosItem(int x, int y) {
    if (item_) {
        imageStart_ = QPoint(x * c_pixelsInventoryItem, y * c_pixelsInventoryItem);
        imageCenter_ = QPoint(x * c_pixelsInventoryItem + item_->width() * c_pixelsInventoryItem - halfSize().width(),
                              y * c_pixelsInventoryItem + item_->height() * c_pixelsInventoryItem - halfSize().height());
//        qDebug() << x << x * c_pixelsInventoryItem << x * c_pixelsInventoryItem - halfSize().width() << x_;
        QGraphicsItem::setPos(imageCenter_);
        magnetic(imageCenter_);
    }
}

void InventoryItemVisual::setPosItem(QPoint pos) {
    setPosItem(pos.x(), pos.y());
}

QString InventoryItemVisual::toolTip() const {
    if (item_) {
        return item_->text();
    } else {
        return tr("Неизвестный предмет");
    }
}

InventoryItem *InventoryItemVisual::item() {
    return item_;
}

void InventoryItemVisual::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    /* Set the position of the graphical element in the graphic scene,
     * translate coordinates of the cursor within the graphic element
     * in the coordinate system of the graphic scenes
     * */
    this->setPos(mapToScene(event->pos()));
}

void InventoryItemVisual::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    switch (event->button()) {
    case Qt::MouseButton::LeftButton: {
        this->setCursor(QCursor(Qt::ClosedHandCursor));
        break;
    }
    case Qt::MouseButton::RightButton: {
        emit s_rightClick(event->scenePos(), this, item_);
        event->ignore();
        break;
    }
    default: {
        event->ignore();
        break;
    }
    }
}

QPoint InventoryItemVisual::magnetic(QPointF aPos) {
    this->moveBy(-(static_cast<int>(aPos.x() - halfSize().width()) % c_pixelsInventoryItem),
                 -(static_cast<int>(aPos.y() - halfSize().height()) % c_pixelsInventoryItem));
    return QPoint(aPos.x() - (static_cast<int>(aPos.x() - halfSize().width()) % c_pixelsInventoryItem),
                  aPos.y() - (static_cast<int>(aPos.y() - halfSize().height()) % c_pixelsInventoryItem));
}

void InventoryItemVisual::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    switch (event->button()) {
    case Qt::MouseButton::LeftButton: {
        this->setCursor(QCursor(Qt::ArrowCursor));

        QPoint scenePos = magnetic(event->scenePos());
        QPoint startPos(scenePos.x() - halfSize().width(),
                         scenePos.y() - halfSize().height());

        auto collidingsItems = this->collidingItems();
        bool isCollised = std::any_of(collidingsItems.begin(),
                                      collidingsItems.end(),
                                      [&](QGraphicsItem *lItem) {
                                        return dynamic_cast<InventoryItemVisual*>(lItem) != nullptr;
                                      });
    //    qDebug() << isCollised;
    //    qDebug() << 1 << event->scenePos();
    //    qDebug() << 2 << scenePos;
    //    qDebug() << 3 << startPos;
    //    qDebug() << 4 << imageCenter_;
    //    qDebug() << 5 << imageStart_;
    //    qDebug() << 6 << imageCenter_.x() + halfSize().width() << imageCenter_.y() + halfSize().height();

        if (isCollised ||
                startPos.x() < 0 ||
                startPos.y() < 0 ||
                startPos.x() + item_->width() * c_pixelsInventoryItem > scene()->width() ||
                startPos.y() + item_->height() * c_pixelsInventoryItem > scene()->height()) {
            this->setPos(imageCenter_);
        } else {
            emit s_moved(imageStart_.x() / c_pixelsInventoryItem,
                         imageStart_.y() / c_pixelsInventoryItem,
                         startPos.x() / c_pixelsInventoryItem,
                         startPos.y() / c_pixelsInventoryItem, this);
            imageStart_ = startPos;
            imageCenter_ = scenePos;
        }
        break;
    }
    case Qt::MouseButton::RightButton: {

        break;
    }
    default: {
        event->ignore();
        break;
    }
    }
}

QSize InventoryItemVisual::halfSize() const {
    if (item_) {
        return QSize(item_->width() * c_pixelsInventoryItem / 2,
                     item_->height() * c_pixelsInventoryItem / 2);
    }
    return QSize();
}

void InventoryItemVisual::setPos(const QPointF &aPoint) {
    QGraphicsItem::setPos(aPoint);
}

void InventoryItemVisual::setPos(qreal x, qreal y) {
    QGraphicsItem::setPos(x, y);
}

//void InventoryItemVisual::dragEnterEvent(QGraphicsSceneDragDropEvent *event) {
//    if (event->mimeData()) {
//        event->setAccepted(true);
//        dragOver = true;
//        update();
//    } else {
//        event->setAccepted(false);
//    }
//}

//void InventoryItemVisual::dragLeaveEvent(QGraphicsSceneDragDropEvent *event) {
//    Q_UNUSED(event);
//    dragOver = false;
//    update();
//}

//void InventoryItemVisual::dropEvent(QGraphicsSceneDragDropEvent *event) {
//    dragOver = false;
//    if (event->mimeData()) {
//        item_->setMimeData(event->mimeData());
//    }
//    update();
//}
