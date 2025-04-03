#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include <QByteArray>
#include <QString>
#include <QVector>
#include <QMap>

#define PORT 6000

class Server: public QObject
{
    Q_OBJECT
public:
    Server();
    ~Server();

private slots:
    void slotNewConnection();
    void slotClientDisconnected();
    void slotServerRead();

private:
    QTcpServer *tcpServer;
    QMap<int, QTcpSocket*> tcpSockets;

signals:
    void changeCountUsers();
};

#endif // SERVER_H
