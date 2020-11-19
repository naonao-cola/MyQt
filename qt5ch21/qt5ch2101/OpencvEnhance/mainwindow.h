#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "opencv2/opencv.hpp"

using namespace cv;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //公有方法
    void initMainWindow();                          //界面初始化
    void imgProc(float contrast, int brightness);   //处理图片
    void imgShow();                                 //显示图片
private slots:
    void on_contrastVerticalSlider_sliderMoved(int position);

    void on_contrastVerticalSlider_valueChanged(int value);

    void on_brightnessVerticalSlider_sliderMoved(int position);

    void on_brightnessVerticalSlider_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    Mat myImg;              //缓存图片（供程序代码引用和处理）
    QImage myQImg;          //保存图片（可转为文件存盘或显示）
};

#endif // MAINWINDOW_H
