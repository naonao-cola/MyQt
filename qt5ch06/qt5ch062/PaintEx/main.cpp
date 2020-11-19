#include "mainwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
       QFont f("ZYSong18030",12);
       a.setFont(f);

       MainWidget w;
       w.show();

    return a.exec();
}
