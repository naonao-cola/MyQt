#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QAxObject>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    //写excel按钮
    void on_writeExcelPushButton_clicked();
    //读excel 按钮
    void on_readExcelPushButton_clicked();
    //写word按钮
    void on_writeWordPushButton_clicked();
    //读word按钮
    void on_readWordPushButton_clicked();

private:
    Ui::MainWindow *ui;

    //excel应用程序指针
    QAxObject *myexcel;
    //工作簿集指针
    QAxObject *myworks;
    //工作簿指针
    QAxObject *workbook;
    //电子表格集指针
    QAxObject *mysheets;

    //word应用程序指针
    QAxObject *myword;
    //文档集指针
    QAxObject *mydocs;
    //文档指针
    QAxObject *document;
    //文本段指针
    QAxObject *paragraph;

};

#endif // MAINWINDOW_H
