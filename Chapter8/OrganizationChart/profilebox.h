#ifndef PROFILEBOX_H
#define PROFILEBOX_H

#include <QGraphicsItemGroup>

#include "mainwindow.h"

class MainWindow;
class QGraphicsTextItem;

class profileBox : public QGraphicsItemGroup
{
public:
    profileBox(QGraphicsItem *parent = nullptr);
    void init(QString name, MainWindow* window, QGraphicsScene* scene);
    QVariant itemChange(GraphicsItemChange change, const QVariant& value) override;

private:
    MainWindow* mainWindow;
    QGraphicsTextItem* nameTag;
};

#endif // PROFILEBOX_H
