#ifndef MAPWIDGET_H
#define MAPWIDGET_H
#include<QGraphicsView>
#include <QLabel>
#include <QMouseEvent>
class MapWidget : public QGraphicsView
{
    Q_OBJECT
public:
    MapWidget();
    //读取地图信息
    void readMap();
    //场景坐标与地图自标的转换
    QPointF mapToMap(QPointF);
public slots:
    void slotZoom(int);
protected:
    //地图显示
    void drawBackground(QPainter *painter, const QRectF &rect);

    void mouseMoveEvent(QMouseEvent *event);
private:
    QPixmap map;
    qreal zoom;
    QLabel *viewCoord;
    QLabel *sceneCoord;
    QLabel *mapCoord;
    double x1,y1;
    double x2,y2;

};

#endif // MAPWIDGET_H
