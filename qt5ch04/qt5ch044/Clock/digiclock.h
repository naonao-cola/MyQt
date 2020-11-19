#ifndef DIGICLOCK_H
#define DIGICLOCK_H
/*
重新定义了鼠标按下事件与鼠标移动事件，同时含有槽函数和私有变量
*/
#include <QLCDNumber>

class DigiClock : public QLCDNumber
{
    Q_OBJECT
 public:
     DigiClock(QWidget *parent=0);

     void mousePressEvent(QMouseEvent *);
     void mouseMoveEvent(QMouseEvent *);
 public slots:
     void showTime();            //显示当前的时间
 private:
     QPoint dragPosition;        //保存鼠标点相对电子时钟窗体左上角的偏移值
     bool showColon;             //用于显示时间时是否显示“：”
};

#endif // DIGICLOCK_H
