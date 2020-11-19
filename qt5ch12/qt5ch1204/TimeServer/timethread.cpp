#include "timethread.h"
#include <QDateTime>
#include <QByteArray>
#include <QDataStream>

TimeThread::TimeThread(qintptr socketDescriptor,QObject *parent)
    :QThread(parent),socketDescriptor(socketDescriptor)
{

}

void TimeThread::run()
{

    QTcpSocket tcpSocket;
    if(!tcpSocket.setSocketDescriptor(socketDescriptor))
    {
        emit error(tcpSocket.error());
        return;
    }
    QByteArray block;
    QDataStream out(&block,QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_11);

    uint time2u = QDateTime::currentDateTime().toTime_t();
    out<<time2u;

    //获取时间
    tcpSocket.write(block);
    //断开连接
    tcpSocket.disconnectFromHost();
    //等待返回
    tcpSocket.waitForDisconnected();
}
