import QtQuick 2.0
import LogicAnalyer 1.0
//import LogicSeries 1.0

Rectangle {
    id: window
    width: 800
    height: 480


    Flickable {
        id: flickable1
        boundsBehavior: Flickable.DragOverBounds
        contentWidth: 1600
        anchors.fill: parent

        Column{
            id: channelList
            width: 1600
            height: parent.height
            clip: true
            anchors.left: parent.left
            anchors.leftMargin: 0
            anchors.top: parent.top
            anchors.topMargin: 0
            spacing: 10

            LogicChannel{
                id: channel0
                series: LogicSeries{
                    level: true
                }

                //            anchors.horizontalCenter: parent.horizontalCenter
                width: parent.width
                height: 60

                color: "maroon"
            }

            LogicChannel{
                id: channel1
                series: LogicSeries{
                    level: false
                }
                //            anchors.horizontalCenter: parent.horizontalCenter
                width: parent.width
                height: 60

                color: "red"
            }

            LogicChannel{
                series: LogicSeries{
                    level: true
                }

                //            anchors.horizontalCenter: parent.horizontalCenter
                width: parent.width
                height: 60

                color: "yellow"
            }
            LogicChannel{
                series: LogicSeries{
                    level: true
                }

                //            anchors.horizontalCenter: parent.horizontalCenter
                width: parent.width
                height: 60

                color: "blue"
            }

            LogicChannel{
                series: LogicSeries{
                    level: true
                }

                //            anchors.horizontalCenter: parent.horizontalCenter
                width: parent.width
                height: 60

                color: "black"
            }

            LogicChannel{
                series: LogicSeries{
                    level: true
                }

                //            anchors.horizontalCenter: parent.horizontalCenter
                width: parent.width
                height: 60

                color: "pink"
            }
        }
    }

}
