#ifndef REGISTERUSERUSECASE_H
#define REGISTERUSERUSECASE_H

#include <memory>
#include <functional>

#include "../Interfaces/Api/IUserRepository.h"
#include "../Entities/User.h"
#include "../Utils/Result.h"

class  RegisterUserUseCase {
public:
    explicit RegisterUserUseCase(IUserRepository* repo);
    void execute(const User& user, std::function<void(Result<User>)> callback);
private:
    IUserRepository* repository_;
};

#endif // REGISTERUSERUSECASE_H
