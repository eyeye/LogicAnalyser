#ifndef LOGICACQUIRERSIMULATOR_H
#define LOGICACQUIRERSIMULATOR_H

#include <QQuickItem>
#include <QTimer>


//class Simulator :public QObject
//{
//    Q_OBJECT
//public:
//    Simulator();

//    void run();
//};


class LogicAcquirerSimulator : public QQuickItem
{
    Q_OBJECT

    Q_PROPERTY(qint32 status READ status WRITE setStatus NOTIFY statusChanged)

public:
    explicit LogicAcquirerSimulator(QQuickItem *parent = 0);
    ~LogicAcquirerSimulator();
    
    Q_INVOKABLE void start();
    Q_INVOKABLE void stop();

    qint32 status();
    void setStatus(qint32 status);

signals:
    void statusChanged(quint32 status);
    void dataReady(quint64* time, quint64* data, quint32 length);

public slots:

private slots:
    void timeout();

private:
    qint32 m_status;
    QTimer* m_timer;
    
};

#endif // LOGICACQUIRERSIMULATOR_H
