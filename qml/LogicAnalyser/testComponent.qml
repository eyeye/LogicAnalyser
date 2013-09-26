import QtQuick 2.0

Rectangle {
    id: rect
    width: 40
    height: 40
    color: "#e8a3a3"

//    property IntValidator step: 4
//    property IntValidator minWidth: 20

    NumberAnimation on opacity {
        from: 0
        to: 1
        duration: 200

//        onRunningChanged: {
//            if (!running) {
//                console.log("Destroying...")
//                rect.destroy();
//            }
//        }
    }

//    NumberAnimation on x {
//        from: 0
//        to: x
//        duration: 200
//    }

//    NumberAnimation on y {
//        from: 0
//        to: y
//        duration: 200
//    }

    MouseArea {
        anchors.fill: parent
        drag.target: parent

        onWheel: {
            var vstep
            var step = 8
            var minWidth = 20

            if (wheel.angleDelta.y > 0)
            {
                vstep = rect.width - minWidth

                if( step < vstep )
                {
                    vstep = step
                }

                rect.width = rect.width - vstep
                rect.x = rect.x + (vstep/2)
            }
            else
            {
                vstep = rect.parent.width - rect.width

                if( step < vstep )
                {
                    vstep = step
                }

                rect.width = rect.width + vstep
                rect.x = rect.x - (vstep/2)

            }
        }
    }

}



