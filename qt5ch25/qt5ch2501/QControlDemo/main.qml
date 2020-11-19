import QtQuick 2.7
import QtQuick.Controls 1.5                //导入qt qucik controls 库
import QtQuick.Dialogs 1.2                 //导入qt quick对话框

ApplicationWindow {                        //主应用窗体
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    menuBar: MenuBar {                     //菜单栏
        Menu {                             //菜单项
            title: qsTr("File")
            MenuItem {                      //子菜单
                text: qsTr("&Open")
                onTriggered: console.log("Open action triggered");
            }
            MenuItem {
                text: qsTr("Exit")
                onTriggered: Qt.quit();
            }
        }
    }

    MainForm {                               //主窗体
        anchors.fill: parent
        button1.onClicked: messageDialog.show(qsTr("Button 1 pressed"))
        button2.onClicked: messageDialog.show(qsTr("Button 2 pressed"))
    }

    MessageDialog {                            //消息组件
        id: messageDialog
        title: qsTr("May I have your attention, please?")

        function show(caption) {
            messageDialog.text = caption;
            messageDialog.open();
        }
    }
}
