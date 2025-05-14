#ifndef REGISTERUSERUSECASE_H
#define REGISTERUSERUSECASE_H

#include <memory>
#include <future>

#include "../Interfaces/Api/IUserRepository.h"
#include "../Entities/AuthorizationRequest.h"
#include "../Entities/AuthorizationReply.h"

class  RegisterUserUseCase {
public:
    explicit RegisterUserUseCase(IUserRepository* repo);
    AuthorizationReply execute(const AuthorizationRequest& request);
private:
    IUserRepository* repository_;
};

#endif // REGISTERUSERUSECASE_H
