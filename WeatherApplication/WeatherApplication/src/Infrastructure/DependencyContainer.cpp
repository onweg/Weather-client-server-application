#include "DependencyContainer.h"

#include "../Data/Config/ConfigLoader.h"
#include "../Data/Config/ConfigProvider.h"
#include "../Data/Api/UserRepository.h"


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

    authViewModel_ = new AuthViewModel(authUseCase_, qmlRoot_);
}

AuthViewModel* DependencyContainer::getAuthViewModel() {
    return authViewModel_;
}

