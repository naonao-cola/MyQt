#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <windows.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    CoInitializeEx(NULL, COINIT_MULTITHREADED);
    ui->setupUi(this);

    myexcel = new QAxObject("Excel.Application");
    //获取工作簿
    myworks = myexcel->querySubObject("WorkBooks");
    //添加工作簿
    myworks->dynamicCall("Add");
    //获取当前活动工作簿
    workbook = myexcel->querySubObject("ActiveWorkBook");
    //获取电子表格集
    mysheets = workbook->querySubObject("Sheets");

    //
    myword = new QAxObject("Word.Application");
    //获取文档集
    mydocs = myword->querySubObject("Documents");
    //添加一个文档
    mydocs->dynamicCall("Add(void)");
    //指向当前活动文档
    document = myword->querySubObject("ActiveDocument");
    //指向当前选中文本
    paragraph = myword->querySubObject("Selection");
}

MainWindow::~MainWindow()
{
    delete ui;
}
//写excel方法
void MainWindow::on_writeExcelPushButton_clicked()
{
    //添加一个表
    mysheets->dynamicCall("Add");
    //指向当前活动表格
    QAxObject *sheet = workbook->querySubObject("ActiveSheet");
    //给表格命名
    sheet->setProperty("Name", "我爱Qt");
    //指向c3表格
    QAxObject *cell = sheet->querySubObject("Range(QVariant, QVariant)", "C3");
    //向单元格写入内容
    QString inStr = ui->InExcelLineEdit->text();
    cell->dynamicCall("SetValue(const QVariant&)", QVariant(inStr));

    //指向第二个表格
    sheet = mysheets->querySubObject("Item(int)", 2);
    //命名
    sheet->setProperty("Name", "Hello Qt");

    cell = sheet->querySubObject("Range(QVariant, QVariant)", "B5");
    cell->dynamicCall("SetValue(const QVariant&)", QVariant("Hello!I love Qt."));

    workbook->dynamicCall("SaveAs(const QString&)", "d:\\Qt\\office\\我爱 Qt5.xls");
    //保存退出
    workbook->dynamicCall("Close()");
    myexcel->dynamicCall("Quit()");

    QMessageBox::information(this, tr("完毕"), tr("Excel工作表已保存。"));
    ui->writeExcelPushButton->setEnabled(false);
    ui->readExcelPushButton->setEnabled(true);
}


//读excel
void MainWindow::on_readExcelPushButton_clicked()
{
    //打开excel
    myexcel = new QAxObject("Excel.Application");
    myworks = myexcel->querySubObject("WorkBooks");
    myworks->dynamicCall("Open(const QString&)", "d:\\Qt\\office\\我爱 Qt5.xls");

    //读出c3内容
    workbook = myexcel->querySubObject("ActiveWorkBook");
    mysheets = workbook->querySubObject("WorkSheets");
    QAxObject *sheet = workbook->querySubObject("Sheets(int)", 1);
    QAxObject *cell = sheet->querySubObject("Range(QVariant, QVariant)", "C3");
    QString outStr = cell->dynamicCall("Value2()").toString();
    ui->OutExcelLabel->setText(outStr);

    //定位到第二张表
    sheet = workbook->querySubObject("Sheets(int)", 2);
    cell = sheet->querySubObject("Range(QVariant, QVariant)", "B5");
    //读出B5单元格
    outStr = cell->dynamicCall("Value2()").toString();

    workbook->dynamicCall("Close()");
    myexcel->dynamicCall("Quit()");
    QMessageBox::information(this, tr("消息"), outStr);
    ui->writeExcelPushButton->setEnabled(true);
    ui->readExcelPushButton->setEnabled(false);
}


//写word
void MainWindow::on_writeWordPushButton_clicked()
{
    QString inStr = ui->InWordLineEdit->text();
    //写入从界面文本 框获取的文本
    paragraph->dynamicCall("TypeText(const QString&)", inStr);
    //写入指定文本
    paragraph->dynamicCall("TypeText(const QVariant&)", QVariant("\nHello!I love Qt."));
    //保存文档
    document->dynamicCall("SaveAs(const QString&)", "d:\\Qt\\office\\我爱 Qt5.doc");

    delete paragraph;
    paragraph = nullptr;
    document->dynamicCall("Close()");
    myword->dynamicCall("Quit()");
    QMessageBox::information(this, tr("完毕"), tr("Word文档已保存。"));
    ui->writeWordPushButton->setEnabled(false);
    ui->readWordPushButton->setEnabled(true);
}
//读word
void MainWindow::on_readWordPushButton_clicked()
{
    myword = new QAxObject("Word.Application");
    //获取文档集
    mydocs = myword->querySubObject("Documents");
    //打开文档
    mydocs->dynamicCall("Open(const QString&)", "d:\\Qt\\office\\我爱 Qt5.doc");
    //指向活动文档
    document = myword->querySubObject("ActiveDocument");
    //指向当前文本
    paragraph = document->querySubObject("Range()");
    //读出当前文本
    QString outStr = paragraph->property("Text").toString();
    ui->OutWordLabel->setText(outStr.split("H").at(0));
    paragraph = document->querySubObject("Range(QVariant, QVariant)", 14, 30);

    outStr = paragraph->property("Text").toString();
    delete paragraph;
    paragraph = nullptr;
    document->dynamicCall("Close()");
    myword->dynamicCall("Quit()");
    QMessageBox::information(this, tr("消息"), outStr);
    ui->writeWordPushButton->setEnabled(true);
    ui->readWordPushButton->setEnabled(false);
}
