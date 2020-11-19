#ifndef WATCHER_H
#define WATCHER_H

#include <QWidget>
#include <QLabel>
#include <QFileSystemWatcher>
class Watcher : public QWidget
{
    Q_OBJECT

public:
    Watcher(QWidget *parent = 0);
    ~Watcher();
public slots:
    //改变或删除
    void directoryChanged(QString path);
private:
    QLabel *pathLabel;
    //监视文件和目录的改变
    QFileSystemWatcher fsWatcher;
};

#endif // WATCHER_H
