#include "DependencyContainer.h"

#include "../Data/Repositories/Config/ConfigLoader.h"
#include "../Data/Repositories/Config/ConfigProvider.h"
#include "../Data/Repositories/Api/UserRepository.h"
#include "../Data/Repositories/Api/WeatherApiSource.h"
#include "../Data/Repositories/SharedState/SharedState.h"
#include "../Data/Repositories/Cache/WeatherCache.h"


DependencyContainer::DependencyContainer(QObject *qmlRoot)
    : qmlRoot_(qmlRoot)
{
    auto sharedStateImpl = std::make_shared<SharedState>();
    sharedStateInterface_ = sharedStateImpl;
    auto configLoaderImpl = std::make_shared<ConfigLoader>();
    configLoaderInterface_ = configLoaderImpl;
    auto cacheSourceIMPL = std::make_shared<WeatherCache>();
    cacheSourceInterface_ = cacheSourceIMPL;


    auto configProviderImpl = std::make_shared<ConfigProvider>(configLoaderInterface_);
    configProviderInterface_ = configProviderImpl;
    auto* userRepositoryImpl = new UserRepository(configProviderInterface_, sharedStateInterface_, qmlRoot_);
    userRepositoryInterface_ = userRepositoryImpl;
    auto* weatherApiSourceImpl = new WeatherApiSource(configProviderInterface_, qmlRoot);
    apiWeatherSourceInterface_ = weatherApiSourceImpl;

    authUseCase_ = std::make_shared<AuthenticateUserUseCase>(userRepositoryInterface_);
    regUseCase_ = std::make_shared<RegisterUserUseCase>(userRepositoryInterface_);
    dailyWeatherUseCase_ = std::make_shared<GetDailyWeatherUseCase>(apiWeatherSourceInterface_, cacheSourceInterface_);
    weeklyWeatherUseCase_ = std::make_shared<GetWeeklyWeatherUseCase>(apiWeatherSourceInterface_, cacheSourceInterface_);

    authViewModel_ = new AuthViewModel(authUseCase_, regUseCase_, qmlRoot_);
    weatherViewModel = new WeatherViewModel(dailyWeatherUseCase_, weeklyWeatherUseCase_, qmlRoot);
}

AuthViewModel* DependencyContainer::getAuthViewModel() {
    return authViewModel_;
}

WeatherViewModel *DependencyContainer::getWeatherViewModel()
{
    return weatherViewModel;
}

