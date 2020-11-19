import QtQuick 2.7
import QtQuick.Controls 2.0                 //qt quick control2.0 库
import QtQuick.Layouts 1.0

ApplicationWindow
{
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    SwipeView                            //页面浏览控件(多页面选项卡控件)
    {
        id: swipeView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex

        Page1
        {
        }

        Page                            //标准页面(容器控件)
        {
            Label
            {
                text: qsTr("Second page")
                anchors.centerIn: parent
            }
        }
    }

    footer: TabBar {                           //标签栏
        id: tabBar
        currentIndex: swipeView.currentIndex
        TabButton {
            text: qsTr("First")
        }
        TabButton {
            text: qsTr("Second")
        }
    }
}
