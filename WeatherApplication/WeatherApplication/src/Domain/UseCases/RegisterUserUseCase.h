#ifndef REGISTERUSERUSECASE_H
#define REGISTERUSERUSECASE_H

#include <functional>
#include <memory>

#include "../Entities/User.h"
#include "../Interfaces/Api/IUserRepository.h"

class RegisterUserUseCase {
public:
 explicit RegisterUserUseCase(IUserRepository* repo);
 void execute(const User& user, std::function<void(Result<User>)> callback);

private:
 IUserRepository* repository_;
};

#endif	// REGISTERUSERUSECASE_H
