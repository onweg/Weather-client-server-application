#ifndef USERREPOSITORY_H
#define USERREPOSITORY_H

#include <memory>

#include <QObject>
#include <QNetworkAccessManager>

#include "../../../Domain/Interfaces/Api/IUserRepository.h"
#include "../../../Domain/Interfaces/Config/IConfigProvider.h"
#include "../../../Domain/Interfaces/SharedState/ISharedState.h"

class UserRepository : public QObject, public IUserRepository {
    Q_OBJECT

public:
    UserRepository(std::shared_ptr<IConfigProvider> config,
                   std::shared_ptr<ISharedState> state,
                   QObject* parent = nullptr);
    // принимаем entity, преобразует в DTO, преобразует в JSON, отправляет на сервер JSON, принмает c сервера JSON, преобразует в DTO, преобразует в entity, возвращаем entiry
    QFuture<AuthorizationReply> findUser(const AuthorizationRequest& request) override;
    QFuture<AuthorizationReply> registerUser(const AuthorizationRequest& request) override;

private:
    enum class AuthCommand { Login, Register };

    void initConfig();
    QFuture<AuthorizationReply> startAuthorization(const AuthorizationRequest& request, AuthCommand command);
    QByteArray buildRequestData(const AuthorizationRequest& request, AuthCommand command);
    QNetworkRequest buildHttpRequest();
    void sendHttpRequest(const QNetworkRequest& req, const QByteArray& data,
                         const AuthorizationRequest& user,
                         std::shared_ptr<QFutureInterface<AuthorizationReply>> futureInterface,
                         AuthCommand command);
    AuthorizationReply parseReply(const QByteArray& response, const AuthorizationRequest& user);
    void handleReply(QNetworkReply* reply,
                     const AuthorizationRequest& user,
                     std::shared_ptr<QFutureInterface<AuthorizationReply>> futureInterface);

    std::shared_ptr<IConfigProvider> configProvider_;
    std::shared_ptr<ISharedState> sharedState_;
    std::shared_ptr<ServerHostConfig> serverHostConfig_;
    QNetworkAccessManager* networkManager_;
};

#endif // USERREPOSITORY_H
