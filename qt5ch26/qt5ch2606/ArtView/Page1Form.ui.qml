import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0


Item
{

    property alias topic: topic
    property alias author: author

    SwipeView
    {
        id: view
        currentIndex: pageIndicator.currentIndex           //与下面一致保持同步
        anchors.fill: parent

        Page
        {
            title: qsTr("蒙娜丽莎")
            Image
            {
                source: "images/蒙娜丽莎.jpg"
            }
        }
        Page
        {
            title: qsTr("大卫")
            Image
            {
                source: "images/大卫.jpg"
            }
        }
        Page
        {
            title: qsTr("西斯廷圣母")
            Image
            {
                source: "images/圣母.jpg"
            }
        }
    }

    PageIndicator                              //页面指示器控件
    {
        id: pageIndicator
        interactive: true                      //是否响应手指触击(鼠标事件)
        count: view.count
        currentIndex: view.currentIndex         //与上面一致，保持同步

        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Label
    {
        id: topic
        text: view.currentItem.title
        font.family: "微软雅黑"
        font.bold: true
        font.pixelSize: 25
        anchors.right: parent.right
        anchors.rightMargin: 250
        TextArea
        {
            id: author
            font.family: "微软雅黑"
            font.pixelSize: 18
            anchors.top: parent.bottom
        }
    }
}
