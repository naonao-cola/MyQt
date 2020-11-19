import QtQuick 2.0

Rectangle {
    width: 80
    height: 80
    ColorAnimation on color {						//(a)颜色动画
        from: "blue"
        to: "aqua"
        duration: 10000
        loops: Animation.Infinite
    }
    RotationAnimation on rotation {					//(b)旋转动画
        from: 0
        to: 360
        duration: 10000
        direction: RotationAnimation.Clockwise
        loops: Animation.Infinite
    }
    NumberAnimation on radius {						//(c)改变属性数值的动画
        from: 0
        to: 40
        duration: 10000
        loops: Animation.Infinite
    }
    PropertyAnimation on x {                          //属性整体动画
        from: 50
        to: 500
        duration: 10000
        loops: Animation.Infinite
        easing.type: Easing.InOutQuad				//先加速，后减速
    }
}

