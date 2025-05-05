#include "DependencyContainer.h"

// Infrastructure
#include "../Data/Repositories/UserRepository.h"
#include "../Data/Repositories/ConfigProvider.h"
#include "../Data/Repositories/ConfigLoader.h"

DependencyContainer::DependencyContainer(QObject* qmlRoot)
    : qmlRoot_(qmlRoot)
{
    auto configLoaderImpl = std::make_shared<ConfigLoader>();
    configLoaderInterface_ = configLoaderImpl; 
    auto configProviderImpl = std::make_shared<ConfigProvider>(configLoaderInterface_);
    configProviderInterface_ = configProviderImpl;
    auto* userRepository = new UserRepository(configProviderInterface_.get(), qmlRoot_);
    userRepositoryInterface_ = userRepository; 

    authUseCase_ = std::make_shared<AuthenticateUserUseCase>(userRepositoryInterface_);

    authViewModel_ = new AuthViewModel(authUseCase_, qmlRoot_);
}


AuthViewModel* DependencyContainer::getAuthViewModel() {
    return authViewModel_;
}
