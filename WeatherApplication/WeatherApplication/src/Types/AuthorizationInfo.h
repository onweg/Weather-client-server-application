#ifndef AUTHORIZATIONINFO_H
#define AUTHORIZATIONINFO_H

#include <QString>

struct AuthorizationInfo {
    QString command;
    QString login;
    QString password;
};

#endif // AUTHORIZATIONINFO_H
