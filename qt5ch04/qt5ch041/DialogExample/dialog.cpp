#include "dialog.h"
#include <QGridLayout>
#include <QFileDialog>
#include <QPushButton>
#include <QColorDialog>
#include <QFontDialog>
#include <QMessageBox>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle(tr("各种标准对话框的实例"));
    //布局设计
    mainLayout=new QGridLayout(this);

    //*************文件//
    fileBtn = new QPushButton;
    fileBtn->setText(tr("文件标准对话框实例"));
    //显示文件的文件名
    fileLineEdit = new QLineEdit;
    mainLayout->addWidget(fileBtn,0,0);
    mainLayout->addWidget(fileLineEdit,0,1);
    connect(fileBtn,SIGNAL(clicked()),this,SLOT(showFile()));


    //********************颜色//
    colorBtn = new QPushButton;
    colorBtn->setText(tr("颜色标准对话框实例"));
    colorFrame = new QFrame;
    colorFrame->setFrameShape(QFrame::Box);
    colorFrame->setAutoFillBackground(true);
    mainLayout->addWidget(colorBtn,1,0);
    mainLayout->addWidget(colorFrame,1,1);
    connect(colorBtn,SIGNAL(clicked()),this,SLOT(showColor()));

     //**************字体//
    fontBtn = new QPushButton;
    fontBtn->setText(tr("字体标准对话框实例"));
    fontLineEdit = new QLineEdit;
    fontLineEdit->setText(tr("Welcome"));
    mainLayout->addWidget(fontBtn,2,0);                         //布局设计
    mainLayout->addWidget(fontLineEdit,2,1);
    connect(fontBtn,SIGNAL(clicked()),this,SLOT(showFont()));	//事件关联

    //************************//
    inputBtn=new QPushButton;                                   //创建控件的对象
    inputBtn->setText(tr("标准输入对话框实例"));
    mainLayout->addWidget(inputBtn,3,0);                        //布局设计
    connect(inputBtn,SIGNAL(clicked()),this,SLOT(showInputDlg()));//事件关联

    //******消息///
    MsgBtn =new QPushButton;                                    //创建控件对象
    MsgBtn->setText(tr("标准消息对话框实例"));
    mainLayout->addWidget(MsgBtn,3,1);
    connect(MsgBtn,SIGNAL(clicked()),this,SLOT(showMsgDlg()));

    //*****自定义消息框//
    CustomBtn =new QPushButton;
    CustomBtn->setText(tr("用户自定义消息对话框实例"));
    label =new QLabel;
    label->setFrameStyle(QFrame::Panel|QFrame::Sunken);
    mainLayout->addWidget(CustomBtn,4,0);
    mainLayout->addWidget(label,4,1);
    connect(CustomBtn,SIGNAL(clicked()),this,SLOT(showCustomDlg()));
}

Dialog::~Dialog()
{

}

void Dialog::showFile()
{
    QString s = QFileDialog::getOpenFileName(this,"open file dialog",".",
                                             "c++ files(*.cpp);;c file(*.c);;Head files()*.h");
    fileLineEdit->setText(s);
}

void Dialog::showColor()
{
    QColor c = QColorDialog::getColor(Qt::blue);
    if(c.isValid())
    {
        //当前bai窗口构建一个调色板，它的button颜色为QColor
        colorFrame->setPalette(QPalette(c));
    }
}

void Dialog::showFont()
{
    bool ok;
    QFont f = QFontDialog::getFont(&ok);
    if (ok)
    {
        fontLineEdit->setFont(f);
    }
}

void Dialog::showInputDlg()
{
    inputDlg =new InputDlg(this);
    inputDlg->show();
}

void Dialog::showMsgDlg()
{
    msgDlg =new MsgBoxDlg();
    msgDlg->show();
}

void Dialog::showCustomDlg()
{
    label->setText(tr("Custom Message Box"));
    QMessageBox customMsgBox;
    customMsgBox.setWindowTitle(tr("用户自定义消息框"));	//设置消息框的标题




    //在下部加
    QPushButton *yesBtn= customMsgBox.addButton(tr("Yes"),QMessageBox:: ActionRole);	//(a)
    QPushButton *noBtn= customMsgBox.addButton(tr("No"),QMessageBox::ActionRole);
    QPushButton *cancelBtn= customMsgBox.addButton(QMessageBox::Cancel);
    //(b)

    //图片在左，文字在右，更换顺序没作用
    customMsgBox.setIconPixmap(QPixmap("Qt.png"));		//(d)
    customMsgBox.setText(tr("这是一个用户自定义消息框!"));	//(c)

    customMsgBox.exec();                                //显示此自定义消息框

    if(customMsgBox.clickedButton()==yesBtn)
        label->setText("Custom Message Box/Yes");
    if(customMsgBox.clickedButton()==noBtn)
        label->setText("Custom Message Box/No");
    if(customMsgBox.clickedButton()==cancelBtn)
        label->setText("Custom Message Box/Cancel");
    return;
}
