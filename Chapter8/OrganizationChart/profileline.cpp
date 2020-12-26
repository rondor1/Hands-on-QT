#include "profileline.h"
#include <QPen>

profileLine::profileLine(QGraphicsLineItem *parent)
{
    QPen pen(Qt::black);
    pen.setWidth(2);
    this->setPen(pen);

    this->setZValue(-999);
}

void profileLine::initLine(QGraphicsItem *start, QGraphicsItem *end)
{
    this->startBox = start;
    this->endBox = end;


    //Update drawing
    updateLine();
}

void profileLine::updateLine()
{
    if(startBox && endBox)
    {
        //Draw line between two boxes
        this->setLine(startBox->x() + startBox->boundingRect().width() / 2,
                      startBox->y() + startBox->boundingRect().height() /2,
                      endBox->x() + endBox->boundingRect().width() / 2,
                      endBox->y() + endBox->boundingRect().height() / 2);
    }
}


