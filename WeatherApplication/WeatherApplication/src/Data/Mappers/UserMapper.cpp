#include "UserMapper.h"

UserMapper::UserMapper()
{

}

User UserMapper::fromDto(const UserDto &userDto)
{
    return User{userDto.username, userDto.passwordHash};
}

UserDto UserMapper::toDto(const User &user)
{
    return UserDto{user.username, user.passwordHash};
}
