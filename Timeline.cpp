#include "Timeline.h"
#include <QPainter>

Timeline::Timeline(QQuickPaintedItem *parent) :
    QQuickPaintedItem(parent)
{
    setFlag(ItemHasContents, true);
}


void Timeline::paint(QPainter *painter)
{
    this->x();
    painter->setPen(Qt::green);

    painter->drawRect(this->x()+2, 2, width()-4, height()-4);
}


