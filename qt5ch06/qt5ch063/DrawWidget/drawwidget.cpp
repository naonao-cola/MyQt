#include "drawwidget.h"
#include <QPen>

DrawWidget::DrawWidget(QWidget *parent) : QWidget(parent)
{
    //窗体背景颜色
    setAutoFillBackground(true);
    setPalette(QPalette(Qt::white));
    pix =new QPixmap(size());  //接受绘制的内容
    pix->fill(Qt::white);      //填充白色背景
    setMinimumSize(600,400);    //设置最小尺寸
}

void DrawWidget::setStyle(int s){
    style = s;
}

void DrawWidget::setWidth(int w){
    weight = w;
}
void DrawWidget::setColor(QColor c){
    color = c;
}
void DrawWidget::mousePressEvent(QMouseEvent *e){
    startPos = e->pos();
}

void DrawWidget::mouseMoveEvent(QMouseEvent *e){
    QPainter *painter = new QPainter;  //新建QPainter对象
    QPen pen;                          //新建pen
    pen.setStyle((Qt::PenStyle)style);
    pen.setWidth(weight);              //线宽
    pen.setColor(color);                //颜色
    painter->begin(pix);               //画家拿起笔

    //绘制
    painter->drawLine(startPos,e->pos());
    painter->end();
    //更新位置
    startPos = e->pos();
    update();   //重新绘制
}

void DrawWidget::paintEvent(QPaintEvent *e){
    QPainter painter(this);
    painter.drawPixmap(QPoint(0,0),*pix);
}
void DrawWidget::resizeEvent(QResizeEvent *event){
    if(height() >pix->height() || width() > pix->width()){
        QPixmap *newPix = new QPixmap(size());
        newPix->fill(Qt::white);
        QPainter p(newPix);
        p.drawPixmap(QPoint(0,0),*pix);   // 在newPix中绘制原pix中内容
        pix = newPix;
    }
    QWidget::resizeEvent(event);
}

void DrawWidget::clear(){
    QPixmap *clearPix =new QPixmap(size());
    clearPix->fill(Qt::white);
    pix = clearPix;
    update();
}
