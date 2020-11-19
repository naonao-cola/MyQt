#ifndef KEYEVENT_H
#define KEYEVENT_H

#include <QWidget>
#include <QKeyEvent>
#include <QPaintEvent>

class KeyEvent : public QWidget
{
    Q_OBJECT

public:
    KeyEvent(QWidget *parent = 0);
    ~KeyEvent();
    void drawPix();
    void keyPressEvent(QKeyEvent*);
    void paintEvent(QPaintEvent *);

private:
    QPixmap *pix;
    QImage image;

    //图标左上顶点位置
     int startX;
     int startY;
     //界面高度
     int width;
     int height;
     //网格大小
     int step;
};

#endif // KEYEVENT_H
