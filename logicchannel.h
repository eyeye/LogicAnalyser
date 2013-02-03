#ifndef LOGICCHANNEL_H
#define LOGICCHANNEL_H

#include <QQuickItem>

class LogicChannel : public QQuickItem
{
    Q_OBJECT
    //Q_PROPERTY(QPointF p1 READ p1 WRITE setP1 NOTIFY p1Changed)
    Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)

public:
    LogicChannel(QQuickItem *parent = 0);
    ~LogicChannel(void);
    QSGNode *updatePaintNode(QSGNode *, UpdatePaintNodeData *);

    QColor color(void) const;
    void setColor(const QColor &color);

signals:
    void colorChanged(const QColor &color);
public slots:


private:

    QColor m_color;

};

#endif // LOGICCHANNEL_H
