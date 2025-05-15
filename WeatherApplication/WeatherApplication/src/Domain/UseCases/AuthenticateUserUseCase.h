#ifndef AUTHENTICATEUSERUSECASE_H
#define AUTHENTICATEUSERUSECASE_H

#include <memory>
#include <functional>

#include "../Interfaces/Api/IUserRepository.h"
#include "../Entities/User.h"
#include "../Utils/Result.h"

class  AuthenticateUserUseCase {
public:
    explicit AuthenticateUserUseCase(IUserRepository* repo);
    QFuture<Result<User>> execute(const User& user);
private:
    IUserRepository* repository_;
};

#endif
