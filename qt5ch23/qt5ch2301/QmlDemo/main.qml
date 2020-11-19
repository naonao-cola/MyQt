import QtQuick 2.9
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    MainForm {
            anchors.fill: parent
            mouseArea.onClicked: {              //控制台打印日志
                console.log(qsTr('Clicked on background. Text: "' + textEdit.text + '"'))
            }
        }
}
