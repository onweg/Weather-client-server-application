#ifndef HTTPSERVER_H
#define HTTPSERVER_H

#include <QCoreApplication>
#include <QDebug>
#include <QDir>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QTcpServer>
#include <QTcpSocket>

class HttpServer : public QTcpServer
{
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
	void sendHttpResponse(QTcpSocket *socket, const QJsonObject &response,
	                      int statusCode = 200);
};

#endif // HTTPSERVER_H
