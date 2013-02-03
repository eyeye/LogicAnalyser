#include "logicseries.h"

LogicSeries::LogicSeries(QObject *parent) :
    QObject(parent), m_count(128), m_level(true)
{
    m_points = new quint64[m_count];

    for(quint32 i = 0; i < m_count; i++)
    {
        m_points[i] = i;
    }
}
