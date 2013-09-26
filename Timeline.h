#ifndef TIMELINE_H
#define TIMELINE_H

#include <QQuickPaintedItem>

class Timeline : public QQuickPaintedItem
{
    Q_OBJECT
public:
    explicit Timeline(QQuickPaintedItem *parent = 0);
    virtual void paint(QPainter * painter);

signals:
    
public slots:

    
private:
    quint64 m_StartTimeInNs;
    qreal m_PixelPerNs;
};

#endif // TIMELINE_H
