#include "tcpclientsocket.h"

TcpClientSocket::TcpClientSocket(QObject *parent)
{
    //QTcpSocket被看成一个QIODevice，readyread（）信号在有数据到来时发出
    connect(this,SIGNAL(readyRead()),this,SLOT(dataReceived()));

    //断开连接时触发
    connect(this,SIGNAL(disconnected()),this,SLOT(slotDisconnected()));
}

void TcpClientSocket::dataReceived(){

    while(bytesAvailable()>0)
    {
        int length = bytesAvailable();
        char buf[1024];
        read(buf,length);
        QString msg=buf;
        emit updateClients(msg,length);
    }
}
void TcpClientSocket::slotDisconnected()
{
    emit disconnected(this->socketDescriptor());
}
