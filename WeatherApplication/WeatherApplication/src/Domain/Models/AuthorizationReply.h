#ifndef AUTHORIZATIONREPLY_H
#define AUTHORIZATIONREPLY_H

#include <QString>

struct AuthorizationReply
{
    bool success = false;
    QString message;
};

#endif // AUTHORIZATIONREPLY_H
