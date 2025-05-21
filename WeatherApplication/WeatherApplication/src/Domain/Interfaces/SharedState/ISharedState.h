#ifndef ISHAREDSTATE_H
#define ISHAREDSTATE_H

#include <string>

class ISharedState {
public:
    virtual ~ISharedState() = default;
    virtual std::string getUsername() = 0;
    virtual void setUsername(const std::string& username) = 0;
};

#endif // ISHAREDSTATE_H
