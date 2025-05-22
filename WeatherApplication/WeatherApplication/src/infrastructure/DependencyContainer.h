#ifndef DEPENDENCYCONTAINER_H
#define DEPENDENCYCONTAINER_H

#include <memory>
#include <QObject>

#include "../domain/interfaces/api/IApiWeatherSource.h"
#include "../domain/interfaces/api/IUserRepository.h"
#include "../domain/interfaces/cache/IWeatherCacheSource.h"
#include "../domain/interfaces/config/IConfigLoader.h"
#include "../domain/interfaces/config/IConfigProvider.h"
#include "../domain/interfaces/database/IWeatherDatabaseInitializer.h"
#include "../domain/interfaces/database/IWeatherHistoryRepository.h"
#include "../domain/interfaces/sharedstate/ISharedState.h"
#include "../domain/interfaces/weather/IWeatherRepository.h"

#include "../domain/usecases/AuthenticateUserUseCase.h"
#include "../domain/usecases/GetDailyWeatherUseCase.h"
#include "../domain/usecases/GetWeatherHistoryUseCase.h"
#include "../domain/usecases/GetWeeklyWeatherUseCase.h"
#include "../domain/usecases/RegisterUserUseCase.h"
#include "../domain/usecases/SaveWeatherHistoryUseCase.h"

#include "../presentation/viewmodels/AuthViewModel.h"
#include "../presentation/viewmodels/WeatherViewModel.h"

class DependencyContainer
{
  public:
    explicit DependencyContainer(QObject *qmlRoot);
    bool init();

    AuthViewModel *getAuthViewModel();
    WeatherViewModel *getWeatherViewModel();

  private:
    std::shared_ptr<ISharedState> sharedStateInterface_;
    std::shared_ptr<IConfigLoader> configLoaderInterface_;
    std::shared_ptr<IConfigProvider> configProviderInterface_;
    std::shared_ptr<IWeatherCacheSource> cacheSourceInterface_;
    std::shared_ptr<IWeatherDatabaseInitializer> dbInitializerInterface_;
    std::shared_ptr<IWeatherHistoryRepository> dbWeatherHistoryInterface_;
    IUserRepository *userRepositoryInterface_ = nullptr;
    IApiWeatherSource *apiWeatherSourceInterface_ = nullptr;
    IWeatherRepository *weatherRepositoryInterface_ = nullptr;

    std::shared_ptr<AuthenticateUserUseCase> authUseCase_;
    std::shared_ptr<RegisterUserUseCase> regUseCase_;
    std::shared_ptr<GetDailyWeatherUseCase> dailyWeatherUseCase_;
    std::shared_ptr<GetWeeklyWeatherUseCase> weeklyWeatherUseCase_;
    std::shared_ptr<SaveWeatherHistoryUseCase> saveHistoryUseCase_;
    std::shared_ptr<GetWeatherHistoryUseCase> getHistoryUseCase_;

    AuthViewModel *authViewModel_ = nullptr;
    WeatherViewModel *weatherViewModel = nullptr;

    QObject *qmlRoot_;

    bool initInfrastructure();
    bool initRepositories();
    bool initUseCases();
    bool initViewModels();
    bool createSharedState();
    bool createConfigLoader();
    bool createWeatherCache();
    bool createDbInitializer();
    bool createConfigProvider();
    bool createUserRepository();
    bool createWeatherApiSource();
    void setDbWeatherHistoryRepository();
    bool createWeatherRepository();
    bool createAuthUseCase();
    bool createRegUseCase();
    bool createDailyWeatherUseCase();
    bool createWeeklyWeatherUseCase();
    bool createSaveHistoryUseCase();
    bool createGetHistoryUseCase();
    bool createAuthViewModel();
    bool createWeatherViewModel();
};

#endif // DEPENDENCYCONTAINER_H
