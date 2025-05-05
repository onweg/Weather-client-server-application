#ifndef DEPENDENCYCONTAINER_H
#define DEPENDENCYCONTAINER_H

#include <memory>

#include "../Presentation/ViewModel/AuthViewModel.h"
#include "../Domain/UseCases/AuthenticateUserUseCase.h"
#include "../Domain/UseCases/RegisterUserUseCase.h"
#include "../Domain/Interfaces/Config/IConfigLoader.h"
#include "../Domain/Interfaces/Config/IConfigProvider.h"
#include "../Domain/Interfaces/Api/IUserRepository.h"

class DependencyContainer {
public:
    explicit DependencyContainer(QObject* qmlRoot);
    AuthViewModel* getAuthViewModel();

private:
    std::shared_ptr<IConfigLoader> configLoaderInterface_;
    std::shared_ptr<IConfigProvider> configProviderInterface_;
    IUserRepository* userRepositoryInterface_;

    std::shared_ptr<AuthenticateUserUseCase> authUseCase_;
    std::shared_ptr<RegisterUserUseCase> regUseCase_;

    AuthViewModel* authViewModel_ = nullptr;
    QObject* qmlRoot_;
};

#endif // DEPENDENCYCONTAINER_H
