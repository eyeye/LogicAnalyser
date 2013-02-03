#ifndef LOGICSERIES_H
#define LOGICSERIES_H

#include <QObject>

class LogicSeries : public QObject
{
    Q_OBJECT
public:
    LogicSeries(QObject *parent = 0);

signals:

public slots:

private:
    bool m_level;
    quint64* m_points;
    quint32 m_count;
};

#endif // LOGICSERIES_H
