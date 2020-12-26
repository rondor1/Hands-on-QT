#ifndef PROFILELINE_H
#define PROFILELINE_H

#include <QGraphicsLineItem>

class profileLine : public QGraphicsLineItem
{
public:
    profileLine(QGraphicsLineItem* parent = nullptr);
    void initLine(QGraphicsItem* start, QGraphicsItem* end);
    void updateLine();

    QGraphicsItem* startBox;
    QGraphicsItem* endBox;
};

#endif // PROFILELINE_H
