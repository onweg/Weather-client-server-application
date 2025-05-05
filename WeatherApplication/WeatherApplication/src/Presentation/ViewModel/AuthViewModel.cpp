#include "AuthViewModel.h"
#include <QCryptographicHash>
#include "../../Domain/Models/User.h"
#include <QDebug>


AuthViewModel::AuthViewModel(std::shared_ptr<AuthenticateUserUseCase> authUseCase, QObject *parent)
    :QObject(parent), authUseCase_(std::move(authUseCase))
{

}

void AuthViewModel::login(const QString &username, const QString &password)
{
    // данные закидываю в Dto
    // UserDTO userDto(username, getHash(password));
    // перевожу из дто в домейн моедль
    // User user = UserDto::getUserDomainModel(userDto);

    User user(username.toStdString(), password.toStdString());

    authUseCase_->execute(user, [this](Result<User> result){
        if (result.isSuccess()) {
            // для Weather я на этом этапе должен буду поменять значения у Модели, которая выводтся на экран, на новые значения,(у моедли Property которые вызовутс при изменении, тем самым картинка обновится без сигнала, так как мне не надо менять никакую модель, то просто вызову сигнал)
            emit authSucceeded();
        } else {
            emit authFailed(QString::fromStdString(result.errorMessage()));
        }
    });
}

void AuthViewModel::registerUser(const QString &username, const QString &password)
{
    // данные закидываю в Dto
    // перевожу из дто в домейн моедль
    // с помощью registerUseCase_ выполняю метод execute чтоб выполнить одну функцию моего кейса
    // проверяю, если регистрация успешна пройдена, отправляю сигнал
    // если нет, то отправляю сишнал с ошибкогй
    qDebug() << username << password;
}

