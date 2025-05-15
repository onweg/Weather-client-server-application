#include "UserRepository.h"
#include "../../../Utils/AuthorizationInfoJsonConverter.h"
#include "../../../Utils/AuthorizationReplyJsonConverter.h"


#include <QString>
#include <QUrl>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QDebug>

#include <QFutureInterface>
#include <QFuture>


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

QFuture<Result<User>> UserRepository::findUser(const User &user)
{
    return sendRequest(user, "LOGIN");
}

QFuture<Result<User>> UserRepository::registerUser(const User &user)
{
    return sendRequest(user, "REGISTER");
}

QFuture<Result<User>> UserRepository::sendRequest(const User &user, const QString command) {
    QFutureInterface<Result<User>> futureInterface;
    futureInterface.reportStarted();


    if (!serverHostConfig_.isSuccess()) {
        futureInterface.reportFinished();
        return futureInterface.future();
    }

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
        futureInterface.reportFinished();
        return futureInterface.future(); // Ошибка - неизвестная команда
    }

    QNetworkReply* reply = networkManager_->post(request, data);

    QObject::connect(reply, &QNetworkReply::finished, this, [this, reply, user, futureInterface]() mutable {
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

        futureInterface.reportResult(result);
        futureInterface.reportFinished();  // сигнализируем, что результат готов
        reply->deleteLater();
    });

    return futureInterface.future();
}


