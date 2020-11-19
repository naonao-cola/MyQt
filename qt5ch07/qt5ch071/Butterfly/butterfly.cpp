#include "butterfly.h"
#include <math.h>
const static double PI=3.141592653;

Butterfly::Butterfly(QObject *parent) : QObject(parent)
{
    up=true;
    pix_up.load("up.png");
    pix_down.load("down.png");
    startTimer(1000);            //启动定时器，100毫秒
}
QRectF Butterfly::boundingRect() const{
    qreal adjust =2;
    return QRectF(-pix_up.width() / 2 - adjust, -pix_up.height() / 2 - adjust,
                   pix_up.width() + adjust * 2, pix_up.height() + adjust * 2);
}
void Butterfly::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){

    if(up){
        painter->drawPixmap(boundingRect().topLeft(),pix_up);
        up = !up;
    }
    else {
        painter->drawPixmap(boundingRect().topLeft(),pix_down);
        up = !up;
    }
}
void Butterfly::timerEvent(QTimerEvent *){

    //边界
    //右边界
    qreal edgex = scene()->sceneRect().right() + boundingRect().width() /2;
    //上边界
    qreal edgetop = scene()->sceneRect().top() +boundingRect().height() /2;
    //下边界
    qreal edgebottom = scene()->sceneRect().bottom() +boundingRect().height() /2;
    //超右边界
    if(pos().x()>=edgex){
        setPos(scene()->sceneRect().left(),pos().y());
    }
    //超上边界
    if(pos().y()<= edgetop)
        setPos(pos().x(),scene()->sceneRect().bottom());
    //超下边界
    if(pos().y() >= edgebottom)
        setPos(pos().x(),scene()->sceneRect().top());

    angle += (qrand()%10)/20.0;
    //随机飞行路径
    qreal dx=fabs(sin(angle*PI)*10.0);
    qreal dy=(qrand()%20)-10.0;
    //映射为场景坐标
    setPos(mapToParent(dx,dy));
}
