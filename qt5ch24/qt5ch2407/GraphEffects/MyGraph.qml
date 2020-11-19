import QtQuick 2.0
import QtGraphicalEffects 1.0			//(a)图形特效元素
Rectangle {								//矩形作为图像显示区
    width: animg.width
    height: animg.height
    AnimatedImage {						//显示GIF图像元素
        id: animg
        source: "images/insect.gif"		//图片路径
    }
    BrightnessContrast {				//(b)特效元素，设置亮度对比度
        id: bright
        anchors.fill: animg
        source: animg
    }
    SequentialAnimation {				//定义串行组合动画
        id: imgAnim
        NumberAnimation {				//用动画调整亮度
            target: bright
            property: "brightness"		//(c)亮度属性
            to: -0.5					//变暗
            duration: 3000
        }
        NumberAnimation {				//用动画设置对比度
            target: bright
            property: "contrast"		//(d)对比度属性
            to: 0.25					//对比度增强
            duration: 2000
        }
    }
    MouseArea {
        anchors.fill: parent
        onClicked: {
            imgAnim.running = true		//单击图像开启动画
        }
    }
}

