#include "mainwindow.h"
#include <QtDebug>
#include <QFile>
#include <QDataStream>
#include <QDate>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    fileFun();
}

MainWindow::~MainWindow()
{

}

void MainWindow::fileFun()
{

    /*二进制写到数据流*/
    QFile file("binary.dat");
    file.open(QIODevice::WriteOnly|QIODevice::Truncate);

    //数据序列化
    QDataStream out(&file);
    out<<QString(tr("周何俊："));
    out<<QDate::fromString("1996/09/25","yyyy/MM/dd");
    //整数序列化
    out<<(qint32)23;
    file.close();


    //读数据
    file.setFileName("binary.dat");
    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug()<<"error";
        return ;
    }
    QDataStream in(&file);
    QString name ;
    QDate birthday;
    qint32 age;
    in>>name>>birthday>>age;
    qDebug()<<name<<birthday<<age;
    file.close();
}
