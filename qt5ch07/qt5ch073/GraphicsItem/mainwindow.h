#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMenuBar>
#include <QGraphicsEllipseItem>
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void initScene();     //初始化场景
    void createActions(); //创建主窗体的动作
    void createMenus();   //创建主窗体菜单栏
public slots:
    void slotNew();       //新建一个窗体
    void slotClear();     //清除所有图元
    void slotAddEllipseItem();//加入椭圆
    void slotAddPolygonItem();//加入多边形
    void slotAddTextItem();   //加入文字
    void slotAddRectItem();   //加入矩形
    void slotAddAlphaItem();  //加入蝴蝶
private:
    QGraphicsScene *scene;
    QAction *newAct;
    QAction *clearAct;
    QAction *exitAct;
    QAction *addEllipseItemAct;
    QAction *addPolygonItemAct;
    QAction *addTextItemAct;
    QAction *addRectItemAct;
    QAction *addAlphaItemAct;
public slots:
    void slotAddFlashItem();
    void slotAddAnimationItem();
private:
    QAction *addFlashItemAct;
    QAction *addAnimItemAct;
};

#endif // MAINWINDOW_H
