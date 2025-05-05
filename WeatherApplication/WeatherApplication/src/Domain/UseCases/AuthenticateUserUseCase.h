#ifndef AUTHENTICATEUSERUSECASE_H
#define AUTHENTICATEUSERUSECASE_H

#include "../Repositories/IUserRepository.h"
#include "../Models/User.h"
#include "../Utils/Result.h"

#include <functional>

class  AuthenticateUserUseCase {
public:
    explicit AuthenticateUserUseCase(std::shared_ptr<IUserRepository> repo);
    void execute(const User& user, std::function<void(Result<User>)> callback);
private:
    std::shared_ptr<IUserRepository> repository_;
};

#endif
