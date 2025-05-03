#ifndef USER_H
#define USER_H

#include <string>

struct User{
    std::string username;
    std::string passwordHash;

    User(const std::string& username, const std::string& passwordHash)
           : username(username), passwordHash(passwordHash) {}
    User() : username(""), passwordHash("") {}
};

#endif // USER_H
