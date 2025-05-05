#include "DependencyContainer.h"

#include "../Data/Repositories/Config/ConfigLoader.h"
#include "../Data/Repositories/Config/ConfigProvider.h"
#include "../Data/Repositories/Api/UserRepository.h"


DependencyContainer::DependencyContainer(QObject *qmlRoot)
    : qmlRoot_(qmlRoot)
{
    auto configLoaderImpl = std::make_shared<ConfigLoader>();
    configLoaderInterface_ = configLoaderImpl;
    auto configProviderImpl = std::make_shared<ConfigProvider>(configLoaderInterface_);
    configProviderInterface_ = configProviderImpl;
    auto* userRepositoryImpl = new UserRepository(configProviderInterface_, qmlRoot_);
    userRepositoryInterface_ = userRepositoryImpl;

    authUseCase_ = std::make_shared<AuthenticateUserUseCase>(userRepositoryInterface_);
    regUseCase_ = std::make_shared<RegisterUserUseCase>(userRepositoryInterface_);

    authViewModel_ = new AuthViewModel(authUseCase_, regUseCase_, qmlRoot_);
}

AuthViewModel* DependencyContainer::getAuthViewModel() {
    return authViewModel_;
}

