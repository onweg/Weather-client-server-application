#ifndef SHAREDSTATE_H
#define SHAREDSTATE_H

#include "../../../Domain/Interfaces/SharedState/ISharedState.h"

class SharedState : public ISharedState
{
public:
    SharedState();
    // на сохранение данных я принимаю примитив(или entity User), ничего не возвращаю
    // на взятие данных принимаю ничего, возвращаю примитив(или entity User)
    std::string getUsername() override ;
    void setUsername(const std::string& username) override;
private:
    std::string username_ = "";
};

#endif // SHAREDSTATE_H
