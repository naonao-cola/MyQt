import QtQuick 2.9
import QtQuick.Window 2.2

Window {
    visible: true
    width: 250
    height: 220
    title: qsTr("Rectangle")
    MainForm{
    anchors.fill: parent
    mouseArea.onClicked: {
            topRect.visible = !topRect.visible
        }
    }
}
