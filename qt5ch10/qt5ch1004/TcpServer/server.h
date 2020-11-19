#ifndef SERVER_H
#define SERVER_H
#include <QTcpServer>
#include <QObject>
#include <tcpclientsocket.h>
/*
实现TCP的协议服务器
*/

class Server : public QTcpServer
{
    Q_OBJECT //为了实现信号与槽的通信
public:
    Server(QObject *parent,int port=0);
    //保存与每一个客户端连接的tcpClientSocket
    QList<TcpClientSocket*> tcpClientSocketList;
signals:
    void updateServer(QString,int);
public slots:
    void updateClients(QString,int);
    void slotDisconnected(int);
protected:
    void incomingConnection (int socketDescriptor);
};

#endif // SERVER_H
