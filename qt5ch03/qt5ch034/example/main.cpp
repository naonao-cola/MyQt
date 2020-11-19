#include "content.h"
#include <QApplication>
#include <QTextCodec>
#include <QSplitter>
#include <QListWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFont font("AR PL KaitiM GB",12);	//设置整个程序采用的字体与字号
    a.setFont(font);

    //新建一个水平分割窗对象，作为主布局框
    QSplitter *splitterMain =new QSplitter(Qt::Horizontal,0);
    //设定分隔条在拖拽时是否实时更新
    splitterMain->setOpaqueResize(true);

    //左侧插入条目
    QListWidget *list =new QListWidget(splitterMain);	//(a)
    list->insertItem(0,QObject::tr("基本信息"));
    list->insertItem(1,QObject::tr("联系方式"));
    list->insertItem(2,QObject::tr("详细资料"));
    //右侧插入详情页
    Content *content =new Content(splitterMain);		//(b)
    //连接槽函数
    QObject::connect(list,SIGNAL(currentRowChanged(int)),content->stack,
                     SLOT(setCurrentIndex(int)));						//(c)

    //设置主布局框即水平分割窗的标题
    splitterMain->setWindowTitle(QObject::tr("修改用户资料"));
    //设置主布局框即水平分割窗的最小尺寸
    splitterMain->setMinimumSize(splitterMain->minimumSize());
    //设置主布局框即水平分割窗的最大尺寸
    splitterMain->setMaximumSize(splitterMain->maximumSize());
    splitterMain->show();	//显示主布局框，其上面的控件一同显示

//    Content w;
//    w.show();

    return a.exec();
}
