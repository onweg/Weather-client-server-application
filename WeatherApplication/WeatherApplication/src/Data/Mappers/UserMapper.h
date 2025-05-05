#ifndef USERMAPPER_H
#define USERMAPPER_H

#include "../../Domain/Entities/User.h"
#include "../DtoModels/UserDto.h"

class UserMapper
{
public:
    UserMapper();
    static User fromDro(const UserDto& userDto);
    static UserDto toDro(const User& user);
};

#endif // USERMAPPER_H
