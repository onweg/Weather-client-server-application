#include "DependencyContainer.h"

#include "../Data/Repositories/Config/ConfigLoader.h"
#include "../Data/Repositories/Config/ConfigProvider.h"
#include "../Data/Repositories/Api/UserRepository.h"
#include "../Data/Repositories/Api/WeatherApiSource.h"
#include "../Data/Repositories/SharedState/SharedState.h"
#include "../Data/Repositories/Cache/WeatherCache.h"
#include "../Data/Repositories/Database/SqliteWeatherHistoryRepository.h"
#include "../Data/Repositories/Database/WeatherDatabaseInitializer.h"
#include "ThreadedRepositoryFactory.h"


DependencyContainer::DependencyContainer(QObject *qmlRoot)
    : qmlRoot_(qmlRoot)
{
    auto sharedStateImpl = std::make_shared<SharedState>();
    sharedStateInterface_ = sharedStateImpl;
    auto configLoaderImpl = std::make_shared<ConfigLoader>();
    configLoaderInterface_ = configLoaderImpl;
    auto cacheSourceImpl = std::make_shared<WeatherCache>();
    cacheSourceInterface_ = cacheSourceImpl;
    auto dbInitializerImpl = std::make_shared<WeatherDatabaseInitializer>();
    dbInitializerInterface_ = dbInitializerImpl;


    auto configProviderImpl = std::make_shared<ConfigProvider>(configLoaderInterface_);
    configProviderInterface_ = configProviderImpl;
    userRepositoryInterface_ = ThreadedRepositoryFactory::createUserRepository(qmlRoot_);
    apiWeatherSourceInterface_ = ThreadedRepositoryFactory::createWeatherApiSource(qmlRoot_);
    auto dbWeatherHistoryImpl = std::make_shared<SqliteWeatherHistoryRepository>(dbInitializerInterface_, sharedStateInterface_);
    dbWeatherHistoryInterface_ = dbWeatherHistoryImpl;

    authUseCase_ = std::make_shared<AuthenticateUserUseCase>(userRepositoryInterface_);
    regUseCase_ = std::make_shared<RegisterUserUseCase>(userRepositoryInterface_);
    dailyWeatherUseCase_ = std::make_shared<GetDailyWeatherUseCase>(apiWeatherSourceInterface_, cacheSourceInterface_);
    weeklyWeatherUseCase_ = std::make_shared<GetWeeklyWeatherUseCase>(apiWeatherSourceInterface_, cacheSourceInterface_);
    saveHistoryUseCase_ = std::make_shared<SaveWeatherHistoryUseCase>(dbWeatherHistoryInterface_);
    getHistoryUseCase_ = std::make_shared<GetWeatherHistoryUseCase>(dbWeatherHistoryInterface_);

    authViewModel_ = new AuthViewModel(authUseCase_, regUseCase_, qmlRoot_);
    weatherViewModel = new WeatherViewModel(dailyWeatherUseCase_, weeklyWeatherUseCase_, saveHistoryUseCase_, qmlRoot);
}

AuthViewModel* DependencyContainer::getAuthViewModel() {
    return authViewModel_;
}

WeatherViewModel *DependencyContainer::getWeatherViewModel()
{
    return weatherViewModel;
}

