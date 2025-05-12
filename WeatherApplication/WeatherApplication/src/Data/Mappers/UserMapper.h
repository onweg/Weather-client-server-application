#ifndef USERMAPPER_H
#define USERMAPPER_H

#include "../../Domain/Entities/User.h"
#include "../DtoModels/UserDto.h"

class UserMapper
{
public:
    UserMapper();
    static User fromDto(const UserDto& userDto);
    static UserDto toDto(const User& user);
};

#endif // USERMAPPER_H
