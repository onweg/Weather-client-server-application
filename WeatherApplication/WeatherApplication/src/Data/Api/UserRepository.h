#ifndef USERREPOSITORY_H
#define USERREPOSITORY_H

#include <memory>

#include <QObject>
#include <QNetworkAccessManager>

#include "../../Domain/Repositories/IUserRepository.h"
#include "../../Domain/Repositories/IConfigProvider.h"

class UserRepository : public QObject, public IUserRepository {
    Q_OBJECT
public:
    UserRepository(std::shared_ptr<IConfigProvider> config, QObject* parent = nullptr);
    void findUser(const User& user, std::function<void(Result<User>)> callback) override;
    // void registerUser(const User& user) override; // сделать по аналогии с callbac
private:
    std::shared_ptr<IConfigProvider> configProvider_;
    Result<ServerHostConfig> serverHostConfig_;
    QNetworkAccessManager* networkManager_;
};

#endif // USERREPOSITORY_H
