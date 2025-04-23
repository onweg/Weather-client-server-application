#ifndef HTTPSERVER_H
#define HTTPSERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
#include <QFile>
#include <QDir>
#include <QCoreApplication>


class HttpServer : public QTcpServer {
    Q_OBJECT
public:
    HttpServer(QObject *parent = nullptr);
    bool start(quint16 port);

protected:
    void incomingConnection(qintptr socketDescriptor) override;

private slots:
    void handleReadyRead();
    void handleDisconnected();

private:
    QSqlDatabase db;
    bool connectToDatabase();
    void processRequest(QTcpSocket *socket, const QByteArray &data);
    void processLogin(QTcpSocket *socket, const QJsonObject &obj);
    void processRegister(QTcpSocket *socket, const QJsonObject &obj);
    void sendHttpResponse(QTcpSocket *socket, const QJsonObject &response, int statusCode = 200);
};


#endif // HTTPSERVER_H
