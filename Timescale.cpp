#include "Timescale.h"

Timescale::Timescale(QQuickItem *parent) :
    QQuickItem(parent)
{
}



void Timescale::setPositionRange(qreal positionStart, qreal positionEnd)
{
    m_positionStart = positionStart;
    m_positionEnd = positionEnd;

    ////////////////////////////////////////////////////////////
    m_scale = m_positionEnd - m_positionStart;

    if( m_scale == 1 )
        m_position = 0;
    else
        m_position = m_positionStart/(1 - m_scale);
    ////////////////////////////////////////////////////////////


    m_timeStart = m_positionStart * m_timeLength;
    m_timeEnd   = m_positionEnd * m_timeLength;
    m_timeViewLength = m_timeEnd - m_timeStart;

    ////////////////////////////////////////////////////////////
    m_pixelLength = m_pixelViewLength / m_scale;
    m_pixelViewStart = m_pixelViewLength * m_positionStart;
    m_pixelViewEnd = m_pixelViewStart + m_pixelViewLength;

    m_pixelRatio = m_pixelViewLength/m_timeViewLength;

    emit scaleChanged();

    qDebug() << "scaleChanged:" ;
}



void Timescale::zoomAtPosition(qreal ratio, qreal position)
{
    qreal newPositionStart;
    qreal newPositionEnd;

    if( (position < m_positionStart) || (position > m_positionEnd) )
    {
        return ;
    }

    newPositionStart = position - ((position - m_positionStart) * ratio);
    newPositionEnd = position + ((m_positionEnd - position) * ratio);

    if( newPositionStart < 0 )
        newPositionStart = 0;

    if( newPositionEnd > 1 )
        newPositionEnd = 1;

    setPositionRange(newPositionStart, newPositionEnd);
}





void Timescale::zoomAtCenter(qreal ratio)
{
    zoomAtPosition( ratio, (m_positionEnd - m_positionStart)/2 );
}


//void Timescale::moveToPosition(qreal position)
//{

//}


void Timescale::movePixel(qint64 pixel)
{
    quint64 newStart = m_pixelViewStart + pixel;
    quint64 newEnd = m_pixelViewEnd + pixel;

    qreal newPositionStart = (qreal)newStart/(qreal)m_pixelLength;
    qreal newPositionEnd = (qreal)newEnd/(qreal)m_pixelLength;

    setPositionRange(newPositionStart, newPositionEnd);
}


void Timescale::moveTime(qint64 time)
{
    quint64 newTimeStart = m_timeStart + time;
    quint64 newTimeEnd = m_timeEnd + time;

    qreal newPositionStart = (qreal)newTimeStart/(qreal)m_timeLength;
    qreal newPositionEnd = (qreal)newTimeEnd/(qreal)m_timeLength;

    setPositionRange(newPositionStart, newPositionEnd);
}


void Timescale::resizePixel(quint64 pixel)
{
    m_pixelViewLength = pixel;

    if( m_pixelViewLength > m_pixelLength )
    {
        m_pixelLength = m_pixelViewLength;
        m_pixelViewStart = 0;
        m_pixelViewEnd = m_pixelViewLength;
    }
    else if( (m_pixelViewStart + m_pixelViewLength) > m_pixelLength )
    {
        m_pixelViewStart = m_pixelLength - m_pixelViewLength;
        m_pixelViewEnd = m_pixelViewLength;
    }
    else
    {
        m_pixelViewEnd = m_pixelViewStart + m_pixelViewLength;
    }

    qreal newPositionStart = (qreal)m_pixelViewStart/(qreal)m_pixelLength;
    qreal newPositionEnd = (qreal)m_pixelViewEnd/(qreal)m_pixelLength;

    setPositionRange(newPositionStart, newPositionEnd);
}


//void Timescale::resizeTime(quint64 time)
//{
//    quint64 newEnd = m_timeEnd + time;

//}


