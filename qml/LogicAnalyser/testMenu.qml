import QtQuick 2.1
import QtQuick.Controls 1.0
import QtQuick.Layouts 1.0
import QtQuick.Dialogs 1.0

Rectangle {
    width: 800
    height: 480

    ToolBar {
        id: tool_bar1
        x: 0
        y: 0
        width: 800
        height: 50

        ToolButton {
            id: tool_button1
            action: runStopAction
            x: 18
            y: 12
//            checkable: true
            checked: runStopAction.checked
            onCheckedChanged: {
                console.log(checked);
            }
        }

        Action {
            id: runStopAction
            text: checked? "停止" : "启动"
            shortcut: checked? "F8" : "F5"
            tooltip: checked? "停止" : "启动"
            checkable: true
        }
    }
}
