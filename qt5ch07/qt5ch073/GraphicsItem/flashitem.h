#ifndef FLASHITEM_H
#define FLASHITEM_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
class FlashItem : public QObject,public QGraphicsItem
{
    Q_OBJECT
public:
    explicit FlashItem(QObject *parent = nullptr);
    QRectF boundingRect() const;   //继承图元类，必须实现此函数
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);
    void timerEvent(QTimerEvent *);
private:
    bool flash;
    QTimer *timer;

signals:

public slots:

};

#endif // FLASHITEM_H
