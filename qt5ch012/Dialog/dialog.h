#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class Dialog : public QDialog
{
    //Q_OBJECT宏必须出现在类的私有声明区中，用于启动元对象的特性。
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();
private:
    QLabel *label1,*label2;
    QLineEdit *lineEdit;
    QPushButton *button;

//注意槽函数的写法
private slots:
    void showArea();
};

#endif // DIALOG_H
