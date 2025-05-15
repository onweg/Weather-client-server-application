#ifndef IUSERREPOSITORY_H
#define IUSERREPOSITORY_H

#include "../../Entities/User.h"
#include "../../Utils/Result.h"

#include <QFuture>

class IUserRepository {
public:
    virtual ~IUserRepository() = default;
    virtual QFuture<Result<User>> findUser(const User& user) = 0;
    virtual QFuture<Result<User>> registerUser(const User& user) = 0;
};

#endif // IUSERREPOSITORY_H
