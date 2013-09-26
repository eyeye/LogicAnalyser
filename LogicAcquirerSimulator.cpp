#include "LogicAcquirerSimulator.h"
#include <QDebug>

LogicAcquirerSimulator::LogicAcquirerSimulator(QQuickItem *parent) :
    QQuickItem(parent)
{
    m_timer = new QTimer();
    connect(m_timer, SIGNAL(timeout()), this, SLOT(timeout()));
//    m_status = 1;
//    m_timer->start(200);
}

LogicAcquirerSimulator::~LogicAcquirerSimulator()
{
    delete m_timer;
}

void LogicAcquirerSimulator::start()
{
    m_status = 1;
    m_timer->start(200);

    emit statusChanged(m_status);
}

void LogicAcquirerSimulator::stop()
{
    m_timer->stop();
    m_status = 0;
    emit statusChanged(m_status);
}

qint32 LogicAcquirerSimulator::status()
{
    return m_status;
}


void LogicAcquirerSimulator::timeout()
{
    static quint64 time = 0;
    static quint64 dataBuffer[4];
    static quint64 timeBuffer[4];

    time += 20000;

    qDebug() << ".";

    timeBuffer[0] = time + 200;
    timeBuffer[1] = time + 400;
    timeBuffer[2] = time + 600;
    timeBuffer[3] = time + 800;

    dataBuffer[0] = 0x01;
    dataBuffer[1] = 0x02;
    dataBuffer[2] = 0x04;
    dataBuffer[3] = 0x08;

    emit dataReady(timeBuffer, dataBuffer, 4);
}


void LogicAcquirerSimulator::setStatus(qint32 status)
{
    m_status = status;
}



