#include "mainwindow.h"
#include <QApplication>
#include <QPixmap>
#include <QSplashScreen>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //设置启动图片
    QPixmap pixmap("Qt.png");
    QSplashScreen splash(pixmap);
    splash.show();

    //使程序启动时仍然可以响应鼠标事件
    a.processEvents();

    MainWindow w;
    w.show();
    //窗体初始化之后，结束动画
    splash.finish(&w);

    return a.exec();
}
