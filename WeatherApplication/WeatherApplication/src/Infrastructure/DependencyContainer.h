#ifndef DEPENDENCYCONTAINER_H
#define DEPENDENCYCONTAINER_H

#include <memory>

#include "../Domain/UseCases/AuthenticateUserUseCase.h"
#include "../Presentation/ViewModel/AuthViewModel.h"
#include "../Domain/Repositories/IConfigLoader.h"
#include "../Domain/Repositories/IUserRepository.h"
#include "../Domain/Repositories/IConfigProvider.h"

class DependencyContainer {
public:
    explicit DependencyContainer(QObject* qmlRoot);
    AuthViewModel* getAuthViewModel();

private:
    std::shared_ptr<IConfigLoader> configLoaderInterface_;
    std::shared_ptr<IConfigProvider> configProviderInterface_;
    IUserRepository* userRepositoryInterface_;

    std::shared_ptr<AuthenticateUserUseCase> authUseCase_;

    AuthViewModel* authViewModel_ = nullptr;
    QObject* qmlRoot_;
};

#endif // DEPENDENCYCONTAINER_H
