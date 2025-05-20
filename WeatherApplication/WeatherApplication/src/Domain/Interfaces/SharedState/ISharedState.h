#ifndef ISHAREDSTATE_H
#define ISHAREDSTATE_H

#include <string>

class ISharedState {
public:
    virtual ~ISharedState() = default;
    // на сохранение данных я принимаю примитив(или entity User), ничего не возвращаю
    // на взятие данных принимаю ничего, возвращаю примитив(или entity User)
    virtual std::string getUsername() = 0;
    virtual void setUsername(const std::string& username) = 0;
};

#endif // ISHAREDSTATE_H
