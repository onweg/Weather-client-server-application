#include "UserRepository.h"
#include "../../Utils/AuthorizationInfoJsonConverter.h"


#include <QString>
#include <QUrl>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QDebug>


UserRepository::UserRepository(IConfigProvider *config, QObject *parent)
    : QObject(parent), configProvider_(config)
{
    qDebug() << 1;
    serverHostConfig_ = config->getServerHostConfig();
    qDebug() << 2;
    networkManager_ = new QNetworkAccessManager(this);
    qDebug() << 3;
}

void UserRepository::findUser(const User &user, std::function<void (Result<User>)> callback)
{
    qDebug() << "UserRepository::findUser";
    if (serverHostConfig_.isSuccess()) {
        qDebug() << "serverHostConfig_.isSuccess()";
        QString urlStr = "http://" + QString::fromStdString(serverHostConfig_.value().ip) + ":" + QString::fromStdString(serverHostConfig_.value().port);
        QUrl url(urlStr);
        QNetworkRequest request(url);
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        QByteArray data = AuthorizationInfoJsonConverter::loginUserToJsonDocument(user).toJson();
        networkManager_->post(request, data);

        QObject::connect(networkManager_, &QNetworkAccessManager::finished, this, [callback, &user](QNetworkReply* reply) {
            Result<User> result;
            if (reply->error() == QNetworkReply::NoError) {
                qDebug() << "Result<User>::success(user);";
                result = Result<User>::success(user);
            } else {
                qDebug() << "Result<User>::failure(reply->errorString().toStdString()";
                result = Result<User>::failure(reply->errorString().toStdString());
            }
        });
    }
}

//void UserRepository::registerUser(const User &user)
//{

//}

