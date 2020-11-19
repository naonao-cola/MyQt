#include "watcher.h"
#include <QApplication>
#include "watcher.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Watcher w;
    w.show();

    return a.exec();
}
