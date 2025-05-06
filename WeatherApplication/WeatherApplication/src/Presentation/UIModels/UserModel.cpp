#include "UserModel.h"

UserModel::UserModel(QObject *parent) : QObject(parent)
{

}

QString UserModel::getUsername() const
{
    return username_;
}

QString UserModel::getPassword() const
{
    return password_;
}

void UserModel::setUsername(const QString &username)
{
    if (username_ != username) {
        username_ = username;
    }
}

void UserModel::setPassword(const QString &password)
{
    if (password_ != password) {
        password_ = password;
    }
}
