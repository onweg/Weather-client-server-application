#ifndef IUSERREPOSITORY_H
#define IUSERREPOSITORY_H

#include "../Models/User.h"
#include "../Utils/Result.h"

#include <functional>

class IUserRepository {
public:
    virtual ~IUserRepository() = default;
    virtual void findUser(const User& user, std::function<void(Result<User>)> callback) = 0;
    // virtual void registerUser(const User& user) = 0; // сделать по аналогии с callback
};

#endif // IUSERREPOSITORY_H
