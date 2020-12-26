#include "profilebox.h"

#include <QFont>
#include <QPen>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QGraphicsPixmapItem>
#include <QBrush>
#include <QDebug>

profileBox::profileBox(QGraphicsItem *parent) : QGraphicsItemGroup(parent)
{

    nameTag = new QGraphicsTextItem(this);

    QBrush brush(Qt::white);
    QPen pen(Qt::black);
    pen.setWidth(2);
    QFont font;
    font.setFamily("Arial");
    font.setPointSize(12);

    //Create items which are contained in this group
    auto rectangle = new QGraphicsRectItem;
    rectangle->setRect(0,0,90,100);
    rectangle->setBrush(brush);
    rectangle->setPen(pen);

    nameTag = new QGraphicsTextItem;
    nameTag->setFont(font);
    nameTag->setPlainText("");

    auto gPixmap = new QGraphicsPixmapItem;
    QPixmap pixmap(":/images/person-icon-blue.png");
    gPixmap->setPixmap(pixmap);
    gPixmap->setPos(15,30);

    //Add items to the group
    this->addToGroup(rectangle);
    this->addToGroup(nameTag);
    this->addToGroup(gPixmap);

    //Set items to be movable, selectable. This item should also notify graphics
    //scene about the movement of an item
    this->setFlag(QGraphicsItem::ItemIsMovable);
    this->setFlag(QGraphicsItem::ItemIsSelectable);
    this->setFlag(QGraphicsItem::ItemSendsScenePositionChanges);
}

void profileBox::init(QString name, MainWindow *window, QGraphicsScene *scene)
{
    nameTag->setPlainText(name);
    mainWindow = window;
    scene->addItem(this);
}

QVariant profileBox::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value)
{
    if(change == QGraphicsItem::ItemPositionChange)
    {
        mainWindow->updateLines();
    }

    return  QGraphicsItem::itemChange(change, value);
}
