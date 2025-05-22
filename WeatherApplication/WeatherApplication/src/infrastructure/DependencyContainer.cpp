#include "DependencyContainer.h"

#include "../data/repositories/api/UserRepository.h"
#include "../data/repositories/api/WeatherApiSource.h"
#include "../data/repositories/cache/WeatherCache.h"
#include "../data/repositories/config/ConfigLoader.h"
#include "../data/repositories/config/ConfigProvider.h"
#include "../data/repositories/database/SqliteWeatherHistoryRepository.h"
#include "../data/repositories/database/WeatherDatabaseInitializer.h"
#include "../data/repositories/sharedstate/SharedState.h"
#include "../data/repositories/weather/WeatherRepository.h"

#include <QDebug>

DependencyContainer::DependencyContainer(QObject *qmlRoot)
    : sharedStateInterface_(nullptr),
      configLoaderInterface_(nullptr),
      configProviderInterface_(nullptr),
      cacheSourceInterface_(nullptr),
      dbInitializerInterface_(nullptr),
      userRepositoryInterface_(nullptr),
      apiWeatherSourceInterface_(nullptr),
      weatherRepositoryInterface_(nullptr),
      authUseCase_(nullptr),
      regUseCase_(nullptr),
      dailyWeatherUseCase_(nullptr),
      weeklyWeatherUseCase_(nullptr),
      saveHistoryUseCase_(nullptr),
      getHistoryUseCase_(nullptr),
      authViewModel_(nullptr),
      weatherViewModel(nullptr),
      qmlRoot_(qmlRoot) {}

bool DependencyContainer::init() {
    if (!initInfrastructure()) return false;
    if (!initRepositories()) return false;
    if (!initUseCases()) return false;
    if (!initViewModels()) return false;
    return true;
}

AuthViewModel* DependencyContainer::getAuthViewModel() {
    return authViewModel_;
}

WeatherViewModel* DependencyContainer::getWeatherViewModel() {
    return weatherViewModel;
}

bool DependencyContainer::initInfrastructure() {
    if (!createSharedState()) return false;
    if (!createConfigLoader()) return false;
    if (!createDbInitializer()) return false;
    return true;
}

bool DependencyContainer::initRepositories() {
    if (!createConfigProvider()) return false;
    if (!createWeatherCache()) return false;
    if (!createUserRepository()) return false;
    if (!createWeatherApiSource()) return false;
    setDbWeatherHistoryRepository();
    if (!createWeatherRepository()) return false;
    return true;
}

bool DependencyContainer::initUseCases() {
    if (!createAuthUseCase()) return false;
    if (!createRegUseCase()) return false;
    if (!createDailyWeatherUseCase()) return false;
    if (!createWeeklyWeatherUseCase()) return false;
    if (!createSaveHistoryUseCase()) return false;
    if (!createGetHistoryUseCase()) return false;
    return true;
}

bool DependencyContainer::initViewModels() {
    if (!createAuthViewModel()) return false;
    if (!createWeatherViewModel()) return false;
    return true;
}

bool DependencyContainer::createSharedState() {
    try {
        sharedStateInterface_ = std::make_shared<SharedState>();
    } catch (const std::bad_alloc& e) {
        qCritical() << "Ошибка выделения памяти в createSharedState:" << e.what();
        return false;
    }
    return true;
}

bool DependencyContainer::createConfigLoader() {
    try {
        configLoaderInterface_ = std::make_shared<ConfigLoader>();
    } catch (const std::bad_alloc& e) {
        qCritical() << "Ошибка выделения памяти в createConfigLoader:" << e.what();
        return false;
    }
    return true;
}

bool DependencyContainer::createWeatherCache() {
    try {
        cacheSourceInterface_ = std::make_shared<WeatherCache>(configProviderInterface_);
    } catch (const std::bad_alloc& e) {
        qCritical() << "Ошибка выделения памяти в createWeatherCache:" << e.what();
        return false;
    }
    return true;
}

bool DependencyContainer::createDbInitializer() {
    try {
        dbInitializerInterface_ = std::make_shared<WeatherDatabaseInitializer>();
    } catch (const std::bad_alloc& e) {
        qCritical() << "Ошибка выделения памяти в createDbInitializer:" << e.what();
        return false;
    }
    return true;
}

bool DependencyContainer::createConfigProvider() {
    try {
        configProviderInterface_ =
            std::make_shared<ConfigProvider>(configLoaderInterface_);
    } catch (const std::bad_alloc& e) {
        qCritical() << "Ошибка выделения памяти в createConfigProvider:" << e.what();
        return false;
    }
    return true;
}

bool DependencyContainer::createUserRepository() {
    userRepositoryInterface_ = new (std::nothrow) UserRepository(
        configProviderInterface_, sharedStateInterface_, qmlRoot_);
    if (!userRepositoryInterface_) {
        qCritical() << "Ошибка выделения памяти в createUserRepository";
        return false;
    }
    return true;
}

bool DependencyContainer::createWeatherApiSource() {
    apiWeatherSourceInterface_ = new (std::nothrow) WeatherApiSource(
        configProviderInterface_, qmlRoot_);
    if (!apiWeatherSourceInterface_) {
        qCritical() << "Ошибка выделения памяти в createWeatherApiSource";
        return false;
    }
    return true;
}

void DependencyContainer::setDbWeatherHistoryRepository() {
    dbWeatherHistoryInterface_ =
        std::make_shared<SqliteWeatherHistoryRepository>(
            dbInitializerInterface_, sharedStateInterface_);
}

bool DependencyContainer::createWeatherRepository() {
    weatherRepositoryInterface_ = new (std::nothrow) WeatherRepository(
        cacheSourceInterface_, apiWeatherSourceInterface_, qmlRoot_);
    if (!weatherRepositoryInterface_) {
        qCritical() << "Ошибка выделения памяти в createWeatherRepository";
        return false;
    }
    return true;
}

bool DependencyContainer::createAuthUseCase() {
    try {
        authUseCase_ =
            std::make_shared<AuthenticateUserUseCase>(userRepositoryInterface_);
    } catch (const std::bad_alloc& e) {
        qCritical() << "Ошибка выделения памяти в createAuthUseCase:" << e.what();
        return false;
    }
    return true;
}

bool DependencyContainer::createRegUseCase() {
    try {
        regUseCase_ =
            std::make_shared<RegisterUserUseCase>(userRepositoryInterface_);
    } catch (const std::bad_alloc& e) {
        qCritical() << "Ошибка выделения памяти в createRegUseCase:" << e.what();
        return false;
    }
    return true;
}

bool DependencyContainer::createDailyWeatherUseCase() {
    try {
        dailyWeatherUseCase_ =
            std::make_shared<GetDailyWeatherUseCase>(weatherRepositoryInterface_);
    } catch (const std::bad_alloc& e) {
        qCritical() << "Ошибка выделения памяти в createDailyWeatherUseCase:" << e.what();
        return false;
    }
    return true;
}

bool DependencyContainer::createWeeklyWeatherUseCase() {
    try {
        weeklyWeatherUseCase_ =
            std::make_shared<GetWeeklyWeatherUseCase>(weatherRepositoryInterface_);
    } catch (const std::bad_alloc& e) {
        qCritical() << "Ошибка выделения памяти в createWeeklyWeatherUseCase:" << e.what();
        return false;
    }
    return true;
}

bool DependencyContainer::createSaveHistoryUseCase() {
    try {
        saveHistoryUseCase_ =
            std::make_shared<SaveWeatherHistoryUseCase>(dbWeatherHistoryInterface_);
    } catch (const std::bad_alloc& e) {
        qCritical() << "Ошибка выделения памяти в createSaveHistoryUseCase:" << e.what();
        return false;
    }
    return true;
}

bool DependencyContainer::createGetHistoryUseCase() {
    try {
        getHistoryUseCase_ =
            std::make_shared<GetWeatherHistoryUseCase>(dbWeatherHistoryInterface_);
    } catch (const std::bad_alloc& e) {
        qCritical() << "Ошибка выделения памяти в createGetHistoryUseCase:" << e.what();
        return false;
    }
    return true;
}

bool DependencyContainer::createAuthViewModel() {
    authViewModel_ = new (std::nothrow) AuthViewModel(authUseCase_, regUseCase_, qmlRoot_);
    if (!authViewModel_) {
        qCritical() << "Ошибка выделения памяти в createAuthViewModel";
        return false;
    }
    return true;
}

bool DependencyContainer::createWeatherViewModel() {
    weatherViewModel = new (std::nothrow) WeatherViewModel(dailyWeatherUseCase_,
                                                           weeklyWeatherUseCase_,
                                                           saveHistoryUseCase_,
                                                           qmlRoot_);
    if (!weatherViewModel) {
        qCritical() << "Ошибка выделения памяти в createWeatherViewModel";
        return false;
    }
    return true;
}
