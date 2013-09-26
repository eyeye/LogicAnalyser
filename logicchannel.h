#ifndef LOGICCHANNEL_H
#define LOGICCHANNEL_H

#include <QQuickItem>
#include <QVector>
#include <QTimer>
#include "logicseries.h"
#include <QtQuick/qsgnode.h>
#include <QtQuick/qsgflatcolormaterial.h>


class LogicChannel : public QQuickItem
{
    Q_OBJECT
    //Q_PROPERTY(QPointF p1 READ p1 WRITE setP1 NOTIFY p1Changed)
    Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)
    Q_PROPERTY(qint32 nSecPerPixel READ nSecPerPixel WRITE setNSecPerPixel NOTIFY nSecPerPixelChanged)
//    Q_PROPERTY(LogicSeries* series READ series WRITE setSeries NOTIFY seriesChanged)

public:
    LogicChannel(QQuickItem *parent = 0);
    ~LogicChannel(void);
    QSGNode *updatePaintNode(QSGNode *, UpdatePaintNodeData *);

    QColor color(void) const;
    void setColor(const QColor &color);

    qint32 nSecPerPixel(void) const;
    void setNSecPerPixel(qint32 nSecPerPixel);

//    LogicSeries* series(void) const;

//    void setSeries(LogicSeries *series);

signals:
    void colorChanged(const QColor &color);
    void nSecPerPixelChanged(qint32 nSecPerPixel);

//    void seriesChanged(const LogicSeries *series);

public slots:
    void updatePoints();
    void autoAddPoint();

private:

    QSGGeometryNode *m_node;
    QSGGeometry     *m_geometry;

    QColor m_color;
    qint32 m_nSecPerPixel;

//    LogicSeries* m_series;

    QVector<quint64> *m_points;
    qint32 m_count;
};

#endif // LOGICCHANNEL_H
