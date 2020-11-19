import QtQuick 2.7

//声明对象
Rectangle { //根对象
    property alias mouseArea: mouseArea   //属性别名
    property alias textEdit: textEdit

    width: 360
    height: 360

    MouseArea {                            //子对象1，响应鼠标事件
        id: mouseArea                      //对象标识符
        anchors.fill: parent                //使用parent访问其父对象，anchors.fill是布局作用，使MouseArea充满对象内部
    }

    TextEdit {                              //子对象2
        id: textEdit
        text: qsTr("Enter some text...")
        verticalAlignment: Text.AlignVCenter
        anchors.top: parent.top              //矩形上部
        anchors.horizontalCenter: parent.horizontalCenter  //矩形居中位置
        anchors.topMargin: 20                              //距窗口顶部20像素
        Rectangle {
            anchors.fill: parent
            anchors.margins: -10
            color: "transparent"
            border.width: 1
        }
    }
}
