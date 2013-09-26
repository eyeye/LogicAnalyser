import QtQuick 2.0
import LogicAnalyer 1.0

Rectangle {
    id: scrollMap

//    property variant flickView
    property real position :0
    property bool dragStarted: false
    property Timescale timescale

    width: 300
    height: 40

    color: "#e0ec8e"


//    Connections {
//        target: flickView
//        onContentXChanged: {
//            if( !dragStarted )
//            {
//                var newPosition = flickView.visibleArea.xPosition;
//                if( newPosition !== position )
//                {
//                    position = newPosition;
//                }
//            }
//        }
//    }

    Connections {
        target: scrollHandler
        onXChanged: {
            if( dragStarted )
            {
                var newContentX = (scrollHandler.x/(scrollMap.width - scrollHandler.width)) * flickView.contentWidth;

                if( newContentX !== flickView.contentX )
                {
                    flickView.contentX = newContentX;
                }
            }
        }
    }


    Rectangle {
        id: scrollHandler
        anchors.top: scrollMap.top

        height: scrollMap.height
//        width: flickView.visibleArea.widthRatio * scrollMap.width
        width: 40
        x: scrollMap.position * scrollMap.width
        color: "#193173"
        opacity: 0.6

        MouseArea {
            id: scrollArea
            anchors.fill: parent
            drag.target: parent
            drag.minimumX: 0
            drag.maximumX: scrollMap.width - scrollHandler.width

            onPressed: {
                scrollMap.dragStarted = true;
            }
            onReleased: {
                scrollMap.dragStarted = false;
            }


        }

    }
}
