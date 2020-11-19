#include "server.h"

Server::Server(QObject *parent,int port):QTcpServer (parent)
{
    //指定端口任意地址进行监听
    listen(QHostAddress::Any,port);
}

//出现先连接时，触发
void Server::incomingConnection(int socketDescriptor)
{
    //创建新的套接字
    TcpClientSocket *tcpClientSocket = new TcpClientSocket(this);
    connect(tcpClientSocket,SIGNAL(updateClients(QString,int)),
            this,SLOT(updateClients(QString,int)));

    connect(tcpClientSocket,SIGNAL(disconnected(int)),
            this,SLOT(slotDisconnected(int)));

    tcpClientSocket->setSocketDescriptor(socketDescriptor);
    tcpClientSocketList.append(tcpClientSocket);


}
void Server::updateClients(QString msg,int length)
{
    //通知服务器更新
    emit updateServer(msg,length);
    for(int i =0;i<tcpClientSocketList.count();i++)
    {
        //实现信息广播
        QTcpSocket *item =tcpClientSocketList.at(i);
        if(item->write(msg.toLatin1(),length)!=length)
        {
            continue;
        }
    }

}
void Server::slotDisconnected(int descriptor)
{

    for (int i =0;i<tcpClientSocketList.count();i++)
    {
        QTcpSocket *item = tcpClientSocketList.at(i);
        if(item->socketDescriptor()==descriptor)
        {
            tcpClientSocketList.removeAt(i);
            return;
        }

    }
    return;
}
