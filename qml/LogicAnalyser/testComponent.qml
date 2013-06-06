import QtQuick 2.0

Rectangle {
    id: rect
    width: 20
    height: 20
    color: "#e8a3a3"

    NumberAnimation on opacity {
        to: 0
        duration: 1000

        onRunningChanged: {
            if (!running) {
                console.log("Destroying...")
                rect.destroy();
            }
        }
    }

    NumberAnimation on x {
        to: 0
        duration: 1000
    }

    NumberAnimation on y {
        to: 0
        duration: 1000
    }
}



