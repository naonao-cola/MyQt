#ifndef BUTTERFLY_H
#define BUTTERFLY_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsView>
class Butterfly : public QObject,public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Butterfly(QObject *parent = nullptr);
    void timerEvent(QTimerEvent*); // 定时器
    QRectF boundingRect() const;   //图元限定范围，必须实现此函数
signals:

public slots:
protected:
    //重回函数
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget);
private:
    bool up;   //上下标志
    QPixmap pix_up;
    QPixmap pix_down;  //蝴蝶图片
    qreal angle;
};

#endif // BUTTERFLY_H
