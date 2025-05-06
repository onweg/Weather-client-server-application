#include "UserMapper.h"

UserMapper::UserMapper()
{

}

User UserMapper::fromDro(const UserDto &userDto)
{
    return User{userDto.username, userDto.passwordHash};
}

UserDto UserMapper::toDro(const User &user)
{
    return UserDto{user.username, user.passwordHash};
}
