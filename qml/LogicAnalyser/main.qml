import QtQuick 2.0
import LogicAnalyer 1.0
//import LogicSeries 1.0

Rectangle {
    id: window
    width: 360
    height: 360

//    LogicSeries
//    {
//        id:series
//    }


    Rectangle {
        width: 400
        height: 200
        anchors.centerIn: parent
        color: "lightblue"

        Text {
            text: qsTr("Hello World")
            anchors.centerIn: parent
        }
        MouseArea {
            anchors.fill: parent
            onClicked: {
                Qt.quit();
            }
        }


    }


    Column{
        anchors.fill: parent
        spacing: 10

        LogicChannel{
            id: channel0
            series: LogicSeries{
                level: true
            }

            anchors.horizontalCenter: parent.horizontalCenter
            width: 500
            height: 60

            color: "maroon"
        }

        LogicChannel{
            id: channel1
            series: LogicSeries{
                level: false
            }
            anchors.horizontalCenter: parent.horizontalCenter
            width: 500
            height: 60

            color: "red"
        }

        LogicChannel{
            series: LogicSeries{
                level: true
            }

            anchors.horizontalCenter: parent.horizontalCenter
            width: 500
            height: 60

            color: "yellow"
        }
        LogicChannel{
            series: LogicSeries{
                level: true
            }

            anchors.horizontalCenter: parent.horizontalCenter
            width: 500
            height: 60

            color: "blue"
        }
        LogicChannel{
            series: LogicSeries{
                level: true
            }

            anchors.horizontalCenter: parent.horizontalCenter
            width: 500
            height: 60

            color: "black"
        }
        LogicChannel{
            series: LogicSeries{
                level: true
            }

            anchors.horizontalCenter: parent.horizontalCenter
            width: 500
            height: 60

            color: "pink"
        }
    }

}
