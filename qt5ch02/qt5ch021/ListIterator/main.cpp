#include <QCoreApplication>
#include <QDebug>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

//    QList<int> list;
//    list<<1<<2<<3<<4<<5;
//    //以该list为参数初始化一个QListIterator对象i。此时，迭代点处在第一个列表项“1”的前面
//    QListIterator<int> i(list);
//    for(;i.hasNext();)
//        qDebug()<<i.next();

    QList<int> list;
    QMutableListIterator<int> i(list);
    for(int j=0;j<10;++j)
        i.insert(j);

    for(i.toFront();i.hasNext();)
            qDebug()<<i.next();
        for(i.toBack();i.hasPrevious();)
        {
            if(i.previous()%2==0)
                i.remove();
            else
                i.setValue(i.peekNext()*10);
        }
        for(i.toFront();i.hasNext();)
            qDebug()<<i.next();

    return a.exec();
}
