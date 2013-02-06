#include <QtGui/QGuiApplication>
#include <QDebug>
#include "qtquick2applicationviewer.h"
#include "logicchannel.h"
#include "logicseries.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qDebug()<<"QGuiApplication";

    qmlRegisterType<LogicChannel>("LogicAnalyer", 1, 0, "LogicChannel");
    qmlRegisterType<LogicSeries>("LogicAnalyer", 1, 0, "LogicSeries");

    qDebug()<<"qmlRegisterType";

    QtQuick2ApplicationViewer viewer;
    viewer.setMainQmlFile(QStringLiteral("qml/LogicAnalyser/main.qml"));
    viewer.showExpanded();

    return app.exec();
}
