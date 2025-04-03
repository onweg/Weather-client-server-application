#include "server.h"

Server::Server()
{
    tcpServer = new QTcpServer(this);

    connect(tcpServer, &QTcpServer::newConnection, this, &Server::slotNewConnection);

    if (!tcpServer->listen(QHostAddress::Any, PORT
                           ))
    {
        qDebug() << "server is not started";
    }
    else
    {
        qDebug() << "server is started";
    }
}

Server::~Server()
{
    for (auto it = tcpSockets.begin(); it != tcpSockets.end(); ++it) {
        it.value()->disconnect();
        it.value()->close();
        it.value()->deleteLater();
    }
    tcpSockets.clear();

    qDebug() << "Сервер завершил работу";
}

void Server::slotNewConnection()
{
    QTcpSocket *socket = tcpServer->nextPendingConnection();

    int clientId = static_cast<int>(socket->socketDescriptor());

    connect(socket, &QTcpSocket::readyRead, this, &Server::slotServerRead);
    connect(socket, &QTcpSocket::disconnected, this, &Server::slotClientDisconnected);

    tcpSockets[clientId] = socket;

    qDebug() << "Клиент подлкючился" << static_cast<int>(socket->socketDescriptor());
}

void Server::slotServerRead()
{
    QTcpSocket *socket = qobject_cast<QTcpSocket*>(sender());

    if (!socket) { return; }
    QByteArray data = socket->readAll();
    QString requestData = QString::fromUtf8(data);
    int id = static_cast<int>(socket->socketDescriptor());

}

void Server::slotClientDisconnected()
{
    QTcpSocket *socket = qobject_cast<QTcpSocket*>(sender());
    if (!socket) return;

    int clientId = -1;
    for (auto it = tcpSockets.begin(); it != tcpSockets.end(); ++it) {
        if (it.value() == socket) {
            clientId = it.key();
            break;
        }
    }

    if (clientId != -1) {
        tcpSockets.remove(clientId);
        qDebug() << "Клиент отключен: " << clientId;
    }

    socket->deleteLater();
}
