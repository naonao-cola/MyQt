#ifndef THREADDLG_H
#define THREADDLG_H

#include <QDialog>
#include <QPushButton>
#include "workthread.h"
#define MAXSIZE 1

class ThreadDlg : public QDialog
{
    Q_OBJECT

public:
    ThreadDlg(QWidget *parent = 0);
    ~ThreadDlg();
public slots:
    void slotStart();
    void slotStop();

private:
    QPushButton *startBtn;
    QPushButton *stopBtn;
    QPushButton *quitBtn;
    WorkThread *workThread[MAXSIZE];
};

#endif // THREADDLG_H
