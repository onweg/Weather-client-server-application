#include "DependencyContainer.h"

#include "../Data/Repositories/Config/ConfigLoader.h"
#include "../Data/Repositories/Config/ConfigProvider.h"
#include "../Data/Repositories/Api/UserRepository.h"
#include "../Data/Repositories/Api/WeatherApiSource.h"
#include "../Data/Repositories/SharedState/SharedState.h"
#include "../Data/Repositories/Cache/WeatherCache.h"
#include "../Data/Repositories/Database/SqliteWeatherHistoryRepository.h"
#include "../Data/Repositories/Database/WeatherDatabaseInitializer.h"
#include "../Data/Repositories/Weather/WeatherRepository.h"

DependencyContainer::DependencyContainer(QObject* qmlRoot)
    : qmlRoot_(qmlRoot) {
    initInfrastructure();
    initRepositories();
    initUseCases();
    initViewModels();
}

AuthViewModel* DependencyContainer::getAuthViewModel() {
    return authViewModel_;
}

WeatherViewModel *DependencyContainer::getWeatherViewModel()
{
    return weatherViewModel;
}

void DependencyContainer::initInfrastructure() {
    sharedStateInterface_ = std::make_shared<SharedState>();
    configLoaderInterface_ = std::make_shared<ConfigLoader>();
    cacheSourceInterface_ = std::make_shared<WeatherCache>();
    dbInitializerInterface_ = std::make_shared<WeatherDatabaseInitializer>();
}

void DependencyContainer::initRepositories() {
    configProviderInterface_ = std::make_shared<ConfigProvider>(configLoaderInterface_);
    userRepositoryInterface_ = new UserRepository(configProviderInterface_, sharedStateInterface_, qmlRoot_);
    apiWeatherSourceInterface_ = new WeatherApiSource(configProviderInterface_, qmlRoot_);
    dbWeatherHistoryInterface_ = std::make_shared<SqliteWeatherHistoryRepository>(dbInitializerInterface_, sharedStateInterface_);
    weatherRepositoryInterface_ = new WeatherRepository(cacheSourceInterface_, apiWeatherSourceInterface_, qmlRoot_);
}

void DependencyContainer::initUseCases() {
    authUseCase_ = std::make_shared<AuthenticateUserUseCase>(userRepositoryInterface_);
    regUseCase_ = std::make_shared<RegisterUserUseCase>(userRepositoryInterface_);
    dailyWeatherUseCase_ = std::make_shared<GetDailyWeatherUseCase>(weatherRepositoryInterface_);
    weeklyWeatherUseCase_ = std::make_shared<GetWeeklyWeatherUseCase>(weatherRepositoryInterface_);
    saveHistoryUseCase_ = std::make_shared<SaveWeatherHistoryUseCase>(dbWeatherHistoryInterface_);
    getHistoryUseCase_ = std::make_shared<GetWeatherHistoryUseCase>(dbWeatherHistoryInterface_);
}

void DependencyContainer::initViewModels() {
    authViewModel_ = new AuthViewModel(authUseCase_, regUseCase_, qmlRoot_);
    weatherViewModel = new WeatherViewModel(dailyWeatherUseCase_, weeklyWeatherUseCase_, saveHistoryUseCase_, qmlRoot_);
}

