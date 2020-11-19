#include "digiclock.h"
#include <QTimer>
#include <QTime>
#include <QMouseEvent>
#include <QDebug>
DigiClock::DigiClock(QWidget *parent):QLCDNumber(parent)
{
    /* 设置时钟背景 */								//(a)
     QPalette p=palette();
     p.setColor(QPalette::Window,Qt::blue);
     setPalette(p);
     //设置窗口表示，设置为没有面板边框和标题栏的窗体
     setWindowFlags(Qt::FramelessWindowHint);	//(b)
     //设置半透明
     setWindowOpacity(0.5);						//(c)

     QTimer *timer=new QTimer(this);			//新建一个定时器对象
     connect(timer,SIGNAL(timeout()),this,SLOT(showTime()));	//(d)
     timer->start(1000);						//(e)
     showTime();								//初始时间显示
     resize(180,60);							//设置电子时钟显示的尺寸
     showColon=false;                            //初始化
}

void DigiClock::showTime()
{
    QTime time=QTime::currentTime();			//(a)
    QString text=time.toString("hh:mm:ss a");		//(b)

    if(showColon)								//(c)
    {
        text[2]=':';
        text[5]=':';
        showColon=false;
    }
    else
    {
        text[2]=' ';
        text[5]=' ';
        showColon=true;
    }
    qDebug() << text;
    setDigitCount(12);
    display(text);								//显示转换好的字符串时间
}

void DigiClock::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        dragPosition=event->globalPos()-frameGeometry().topLeft();
        event->accept();
    }
    if(event->button()==Qt::RightButton)
    {
        close();
    }
}

void DigiClock::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons()&Qt::LeftButton)
    {
        move(event->globalPos()-dragPosition);
        event->accept();
    }
}


