#include "mainwindow.h"
#include <QApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator *translator = new QTranslator;
    translator->load("I:/charon/mydemo/measurement/MfcQt/QT/QT5/qt5ch15/qt5ch1501/TestHello/TestHello.qm");
    a.installTranslator(translator);

    MainWindow w;
    w.show();

    return a.exec();
}
