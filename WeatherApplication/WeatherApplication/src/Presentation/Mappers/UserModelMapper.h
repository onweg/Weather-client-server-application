#ifndef USERMODELMAPPER_H
#define USERMODELMAPPER_H

#include "../../Domain/Entities/User.h"
#include "../UIModels/UserModel.h"

class UserModelMapper
{
public:
    static void toUiModel(const User& dto, UserModel* uiModel);
    static User fromUiModel(const UserModel* uiModel);
};

#endif // USERMODELMAPPER_H
