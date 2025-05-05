#ifndef IUSERREPOSITORY_H
#define IUSERREPOSITORY_H

#include "../../Entities/User.h"
#include "../../Utils/Result.h"

#include <functional>

class IUserRepository {
public:
    virtual ~IUserRepository() = default;
    virtual void findUser(const User& user, std::function<void(Result<User>)> callback) = 0;
    virtual void registerUser(const User& user, std::function<void(Result<User>)> callback) = 0;
};

#endif // IUSERREPOSITORY_H
