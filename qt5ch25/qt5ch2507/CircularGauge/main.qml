import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.2
import QtQuick.Extras 1.4          //CircularGauge的库

ApplicationWindow
{
    visible: true
    width: 320
    height: 240
    title: qsTr("汽车时速表")

    MainForm
    {
        anchors.fill: parent
        CircularGauge
        {
            value: accelerating ? maximumValue : 0
            anchors.centerIn: parent

            property bool accelerating: false   //通过accelerating判断加速状态

            Keys.onSpacePressed: accelerating = true
            Keys.onReleased:
            {
                if (event.key === Qt.Key_Space)
                {
                    accelerating = false;
                    event.accepted = true;
                }
            }

            Component.onCompleted: forceActiveFocus()

            Behavior on value {
                NumberAnimation {
                    duration: 1000
                }
            }
        }

    }

}
