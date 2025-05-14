#ifndef USERREPOSITORY_H
#define USERREPOSITORY_H

#include <memory>
#include <future>
#include <QObject>
#include <QNetworkAccessManager>
#include <QByteArray>
#include "../../../Domain/Interfaces/Api/IUserRepository.h"
#include "../../../Domain/Interfaces/Config/IConfigProvider.h"
#include "../../../Domain/Interfaces/SharedState/ISharedState.h"
#include "../../../Domain/Entities/AuthorizationRequest.h"
#include "../../../Domain/Entities//AuthorizationReply.h"

class UserRepository : public QObject, public IUserRepository {
    Q_OBJECT
public:
    UserRepository(std::shared_ptr<IConfigProvider> config,
                   std::shared_ptr<ISharedState> state,
                   QObject* parent = nullptr);

    std::future<AuthorizationReply> findUser(const AuthorizationRequest& request) override;
    std::future<AuthorizationReply> registerUser(const AuthorizationRequest& request) override;

private:
    struct AuthorizationCommand {
        AuthorizationRequest request;
        enum class Type { Login, Register } type;
    };

    std::future<AuthorizationReply> sendRequest(const AuthorizationCommand& command);

    QString buildUrl() const;
    QByteArray serializeRequest(const AuthorizationCommand& command) const;
    AuthorizationReply parseReply(const QByteArray& responseData, const AuthorizationRequest& originalRequest);

    std::shared_ptr<IConfigProvider> configProvider_;
    std::shared_ptr<ISharedState> sharedState_;
    ServerHostConfig serverHostConfig_;
    QNetworkAccessManager* networkManager_;
};

#endif // USERREPOSITORY_H

//#ifndef USERREPOSITORY_H
//#define USERREPOSITORY_H

//#include <memory>
//#include <future>

//#include <QObject>
//#include <QNetworkAccessManager>
//#include <QByteArray>

//#include "../../../Domain/Interfaces/Api/IUserRepository.h"
//#include "../../../Domain/Interfaces/Config/IConfigProvider.h"
//#include "../../../Domain/Interfaces/SharedState/ISharedState.h"

//class UserRepository : public QObject, public IUserRepository {
//    Q_OBJECT
//public:
//    UserRepository(std::shared_ptr<IConfigProvider> config,
//                   std::shared_ptr<ISharedState> state,
//                   QObject* parent = nullptr);
//    AuthorizationReply findUser(const AuthorizationRequest& request) override;
//    AuthorizationReply registerUser(const AuthorizationRequest& request) override;
//private:
//    std::future<AuthorizationReply> sendRequest(const QByteArray& data);
//    std::shared_ptr<IConfigProvider> configProvider_;
//    std::shared_ptr<ISharedState> sharedState_;

//    ServerHostConfig serverHostConfig_;
//    QNetworkAccessManager* networkManager_;
//};

//#endif // USERREPOSITORY_H
