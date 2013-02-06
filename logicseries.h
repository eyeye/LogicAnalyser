#ifndef LOGICSERIES_H
#define LOGICSERIES_H

#include <QObject>

class LogicSeries : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool level READ level WRITE setLevel)
public:
    LogicSeries(QObject *parent = 0);
    ~LogicSeries(void);

    bool level(void);
    double* points(void);
    quint32 count(void);

    void setLevel(bool level);
    void setPoints(double* points);
    void setCount(quint32 count);

signals:


public slots:

private:
    bool m_level;
    double* m_points;
    quint32 m_count;

    double m_pointsData[128];
};

#endif // LOGICSERIES_H
