#ifndef AUTHVIEWMODEL_H
#define AUTHVIEWMODEL_H

#include <QObject>
#include <memory>
#include "../../Domain/UseCases/AuthenticateUserUseCase.h"
#include "../../Domain/UseCases/RegisterUserUseCase.h"

class AuthViewModel : public QObject {
    Q_OBJECT

public:
    explicit AuthViewModel(std::shared_ptr<AuthenticateUserUseCase> authUseCase, QObject* parent = nullptr);

    Q_INVOKABLE void login(const QString& username, const QString& password);
    Q_INVOKABLE void registerUser(const QString& username, const QString& password);

signals:
    void authSucceeded();
    void authFailed(const QString& message);

private:
    std::shared_ptr<AuthenticateUserUseCase> authUseCase_;
    // std::shared_ptr<RegisterUserUseCase> registerUseCase_;
};

#endif // AUTHVIEWMODEL_H
