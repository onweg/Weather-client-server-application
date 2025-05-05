#include "UserMapper.h"

UserMapper::UserMapper()
{

}

User UserMapper::fromDro(const UserDto &userDto)
{
    return User(userDto.username.toStdString(), userDto.passwordHash.toStdString());
}

UserDto UserMapper::toDro(const User &user)
{
    return UserDto(QString::fromStdString(user.username), QString::fromStdString(user.passwordHash));
}
