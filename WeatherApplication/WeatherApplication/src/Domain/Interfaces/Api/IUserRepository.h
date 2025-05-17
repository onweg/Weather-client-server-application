#ifndef IUSERREPOSITORY_H
#define IUSERREPOSITORY_H

#include <QFuture>

#include "../../Entities/AuthorizationReply.h"
#include "../../Entities/AuthorizationRequest.h"

class IUserRepository {
public:
    virtual ~IUserRepository() = default;
    virtual QFuture<AuthorizationReply> findUser(const AuthorizationRequest& request) = 0;
    virtual QFuture<AuthorizationReply> registerUser(const AuthorizationRequest& request) = 0;
};

#endif // IUSERREPOSITORY_H
