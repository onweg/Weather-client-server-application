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
    void execute(const User& user, std::function<void(Result<User>)> callback);
private:
    IUserRepository* repository_;
};

#endif
