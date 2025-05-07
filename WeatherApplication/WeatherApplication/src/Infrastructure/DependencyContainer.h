#ifndef DEPENDENCYCONTAINER_H
#define DEPENDENCYCONTAINER_H

#include <memory>

#include "../Presentation/ViewModels/AuthViewModel.h"
#include "../Presentation/ViewModels/WeatherViewModel.h"
#include "../Domain/UseCases/AuthenticateUserUseCase.h"
#include "../Domain/UseCases/RegisterUserUseCase.h"
#include "../Domain/UseCases/GetDailyWeatherUseCase.h"
#include "../Domain/UseCases/GetWeeklyWeatherUseCase.h"
#include "../Domain/UseCases/SaveWeatherHistoryUseCase.h"
#include "../Domain/UseCases/GetWeatherHistoryUseCase.h"
#include "../Domain/Interfaces/Config/IConfigLoader.h"
#include "../Domain/Interfaces/Config/IConfigProvider.h"
#include "../Domain/Interfaces/Api/IUserRepository.h"
#include "../Domain/Interfaces/Api/IApiWeatherSource.h"
#include "../Domain/Interfaces/SharedState/ISharedState.h"
#include "../Domain/Interfaces/Cache/IWeatherCacheSource.h"
#include "../Domain/Interfaces/Database/IWeatherDatabaseInitializer.h"
#include "../Domain/Interfaces/Database/IWeatherHistoryRepository.h"

class DependencyContainer {
public:
    explicit DependencyContainer(QObject* qmlRoot);
    AuthViewModel* getAuthViewModel();
    WeatherViewModel *getWeatherViewModel();

private:
    std::shared_ptr<ISharedState> sharedStateInterface_;
    std::shared_ptr<IConfigLoader> configLoaderInterface_;
    std::shared_ptr<IConfigProvider> configProviderInterface_;
    std::shared_ptr<IWeatherCacheSource> cacheSourceInterface_;
    std::shared_ptr<IWeatherDatabaseInitializer> dbInitializerInterface_;
    std::shared_ptr<IWeatherHistoryRepository> dbWeatherHistoryInterface_;


    IUserRepository* userRepositoryInterface_ = nullptr;
    IApiWeatherSource* apiWeatherSourceInterface_ = nullptr;;

    std::shared_ptr<AuthenticateUserUseCase> authUseCase_;
    std::shared_ptr<RegisterUserUseCase> regUseCase_;
    std::shared_ptr<GetDailyWeatherUseCase> dailyWeatherUseCase_;
    std::shared_ptr<GetWeeklyWeatherUseCase> weeklyWeatherUseCase_;
    std::shared_ptr<SaveWeatherHistoryUseCase> saveHistoryUseCase_;
    std::shared_ptr<GetWeatherHistoryUseCase> getHistoryUseCase_;


    AuthViewModel* authViewModel_ = nullptr;
    WeatherViewModel* weatherViewModel = nullptr;

    QObject* qmlRoot_;
};

#endif // DEPENDENCYCONTAINER_H
