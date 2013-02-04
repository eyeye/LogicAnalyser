#include "logicseries.h"

LogicSeries::LogicSeries(QObject *parent) :
    QObject(parent), m_level(true), m_count(128)
{
    m_points = new double[m_count];

    qDebug("初始化Series！");
    for(quint32 i = 0; i < m_count; i++)
    {
        m_points[i] = i;
    }
}

bool LogicSeries::level()
{
    return m_level;
}

double *LogicSeries::points()
{
    return m_points;
}

quint32 LogicSeries::count()
{
    return m_count;
}

void LogicSeries::setLevel(bool level)
{
    if(m_level != level)
    {
        m_level = level;

    }
}

void LogicSeries::setPoints(double *points)
{
    if(m_points != points)
    {
        m_points = points;
    }
}

void LogicSeries::setCount(quint32 count)
{
    if(m_count != count)
    {
        m_count = count;
    }
}
