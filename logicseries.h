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
    quint64* points(void);
    quint32 count(void);

    void setLevel(bool level);
    void setPoints(quint64* points);
    void setCount(quint32 count);

    // 方便搜索的功能函数
//    Q_INVOKABLE quint64 leftPoint(quint64 time);
//    Q_INVOKABLE quint64 rightPoint(quint64 time);
//    Q_INVOKABLE quint64 neareatPoint(quint64 time);


signals:


public slots:

private:
    bool m_level;
    quint64* m_points;
    quint32 m_count;

    // 记忆当前左右位置，方便快速搜索。
    quint32 m_leftIndex;
    quint32 m_rightIndex;

    //quint64 m_pointsData[128];
};

#endif // LOGICSERIES_H
