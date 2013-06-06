import QtQuick 2.0
import "test.js" as JSTest


Rectangle {
    id: rootRect
    width: 480
    height: 320


    MouseArea {
        id: mousearea1
        anchors.fill: parent
        onDoubleClicked: {
            JSTest.creatTestComponent(rootRect, mouse.x, mouse.y);
        }
    }

    Component.onCompleted: {
        JSTest.loadTestComponent();
    }
}
