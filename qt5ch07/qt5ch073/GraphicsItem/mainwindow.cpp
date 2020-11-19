#include "mainwindow.h"
#include "flashitem.h"
#include "startitem.h"
#include <QGraphicsItemAnimation>
#include <QTimeLine>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    createActions();                            //创建动作
    createMenus();                              //创建菜单
    scene = new QGraphicsScene;
    scene->setSceneRect(-200,-200,400,400);
    initScene();                                //初始化场景
    //视图
    QGraphicsView *view =new QGraphicsView;
    view->setScene(scene);                      //设置显示的场景
    view->setMinimumSize(400,400);
    view->show();
    setCentralWidget(view);
    resize(550,450);
    setWindowTitle(tr("Grapgics Items"));
}

MainWindow::~MainWindow()
{

}
void MainWindow::createActions(){
    newAct = new QAction(tr("新建"),this);
    clearAct = new QAction(tr("清除"),this);
    exitAct =new QAction(tr("退出"),this);
    addEllipseItemAct =new QAction(tr("加入椭圆"),this);
    addPolygonItemAct = new QAction(tr("加入 多边形"),this);
    addTextItemAct = new QAction(tr("加入文字"),this);
    addRectItemAct = new QAction(tr("加入 长方形"),this);
    addAlphaItemAct = new QAction(tr("加入 透明图片"),this);

    addFlashItemAct = new QAction(tr("加入闪烁圆"),this);
    addAnimItemAct = new  QAction(tr("加入 星星"),this);
    //连接槽信号
    connect(newAct,&QAction::triggered,this,&MainWindow::slotNew);
    connect(clearAct,&QAction::triggered,this,&MainWindow::slotClear);
    connect(exitAct,&QAction::triggered,this,&MainWindow::close);
    connect(addEllipseItemAct,&QAction::triggered,this,&MainWindow::slotAddEllipseItem);
    connect(addPolygonItemAct,&QAction::triggered,this,&MainWindow::slotAddPolygonItem);
    connect(addTextItemAct,&QAction::triggered,this,&MainWindow::slotAddTextItem);
    connect(addRectItemAct,&QAction::triggered,this,&MainWindow::slotAddRectItem);
    connect(addAlphaItemAct,&QAction::triggered,this,&MainWindow::slotAddAlphaItem);

    connect(addFlashItemAct,&QAction::triggered,this,&MainWindow::slotAddFlashItem);
    connect(addAnimItemAct,&QAction::triggered,this,&MainWindow::slotAddAnimationItem);
}

//创建菜单
void MainWindow::createMenus(){

    //文件
    QMenu *fileMenu = menuBar()->addMenu(tr("文件"));
    fileMenu->addAction(newAct);
    fileMenu->addAction(clearAct);
    fileMenu->addSeparator();                       //分割线
    fileMenu->addAction(exitAct);

    //元素
    QMenu *itemsMenu =menuBar()->addMenu(tr("元素"));
    itemsMenu->addAction(addEllipseItemAct);
    itemsMenu->addAction(addPolygonItemAct);
    itemsMenu->addAction(addTextItemAct);
    itemsMenu->addAction(addRectItemAct);
    itemsMenu->addAction(addAlphaItemAct);

    itemsMenu->addAction(addFlashItemAct);
    itemsMenu->addAction(addAnimItemAct);


}
//初始化场景
void MainWindow::initScene(){

    int i;
    for(i = 0;i<3;i++)
        slotAddEllipseItem();
    for(i=0;i<3;i++)
        slotAddPolygonItem();
    for(i=0;i<3;i++)
        slotAddTextItem();
    for(i=0;i<3;i++)
        slotAddRectItem();
    for(i=0;i<3;i++)
        slotAddAlphaItem();
    for(i=0;i<3;i++)
        slotAddFlashItem();
    for(i=0;i<3;i++)
        slotAddAnimationItem();

}

//新建窗体
void MainWindow::slotNew(){
    slotClear();
    initScene();
    MainWindow *newWin = new MainWindow;
    newWin->show();
}
//清除图元
//at比[]更快，不需要深拷贝
void MainWindow::slotClear(){
    QList<QGraphicsItem*> listItem = scene->items();
    while(!listItem.empty()){
        scene->removeItem(listItem.at(0));
        listItem.removeAt(0);
    }
}
//加椭圆
void MainWindow::slotAddEllipseItem(){
    QGraphicsEllipseItem *item = new QGraphicsEllipseItem(QRectF(0,0,80,60));
    item->setPen(Qt::NoPen);
    item->setBrush(QColor(qrand()%256,qrand()%256,qrand()%256));
    item->setFlag(QGraphicsItem::ItemIsMovable);
    scene->addItem(item);

    item->setPos((qrand()%int(scene->sceneRect().width()))-200,
                 (qrand()%int(scene->sceneRect().height()))-200);
}
//加多边形
void MainWindow::slotAddPolygonItem(){
    QVector<QPoint> v;                        //多边形的点
    v<<QPoint(30,-15)<<QPoint(0,-30)<<QPoint(-30,-15)
    <<QPoint(-30,15)<<QPoint(0,30)<<QPoint(30,15);

    QGraphicsPolygonItem *item = new QGraphicsPolygonItem(QPolygonF(v));
    item->setBrush(QColor(qrand()%256,qrand()%256,qrand()%256));
    item->setFlag(QGraphicsItem::ItemIsMovable);
    scene->addItem(item);
    //位置
    item->setPos((qrand()%int(scene->sceneRect().width()))-200,
                 (qrand()%int(scene->sceneRect().height()))-200);
}
//加文字
void MainWindow::slotAddTextItem(){
    QFont font("Times",16);
    QGraphicsTextItem *item =new QGraphicsTextItem("Hello Qt");

    item->setFont(font);
    item->setDefaultTextColor(QColor(qrand()%256,qrand()%256,qrand()%256));
    item->setFlag(QGraphicsItem::ItemIsMovable);
    scene->addItem(item);
    //位置
    item->setPos((qrand()%int(scene->sceneRect().width()))-200,
                 (qrand()%int(scene->sceneRect().height()))-200);
}
//加长方形
void MainWindow::slotAddRectItem(){
    QGraphicsRectItem *item = new QGraphicsRectItem(QRectF(0,0,60,60));

    //设置笔
    QPen pen;
    pen.setWidth(3);
    pen.setColor(QColor(qrand()%256,qrand()%256,qrand()%256));

    item->setPen(pen);
    item->setBrush(QColor(qrand()%256,qrand()%256,qrand()%256));
    item->setFlag(QGraphicsItem::ItemIsMovable);
    scene->addItem(item);
    //位置
    item->setPos((qrand()%int(scene->sceneRect().width()))-200,
                 (qrand()%int(scene->sceneRect().height()))-200);

}
//添加图像
void MainWindow::slotAddAlphaItem(){
    QGraphicsPixmapItem *item =scene->addPixmap(QPixmap("image.png"));
    item->setFlag(QGraphicsItem::ItemIsMovable);
    //位置
    item->setPos((qrand()%int(scene->sceneRect().width()))-200,
                 (qrand()%int(scene->sceneRect().height()))-200);
}

//加入闪烁图元
void MainWindow::slotAddFlashItem(){
    FlashItem *item =new FlashItem;
    scene->addItem(item);
    item->setPos((qrand()%int(scene->sceneRect().width()))-200,
                 (qrand()%int(scene->sceneRect().height()))-200);
}
//加入星星
void MainWindow::slotAddAnimationItem(){
    StartItem *item =new StartItem;
    QGraphicsItemAnimation *anim =new QGraphicsItemAnimation;

    anim->setItem(item);
    QTimeLine *timeLine = new QTimeLine(4000);
    timeLine->setCurveShape(QTimeLine::SineCurve);
    timeLine->setLoopCount(0);
    anim->setTimeLine(timeLine);

    int y = (qrand()%400)-200;
    for(int i =0;i<400;i++){
        anim->setPosAt(i/400.0,QPointF(i-200,y));
    }
    timeLine->start();
    scene->addItem(item);
}



















