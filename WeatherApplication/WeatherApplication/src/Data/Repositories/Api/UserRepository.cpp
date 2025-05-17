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

QFuture<AuthorizationReply> UserRepository::findUser(const AuthorizationRequest &request)
{
    return sendRequest(request, "LOGIN");
}

QFuture<AuthorizationReply> UserRepository::registerUser(const AuthorizationRequest &request)
{
    return sendRequest(request, "REGISTER");
}

QFuture<AuthorizationReply> UserRepository::sendRequest(const AuthorizationRequest &user, const QString command) {
    QFutureInterface<AuthorizationReply> futureInterface;
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
        AuthorizationReply result;

        QByteArray response = reply->readAll();

        QJsonParseError error;
        QJsonDocument doc = QJsonDocument::fromJson(response, &error);
        if (error.error != QJsonParseError::NoError) {
            result = AuthorizationReply::failure("Ошибка парсинга JSON:" + error.errorString().toStdString());
        } else {
            if (!doc.isObject()) {
                result = AuthorizationReply::failure("JSON не является объектом");
            } else {
                result = AuthorizationReplyJsonConverter::parseAuthorizationReply(doc.object());
                if (result.authorized) {
                    sharedState_->setUsername(user.username);
                }
            }
        }

        futureInterface.reportResult(result);
        futureInterface.reportFinished();  // сигнализируем, что результат готов
        reply->deleteLater();
    });

    return futureInterface.future();
}


