#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initMainWindow();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initMainWindow()
{
    QString imgPath = "girldiver.jpg";                  //本地路径（图片直接存放在项目目录下）
    Mat imgData = imread(imgPath.toLatin1().data());    //读取图像数据
    if(imgData.empty())
    {
        QMessageBox::information(nullptr,tr("提示信息"),tr("图片读取失败"));
        return;

    }
    cvtColor(imgData, imgData, COLOR_BGR2RGB);          //图像格式转换
    myImg = imgData;
    myQImg = QImage((const unsigned char*)(imgData.data), imgData.cols, imgData.rows, QImage::Format_RGB888);
    imgShow();
}

void MainWindow::imgProc(float con, int bri)
{
    Mat imgSrc = myImg;
    Mat imgDst = Mat::zeros(imgSrc.size(), imgSrc.type());
    imgSrc.convertTo(imgDst, -1, con, bri);

    myQImg = QImage((const unsigned char*)(imgDst.data), imgDst.cols, imgDst.rows, QImage::Format_RGB888);
    imgShow();
}

void MainWindow::imgShow()
{
    ui->viewLabel->setPixmap(QPixmap::fromImage(myQImg.scaled(ui->viewLabel->size(), Qt::KeepAspectRatio)));//在Qt界面上显示图像
}
void MainWindow::on_contrastVerticalSlider_sliderMoved(int position)
{
    imgProc(position / 33.3, 0);
}

void MainWindow::on_contrastVerticalSlider_valueChanged(int value)
{
    imgProc(value / 33.3, 0);
}

void MainWindow::on_brightnessVerticalSlider_sliderMoved(int position)
{
    imgProc(1.0, position);
}

void MainWindow::on_brightnessVerticalSlider_valueChanged(int value)
{
    imgProc(1.0, value);
}
