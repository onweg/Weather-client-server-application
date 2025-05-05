#ifndef USERDTO_H
#define USERDTO_H

#include <QString>

struct UserDto{
    QString username;
    QString passwordHash;

    UserDto(const QString& username, const QString& passwordHash)
           : username(username), passwordHash(passwordHash) {}
    UserDto() : username(""), passwordHash("") {}
};

#endif // USERDTO_H
