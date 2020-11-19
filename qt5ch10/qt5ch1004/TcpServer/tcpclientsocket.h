#ifndef TCPCLIENTSOCKET_H
#define TCPCLIENTSOCKET_H
#include <QTcpSocket>
#include <QObject>
/*
创建 套接字，以便在服务器端实现与客户端程序的通信
*/
class TcpClientSocket : public QTcpSocket
{
    Q_OBJECT   //为了实现信号与槽的通信
public:
    TcpClientSocket(QObject *parent =0);
signals:
    void updateClients(QString ,int);
    void disconnected(int);
protected slots:

    void dataReceived();
    void slotDisconnected();

};

#endif // TCPCLIENTSOCKET_H
