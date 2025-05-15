#ifndef REGISTERUSERUSECASE_H
#define REGISTERUSERUSECASE_H

#include <memory>
#include <functional>

#include "../Interfaces/Api/IUserRepository.h"
#include "../Entities/User.h"

class  RegisterUserUseCase {
public:
    explicit RegisterUserUseCase(IUserRepository* repo);
    QFuture<Result<User>> execute(const User& user);
private:
    IUserRepository* repository_;
};

#endif // REGISTERUSERUSECASE_H
