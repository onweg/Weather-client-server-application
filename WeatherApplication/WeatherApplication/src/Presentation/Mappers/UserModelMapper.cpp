#include "UserModelMapper.h"

void UserModelMapper::toUiModel(const User &domain, UserModel *uiModel)
{
    if (!uiModel) return;
    uiModel->setUsername(QString::fromStdString(domain.username));
    uiModel->setPassword(QString::fromStdString(domain.passwordHash));
}

User UserModelMapper::fromUiModel(const UserModel *uiModel)
{
    if (!uiModel) return {};

    return User{
        uiModel->getUsername().toStdString(),
        uiModel->getPassword().toStdString()
    };
}
