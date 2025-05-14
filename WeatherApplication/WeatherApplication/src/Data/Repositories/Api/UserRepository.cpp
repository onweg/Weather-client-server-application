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
    : QObject(parent),
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

AuthorizationReply UserRepository::findUser(const AuthorizationRequest& request) {
    AuthorizationCommand command{request, AuthorizationCommand::Type::Login};
    return sendRequest(command).get();
}

AuthorizationReply UserRepository::registerUser(const AuthorizationRequest& request) {
    AuthorizationCommand command{request, AuthorizationCommand::Type::Register};
    return sendRequest(command).get();
}

std::future<AuthorizationReply> UserRepository::sendRequest(const AuthorizationCommand& command) {
    std::promise<AuthorizationReply> promise;
    std::future<AuthorizationReply> future = promise.get_future();
    QNetworkRequest request((QUrl(buildUrl())));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = serializeRequest(command);
    QNetworkReply* reply = networkManager_->post(request, data);
    QObject::connect(reply, &QNetworkReply::finished, this, [this, reply, command, p = std::move(promise)]() mutable {
        QByteArray responseData = reply->readAll();
        AuthorizationReply replyObj = parseReply(responseData, command.request);
        reply->deleteLater();
        p.set_value(replyObj);
    });
    return future;
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



//#include "UserRepository.h"
//#include "../../../Utils/AuthorizationInfoJsonConverter.h"
//#include "../../../Utils/AuthorizationReplyJsonConverter.h"


//#include <QString>
//#include <QUrl>
//#include <QNetworkRequest>
//#include <QNetworkReply>
//#include <QDebug>


//UserRepository::UserRepository(std::shared_ptr<IConfigProvider> config,  std::shared_ptr<ISharedState> state, QObject *parent)
//    : QObject(parent), configProvider_(std::move(config)), sharedState_(std::move(state))
//{
//    auto result = configProvider_->getServerHostConfig();
//    if (!result.isSuccess()) {
//        throw std::runtime_error("Не удалось получить данные из config файла");
//    }
//    serverHostConfig_ = result.value();
//    networkManager_ = new QNetworkAccessManager(this);
//}

//AuthorizationReply UserRepository::findUser(const AuthorizationRequest &user)
//{
//    auto future -
//    return sendRequest(user, std::move(callback), "LOGIN");
//}

//AuthorizationReply UserRepository::registerUser(const AuthorizationRequest &user)
//{
//    return sendRequest(user, std::move(callback), "REGISTER");
//}

//AuthorizationReply UserRepository::sendRequest(какой-нибудь сформированный QByteArray например)
//{

//    QString urlStr = "http://" + QString::fromStdString(serverHostConfig_.ip) + ":" + QString::fromStdString(serverHostConfig_.port);
//    QUrl url(urlStr);
//    QNetworkRequest request(url);
//    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
//    QByteArray data;
//    if (command == "LOGIN") {
//        data = AuthorizationInfoJsonConverter::loginUserToJsonDocument(user).toJson();
//    } else if (command == "REGISTER") {
//        data = AuthorizationInfoJsonConverter::registerUserToJsonDocument(user).toJson();
//    }
//    QNetworkReply* reply = networkManager_->post(request, data);

//    QObject::connect(reply, &QNetworkReply::finished, this, [this, reply, user, callback]() {
//        Result<User> result;

//        QByteArray response = reply->readAll();

//        QJsonParseError error;
//        QJsonDocument doc = QJsonDocument::fromJson(response, &error);
//        if (error.error != QJsonParseError::NoError) {
//            result = Result<User>::failure("Ошибка парсинга JSON:" + error.errorString().toStdString());
//        } else {
//            if (!doc.isObject()) {
//                result = Result<User>::failure("JSON не является объектом");
//            } else {
//                AuthorizationReply authorizationReply = AuthorizationReplyJsonConverter::parseAuthorizationReply(doc.object());
//                if (authorizationReply.success) {
//                    sharedState_->setUsername(user.username);
//                    result = Result<User>::success(user);
//                } else {
//                    result = Result<User>::failure(authorizationReply.message);
//                }
//            }
//        }
//        callback(result);
//        reply->deleteLater();
//    });

//}


