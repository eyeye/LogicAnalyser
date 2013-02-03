import QtQuick 2.0
import LogicAnalyer 1.0
import LogicSeries 1.0

Rectangle {
    id: window
    width: 360
    height: 360

    LogicSeries
    {
        id:series
    }


    Rectangle {
        width: parent.width/2
        height: parent.height/2
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
        spacing: 40

        LogicChannel{
            id: channel0
            anchors.horizontalCenter: window.horizontalCenter
            width: window.width
            height: 60

            color: "maroon"
        }

        LogicChannel{
            id: channel1
            anchors.horizontalCenter: window.horizontalCenter
            width: window.width
            height: 60

            color: "maroon"
        }
    }

}