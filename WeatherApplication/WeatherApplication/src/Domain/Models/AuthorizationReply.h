#ifndef AUTHORIZATIONREPLY_H
#define AUTHORIZATIONREPLY_H

#include <string>

struct AuthorizationReply
{
    bool success = false;
    std::string message;
};

#endif // AUTHORIZATIONREPLY_H
