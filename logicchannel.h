#ifndef LOGICCHANNEL_H
#define LOGICCHANNEL_H

#include <QQuickItem>
#include "logicseries.h"

class LogicChannel : public QQuickItem
{
    Q_OBJECT
    //Q_PROPERTY(QPointF p1 READ p1 WRITE setP1 NOTIFY p1Changed)
    Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)
    Q_PROPERTY(LogicSeries* series READ series WRITE setSeries NOTIFY seriesChanged)

public:
    LogicChannel(QQuickItem *parent = 0);
    ~LogicChannel(void);
    QSGNode *updatePaintNode(QSGNode *, UpdatePaintNodeData *);

    QColor color(void) const;
    void setColor(const QColor &color);

    LogicSeries* series(void) const;
    void setSeries(LogicSeries *series);

signals:
    void colorChanged(const QColor &color);
    void seriesChanged(const LogicSeries *series);

public slots:


private:

    QColor m_color;
    LogicSeries* m_series;

};

#endif // LOGICCHANNEL_H
