#include "UserRepository.h"
#include "../../../Utils/AuthorizationInfoJsonConverter.h"
#include "../../../Utils/AuthorizationReplyJsonConverter.h"

#include <QUrl>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QEventLoop>
#include <stdexcept>

UserRepository::UserRepository(std::shared_ptr<IConfigProvider> config,
                               std::shared_ptr<ISharedState> state,
                               QObject* parent)
    : QObject(nullptr),
      configProvider_(std::move(config)),
      sharedState_(std::move(state))
{
    auto result = configProvider_->getServerHostConfig();
    if (!result.isSuccess()) {
        throw std::runtime_error("Не удалось получить данные из config файла");
    }
    serverHostConfig_ = result.value();
    networkManager_ = new QNetworkAccessManager(this);
}

std::future<AuthorizationReply> UserRepository::findUser(const AuthorizationRequest& request) {
    AuthorizationCommand command{request, AuthorizationCommand::Type::Login};
    return sendRequest(command);
}

std::future<AuthorizationReply> UserRepository::registerUser(const AuthorizationRequest& request) {
    AuthorizationCommand command{request, AuthorizationCommand::Type::Register};
    return sendRequest(command);
}

std::future<AuthorizationReply> UserRepository::sendRequest(const AuthorizationCommand& command) {
    return std::async(std::launch::async, [this, command]() -> AuthorizationReply {
        QNetworkRequest request((QUrl(buildUrl())));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        QByteArray data = serializeRequest(command);

        QNetworkReply* reply = networkManager_->post(request, data);

        // Блокирующее ожидание завершения
        QEventLoop loop;
        QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
        loop.exec();

        QByteArray responseData = reply->readAll();
        AuthorizationReply replyObj = parseReply(responseData, command.request);
        reply->deleteLater();
        return replyObj;
    });
}


QString UserRepository::buildUrl() const {
    return "http://" + QString::fromStdString(serverHostConfig_.ip) + ":" + QString::fromStdString(serverHostConfig_.port);
}

QByteArray UserRepository::serializeRequest(const AuthorizationCommand& command) const {
    QJsonDocument doc;
    switch (command.type) {
        case AuthorizationCommand::Type::Login:
            doc = AuthorizationInfoJsonConverter::loginUserToJsonDocument(command.request);
            break;
        case AuthorizationCommand::Type::Register:
            doc = AuthorizationInfoJsonConverter::registerUserToJsonDocument(command.request);
            break;
    }
    return doc.toJson();
}

AuthorizationReply UserRepository::parseReply(const QByteArray& responseData, const AuthorizationRequest& originalRequest) {
    QJsonParseError error;
    QJsonDocument doc = QJsonDocument::fromJson(responseData, &error);
    if (error.error != QJsonParseError::NoError) {
        return AuthorizationReply{false, "Ошибка парсинга JSON: " + error.errorString().toStdString()};
    }
    if (!doc.isObject()) {
        return AuthorizationReply{false, "Ответ не является JSON-объектом"};
    }
    AuthorizationReply reply = AuthorizationReplyJsonConverter::parseAuthorizationReply(doc.object());
    if (reply.success) {
        sharedState_->setUsername(originalRequest.username);
    }
    return reply;
}
