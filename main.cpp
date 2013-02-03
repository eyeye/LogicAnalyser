#include <QtGui/QGuiApplication>
#include "qtquick2applicationviewer.h"
#include "logicchannel.h"
#include "logicseries.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<LogicChannel>("LogicAnalyer", 1, 0, "LogicChannel");
    qmlRegisterType<LogicSeries>("LogicAnalyer", 1, 0, "LogicSeries");

    QtQuick2ApplicationViewer viewer;
    viewer.setMainQmlFile(QStringLiteral("qml/LogicAnalyser/main.qml"));
    viewer.showExpanded();

    return app.exec();
}
