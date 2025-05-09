#include "UserRepository.h"
#include "../../../Utils/AuthorizationInfoJsonConverter.h"
#include "../../../Utils/AuthorizationReplyJsonConverter.h"


#include <QString>
#include <QUrl>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QDebug>


UserRepository::UserRepository(std::shared_ptr<IConfigProvider> config,  std::shared_ptr<ISharedState> state, QObject *parent)
    : QObject(parent), configProvider_(std::move(config)), sharedState_(std::move(state))
{
    if (configProvider_) {
        serverHostConfig_ = configProvider_->getServerHostConfig();
    } else {
        serverHostConfig_ = Result<ServerHostConfig>::failure("Ну удалось получить IConfigProvider");
        qWarning() << "Ну удалось получить IConfigProvider";
    }
    networkManager_ = new QNetworkAccessManager(this);
}

void UserRepository::findUser(const User &user, std::function<void (Result<User>)> callback)
{
    sendRequest(user, std::move(callback), "LOGIN");
}

void UserRepository::registerUser(const User &user, std::function<void (Result<User>)> callback)
{
    sendRequest(user, std::move(callback), "REGISTER");
}

void UserRepository::sendRequest(const User &user, std::function<void (Result<User>)> callback, const QString command)
{
    if (serverHostConfig_.isSuccess()) {
        QString urlStr = "http://" + QString::fromStdString(serverHostConfig_.value().ip) + ":" + QString::fromStdString(serverHostConfig_.value().port);
        QUrl url(urlStr);
        QNetworkRequest request(url);
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        QByteArray data;
        if (command == "LOGIN") {
            data = AuthorizationInfoJsonConverter::loginUserToJsonDocument(user).toJson();
        } else if (command == "REGISTER") {
            data = AuthorizationInfoJsonConverter::registerUserToJsonDocument(user).toJson();
        } else {
            qDebug() << "Нет такой команды: " << command;
            return;
        }
        QNetworkReply* reply = networkManager_->post(request, data);

        QObject::connect(reply, &QNetworkReply::finished, this, [this, reply, user, callback]() {
            Result<User> result;

            QByteArray response = reply->readAll();

            QJsonParseError error;
            QJsonDocument doc = QJsonDocument::fromJson(response, &error);
            if (error.error != QJsonParseError::NoError) {
                result = Result<User>::failure("Ошибка парсинга JSON:" + error.errorString().toStdString());
            } else {
                if (!doc.isObject()) {
                    result = Result<User>::failure("JSON не является объектом");
                } else {
                    AuthorizationReply authorizationReply = AuthorizationReplyJsonConverter::parseAuthorizationReply(doc.object());
                    if (authorizationReply.success) {
                        sharedState_->setUsername(user.username);
                        result = Result<User>::success(user);
                    } else {
                        result = Result<User>::failure(authorizationReply.message);
                    }
                }
            }
            callback(result);
            reply->deleteLater();
        });
    }
}


