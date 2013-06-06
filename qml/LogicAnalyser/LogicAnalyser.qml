import QtQuick 2.0
import QtQuick.Controls 1.0
import QtQuick.Layouts 1.0
import QtQuick.Dialogs 1.0

import LogicAnalyer 1.0

Rectangle {
    width: 800
    height: 480

    ColumnLayout {
        id: column_layout1
        anchors.fill: parent

        ToolBar {
            id: tool_bar1
            x: 26
            y: 156
            width: 360
            height: 50

            Layout.alignment: Qt.AlignTop | Qt.AlignLeft
            Layout.fillWidth: true
        }



        Rectangle {
            id: rectangle1
            x: 80
            y: 116
            width: 200
            height: 200
            color: "#b4e0f5"

            Layout.fillHeight: true
            Layout.fillWidth: true


            Flickable {
                id: flickable1
                x: 234
                y: 288
                width: 300
                height: 300
                anchors.fill: parent
                flickableDirection: Flickable.HorizontalFlick

                ListView {
                    id: list_view1
                    anchors.fill: parent
                    model: ListModel {
                        ListElement {
                            name: "Grey"
                            colorCode: "grey"
                        }

                        ListElement {
                            name: "Red"
                            colorCode: "red"
                        }

                        ListElement {
                            name: "Blue"
                            colorCode: "blue"
                        }

                        ListElement {
                            name: "Green"
                            colorCode: "green"
                        }
                    }

                    delegate: LogicChannel{
                        id: channel0
                        series: LogicSeries{
                            level: true
                        }

                        //            anchors.horizontalCenter: parent.horizontalCenter
                        width: parent.width
                        height: 60

                        color: colorCode
                    }
                }
            }

        }


        StatusBar {
            id: status_bar1
            x: 160
            y: 419

            Layout.alignment: Qt.AlignBottom | Qt.AlignLeft
        }


    }
}




