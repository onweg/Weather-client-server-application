#include "httpserver.h"
#include <QCryptographicHash>
#include <QCoreApplication>
#include <QString>

HttpServer::HttpServer(QObject *parent) : QTcpServer(parent) {

}

bool HttpServer::start(quint16 port) {
    if (!connectToDatabase()) {
        qDebug() << "Не удалось подключиться к базе данных";
        return false;
    }
    if (!this->listen(QHostAddress::Any, port)) {
        qDebug() << "Не удалось запустить сервер на порту" << port;
        return false;
    } else {
        qDebug() << "Сервер запущен на порту" << port;
        return true;
    }
}

void HttpServer::incomingConnection(qintptr socketDescriptor) {
    QTcpSocket *socket = new QTcpSocket(this);
    socket->setSocketDescriptor(socketDescriptor);
    qDebug() << "Новое подлкючение с дескриптором: " << socket->socketDescriptor();

    //connect(socket, &QTcpSocket::readyRead, this, &HttpServer::handleReadyRead);
    connect(socket, &QTcpSocket::readyRead, this, [=]() mutable {
        static QByteArray buffer;

        buffer += socket->readAll();

        if (!buffer.contains("\r\n\r\n"))
            return;

        int headerEnd = buffer.indexOf("\r\n\r\n");
        int contentLength = 0;

        QList<QByteArray> headers = buffer.left(headerEnd).split('\n');
        for (const QByteArray &line : headers) {
            if (line.toLower().startsWith("content-length:")) {
                contentLength = line.split(':').last().trimmed().toInt();
                break;
            }
        }

        int totalSize = headerEnd + 4 + contentLength;
        if (buffer.size() < totalSize)
            return; // ждём остальное

        QByteArray fullRequest = buffer.left(totalSize);
        buffer.clear();  // reset

        processRequest(socket, fullRequest);
    });

    connect(socket, &QTcpSocket::disconnected, this, &HttpServer::handleDisconnected);
}

void HttpServer::handleReadyRead() {
    QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());
    QByteArray requestData = socket->readAll();
    qDebug() << "Пришел новый запрос";
    processRequest(socket, requestData);
}

void HttpServer::handleDisconnected() {
    QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());
    socket->deleteLater();
}

void HttpServer::processRequest(QTcpSocket *socket, const QByteArray &data) {
    QString request = QString::fromUtf8(data);
    int headerEndIndex = request.indexOf("\r\n\r\n");
    if (headerEndIndex == -1) {
        socket->disconnectFromHost();
        return;
    }

    QByteArray body = data.mid(headerEndIndex + 4);
    qDebug() << "BODY decoded:\n" << QString::fromUtf8(body);


    QJsonParseError parseError;
    QJsonDocument doc = QJsonDocument::fromJson(body, &parseError);
    if (parseError.error != QJsonParseError::NoError || !doc.isObject()) {
        QJsonObject errorObj;
        errorObj["status"] = "error";
        errorObj["message"] = "Неверный JSON";
        sendHttpResponse(socket, errorObj, 400);
        return;
    }

    QJsonObject obj = doc.object();
    QString command = obj.value("command").toString();

    if (command == "LOGIN") {
        processLogin(socket, obj);
    } else if (command == "REGISTER") {
        processRegister(socket, obj);
    } else {
        QJsonObject errorObj;
        errorObj["status"] = "error";
        errorObj["message"] = "Неизвестная команда";
        sendHttpResponse(socket, errorObj, 400);
    }
}

void HttpServer::processLogin(QTcpSocket *socket, const QJsonObject &obj) {
    QString login = obj.value("login").toString();
    QString password = obj.value("password").toString();

    QByteArray passwordHash = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Md5).toHex();

    QSqlQuery query(db);
    query.prepare("SELECT COUNT(*) FROM users WHERE username = :username AND password_hash = :password");
    query.bindValue(":username", login);
    query.bindValue(":password", QString(passwordHash)); // передаём хеш в строковом виде

    if (!query.exec() || !query.next() || query.value(0).toInt() == 0) {
        QJsonObject error;
        error["status"] = "error";
        error["message"] = "Неверный логин или пароль";
        sendHttpResponse(socket, error, 401);
        return;
    }

    QJsonObject ok;
    ok["status"] = "success";
    ok["message"] = "Авторизация успешна";
    sendHttpResponse(socket, ok);
}


void HttpServer::processRegister(QTcpSocket *socket, const QJsonObject &obj) {
    QString login = obj.value("login").toString();
    QString password = obj.value("password").toString();

    if (login.isEmpty() || password.isEmpty()) {
        QJsonObject error;
        error["status"] = "error";
        error["message"] = "Логин и пароль не должны быть пустыми";
        sendHttpResponse(socket, error, 400);
        return;
    }

    QByteArray hash = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Md5);
    QString passwordMd5 = hash.toHex();

    QSqlQuery checkQuery(db);
    checkQuery.prepare("SELECT COUNT(*) FROM users WHERE username = :username");
    checkQuery.bindValue(":username", login);
    if (!checkQuery.exec() || !checkQuery.next()) {
        QJsonObject error;
        error["status"] = "error";
        error["message"] = "Ошибка запроса";
        sendHttpResponse(socket, error, 500);
        return;
    }
    if (checkQuery.value(0).toInt() > 0) {
        QJsonObject exists;
        exists["status"] = "error";
        exists["message"] = "Пользователь уже существует";
        sendHttpResponse(socket, exists, 409);
        return;
    }

    QSqlQuery insertQuery(db);
    insertQuery.prepare("INSERT INTO users (username, password_hash) VALUES (:username, :password)");
    insertQuery.bindValue(":username", login);
    insertQuery.bindValue(":password", passwordMd5);
    if (!insertQuery.exec()) {
        QJsonObject fail;
        fail["status"] = "error";
        fail["message"] = "Ошибка при регистрации";
        sendHttpResponse(socket, fail, 500);
        return;
    }

    QJsonObject success;
    success["status"] = "success";
    success["message"] = "Регистрация успешна";
    sendHttpResponse(socket, success);
}

void HttpServer::sendHttpResponse(QTcpSocket *socket, const QJsonObject &response, int statusCode) {
    QJsonDocument doc(response);
    QByteArray body = doc.toJson(QJsonDocument::Compact);

    QString statusText = (statusCode == 200) ? "OK" :
                             (statusCode == 400) ? "Bad Request" :
                             (statusCode == 401) ? "Unauthorized" :
                             (statusCode == 409) ? "Conflict" :
                             "Internal Server Error";

    QByteArray header = "HTTP/1.1 " + QByteArray::number(statusCode) + " " + statusText.toUtf8() + "\r\n";
    header += "Content-Type: application/json; charset=utf-8\r\n"; // Указываем кодировку UTF-8
    header += "Content-Length: " + QByteArray::number(body.size()) + "\r\n";
    header += "Connection: close\r\n\r\n";

    socket->write(header + body);
    socket->flush();
    socket->disconnectFromHost();
}

#ifdef USE_STRICT_CONFIG_PATH
QString getConfigPath() {
    qDebug() << "App dir:" << QCoreApplication::applicationDirPath();
    QString configPath = QCoreApplication::applicationDirPath() + "/db_config.json";
    if (!QFile::exists(configPath)) {
        qWarning() << "Config file not found at" << configPath;
        return {};
    }
    return configPath;
}
#else
QString getConfigPath() {
    qDebug() << "App dir:" << QCoreApplication::applicationDirPath();
    QDir dir(QCoreApplication::applicationDirPath());
    while (!dir.exists("db_config.json") && dir.cdUp()) {}
    QString configPath = dir.filePath("db_config.json");
    if (!QFile::exists(configPath)) {
        qWarning() << "Config file not found at" << configPath;
        return {};
    }
    return configPath;
}
#endif


bool HttpServer::connectToDatabase() {
    QString configPath = getConfigPath();
    if (configPath.isEmpty()) {
        qDebug() << "Не удалось найти конфигурационный файл";
        return false;
    }

    QFile configFile(configPath);
    if (!configFile.open(QIODevice::ReadOnly)) {
        qDebug() << "Не удалось открыть файл конфигурации";
        return false;
    }

    QByteArray jsonData = configFile.readAll();
    configFile.close();

    QJsonDocument doc = QJsonDocument::fromJson(jsonData);
    if (doc.isNull()) {
        qDebug() << "Не удалось парсить JSON файл";
        return false;
    }

    QJsonObject jsonObject = doc.object();
    QString host = jsonObject.value("host").toString();
    int port = jsonObject.value("port").toInt();
    QString dbname = jsonObject.value("database").toString();
    QString username = jsonObject.value("username").toString();
    QString password = jsonObject.value("password").toString();

    if (port == 0) {
        qDebug() << "Порт из конфигурации равен 0, возможно ошибка в файле";
        return false;
    }

    db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName(host);
    db.setPort(port);
    db.setDatabaseName(dbname);
    db.setUserName(username);
    db.setPassword(password);

    if (!db.open()) {
        qDebug() << "Ошибка подключения к БД:" << db.lastError().text();
        return false;
    }

    return true;
}
