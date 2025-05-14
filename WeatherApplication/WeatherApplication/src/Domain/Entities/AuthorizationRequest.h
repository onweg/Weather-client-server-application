#ifndef AUTHORIZATIONREQUEST_H
#define AUTHORIZATIONREQUEST_H

#include <string>

struct AuthorizationRequest{
    std::string username;
    std::string passwordHash;
};

#endif // AUTHORIZATIONREQUEST_H
