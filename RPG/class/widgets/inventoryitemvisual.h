#ifndef INVENTORYITEMVISUAL_H
#define INVENTORYITEMVISUAL_H

#include <QObject>
#include <QGraphicsObject>
#include "class/player/inventoryitem.h"

class InventoryItemVisual : public QObject, public QGraphicsItem {
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)
public:
    InventoryItemVisual(InventoryItem *item = nullptr, QObject *parent = nullptr);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    void setPosItem(int x, int y);
    void setPosItem(QPoint pos);

    QString toolTip() const;
    InventoryItem *item();

protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

//    void dragEnterEvent(QGraphicsSceneDragDropEvent *event) override;
//    void dragLeaveEvent(QGraphicsSceneDragDropEvent *event) override;
//    void dropEvent(QGraphicsSceneDragDropEvent *event) override;

    QPoint magnetic(QPointF aPos);
signals:
    void s_moved(int xOld, int yOld, int xNew, int yNew, QGraphicsItem *item);
    void s_rightClick(QPointF pos, InventoryItemVisual *graphicItem, InventoryItem *item);

private:
    QSize halfSize() const;
    void setPos(const QPointF &aPoint);
    void setPos(qreal x, qreal y);

    InventoryItem *item_;
    QPoint imageStart_;
    QPoint imageCenter_;
    bool dragOver = false;
};

#endif // INVENTORYITEMVISUAL_H
