#include <QtGui/QGuiApplication>
#include <QDebug>
#include "qtquick2applicationviewer.h"
#include "logicchannel.h"
#include "logicseries.h"
#include "LogicAcquirerSimulator.h"
#include "Timeline.h"
#include "Timescale.h"

#include "QuickItemDemo0.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);


    qDebug()<<"QGuiApplication";

    qmlRegisterType<LogicChannel>("LogicAnalyer", 1, 0, "LogicChannel");
    qmlRegisterType<LogicSeries>("LogicAnalyer", 1, 0, "LogicSeries");
    qmlRegisterType<LogicAcquirerSimulator>("LogicAnalyer", 1, 0, "LogicAcquirerSimulator");
    qmlRegisterType<Timeline>("LogicAnalyer", 1, 0, "Timeline");
    qmlRegisterType<Timescale>("LogicAnalyer", 1, 0, "Timescale");

    qmlRegisterType<LogicAcquirerSimulator>("LogicAnalyer", 1, 0, "QuickItemDemo0");


    qDebug()<<"qmlRegisterType";

    QtQuick2ApplicationViewer viewer;
    viewer.setMainQmlFile(QStringLiteral("qml/LogicAnalyser/LogicAnalyser.qml"));
//    viewer.setMainQmlFile(QStringLiteral("qml/LogicAnalyser/testQml.qml"));
    viewer.showExpanded();
//    QVariant
    return app.exec();
}



