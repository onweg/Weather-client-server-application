#ifndef AUTHVIEWMODEL_H
#define AUTHVIEWMODEL_H

#include <QObject>
#include <memory>
#include "../../Domain/UseCases/AuthenticateUserUseCase.h"
#include "../../Domain/UseCases/RegisterUserUseCase.h"
#include "../../Domain/Entities/AuthorizationReply.h"

class AuthViewModel : public QObject {
    Q_OBJECT

public:
    explicit AuthViewModel(std::shared_ptr<AuthenticateUserUseCase> authUseCase, std::shared_ptr<RegisterUserUseCase> regUseCase, QObject* parent = nullptr);

    Q_INVOKABLE void loginUser(const QString& username, const QString& password);
    Q_INVOKABLE void registerUser(const QString& username, const QString& password);

signals:
    void authSucceeded();
    void authFailed(const QString& message);

    void showLoadingAnimation();
    void hideLoadingAnimation();

private:
    std::shared_ptr<AuthenticateUserUseCase> authUseCase_;
    std::shared_ptr<RegisterUserUseCase> regUseCase_;
};

#endif // AUTHVIEWMODEL_H
