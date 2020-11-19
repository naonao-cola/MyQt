#include "dialog.h"
#include <QGridLayout>
const static double PI = 3.141592653;

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    label1 = new QLabel(this);
    label1->setText(tr("请输入圆的半径： "));
    lineEdit = new QLineEdit(this);
    label2 = new QLabel(this);
    button = new QPushButton(this);
    button->setText(tr("显示对应的圆的面积"));

    QGridLayout* mainLayout = new QGridLayout(this);

    mainLayout->addWidget(label1,0,0);
    mainLayout->addWidget(lineEdit,0,1);
    mainLayout->addWidget(label2,1,0);
    mainLayout->addWidget(button,1,1);
    //将布局管理器添加到对应的窗口部件对象中
    setLayout(mainLayout);
    //信号槽
   //connect(button,SIGNAL(clicked()),this,SLOT(showArea()));
    //slot是对象2的槽
    //SIGNAL()和SLOT()是Qt定义的两个宏，它们返回其参数的C语言风格的字符串（const char*）
    //传递一个信号来调用槽函数会比直接调用非虚函数的运行速度慢10倍。
    connect(lineEdit,SIGNAL(textChanged(QString)),this,SLOT(showArea()));
}

Dialog::~Dialog()
{

}



void Dialog::showArea()
{
    bool ok;
       QString tempStr;
       QString valueStr=lineEdit->text();
       double valueInt=valueStr.toDouble(&ok);
       double area=valueInt*valueInt*PI;
       label2->setText(tempStr.setNum(area));
}
