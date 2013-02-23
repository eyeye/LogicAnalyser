#include "logicseries.h"

LogicSeries::LogicSeries(QObject *parent) :
    QObject(parent), m_level(true), m_count(1024)
{
    qDebug("Series Init!");
    m_points = new quint64[m_count];
    //m_points = m_pointsData;
    quint32 sum = 0;

    for(quint32 i = 0; i < m_count; i++)
    {
        sum += i;
        m_points[i] = 8*i;
    }
}

LogicSeries::~LogicSeries()
{
    delete m_points;
}

bool LogicSeries::level()
{
    return m_level;
}

quint64 *LogicSeries::points()
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

void LogicSeries::setPoints(quint64 *points)
{
    if(m_points != points)
    {
        if( m_points != NULL )
        {
            delete m_points;
        }

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
