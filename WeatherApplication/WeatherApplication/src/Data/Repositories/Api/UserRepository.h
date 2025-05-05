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
    UserRepository(std::shared_ptr<IConfigProvider> config,  std::shared_ptr<ISharedState> state, QObject* parent = nullptr);
    void findUser(const User& user, std::function<void(Result<User>)> callback) override;
    void registerUser(const User& user, std::function<void(Result<User>)> callback) override;
private:
    void sendRequest(const User& user, std::function<void(Result<User>)> callback, const QString command);
    std::shared_ptr<IConfigProvider> configProvider_;
    std::shared_ptr<ISharedState> sharedState_;
    Result<ServerHostConfig> serverHostConfig_;
    QNetworkAccessManager* networkManager_;
};

#endif // USERREPOSITORY_H
