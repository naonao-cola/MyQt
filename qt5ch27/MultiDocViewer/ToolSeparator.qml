import QtQuick 2.4
import QtQuick.Layouts 1.2
Item {
    width: 8
    //anchors.top: parent.top
    Layout.alignment: Qt.AlignTop
    //anchors.bottom: parent.bottom
    //anchors.margins: 6
    Layout.margins: 6

    Rectangle {
        width: 1
        height: parent.height
        anchors.horizontalCenter: parent.horizontalCenter
        color: "#22000000"
    }
    Rectangle {
        width: 1
        height: parent.height
        anchors.horizontalCenterOffset: 1
        anchors.horizontalCenter: parent.horizontalCenter
        color: "#33ffffff"
    }
}
