#include "DependencyContainer.h"

#include <QDebug>

#include "../data/repositories/api/UserRepository.h"
#include "../data/repositories/api/WeatherApiSource.h"
#include "../data/repositories/cache/WeatherCache.h"
#include "../data/repositories/config/ConfigLoader.h"
#include "../data/repositories/config/ConfigProvider.h"
#include "../data/repositories/database/SqliteWeatherHistoryRepository.h"
#include "../data/repositories/database/WeatherDatabaseInitializer.h"
#include "../data/repositories/sharedstate/SharedState.h"
#include "../data/repositories/weather/WeatherRepository.h"

DependencyContainer::DependencyContainer(QObject *qmlRoot)
 : sharedStateInterface_(nullptr), configLoaderInterface_(nullptr),
   configProviderInterface_(nullptr), cacheSourceInterface_(nullptr),
   dbInitializerInterface_(nullptr), userRepositoryInterface_(nullptr),
   apiWeatherSourceInterface_(nullptr), weatherRepositoryInterface_(nullptr),
   authUseCase_(nullptr), regUseCase_(nullptr), dailyWeatherUseCase_(nullptr),
   weeklyWeatherUseCase_(nullptr), saveHistoryUseCase_(nullptr),
   getHistoryUseCase_(nullptr), authViewModel_(nullptr),
   weatherViewModel(nullptr), qmlRoot_(qmlRoot)
{
}

bool DependencyContainer::init()
{
	bool success = true;
	success &= initInfrastructure();
	success &= initRepositories();
	success &= initUseCases();
	success &= initViewModels();
	return success;
}

AuthViewModel *DependencyContainer::getAuthViewModel()
{
	return authViewModel_;
}

WeatherViewModel *DependencyContainer::getWeatherViewModel()
{
	return weatherViewModel;
}

bool DependencyContainer::initInfrastructure()
{
	bool success = true;
	success &= createSharedState();
	success &= createConfigLoader();
	success &= createDbInitializer();
	return success;
}

bool DependencyContainer::initRepositories()
{
	bool success = true;
	success &= createConfigProvider();
	success &= createWeatherCache();
	success &= createUserRepository();
	success &= createWeatherApiSource();
	setDbWeatherHistoryRepository();
	success &= createWeatherRepository();
	return success;
}

bool DependencyContainer::initUseCases()
{
	bool success = true;
	success &= createAuthUseCase();
	success &= createRegUseCase();
	success &= createDailyWeatherUseCase();
	success &= createWeeklyWeatherUseCase();
	success &= createSaveHistoryUseCase();
	success &= createGetHistoryUseCase();
	return success;
}

bool DependencyContainer::initViewModels()
{
	bool success = true;
	success &= createAuthViewModel();
	success &= createWeatherViewModel();
	return success;
}

bool DependencyContainer::createSharedState()
{
	bool success = true;
	try
	{
		sharedStateInterface_ = std::make_shared<SharedState>();
	}
	catch (const std::bad_alloc &e)
	{
		qCritical() << "Ошибка выделения памяти в createSharedState:"
		            << e.what();
		success = false;
	}
	return success;
}

bool DependencyContainer::createConfigLoader()
{
	bool success = true;
	try
	{
		configLoaderInterface_ = std::make_shared<ConfigLoader>();
	}
	catch (const std::bad_alloc &e)
	{
		qCritical() << "Ошибка выделения памяти в createConfigLoader:"
		            << e.what();
		success = false;
	}
	return success;
}

bool DependencyContainer::createWeatherCache()
{
	bool success = true;
	try
	{
		cacheSourceInterface_ =
		    std::make_shared<WeatherCache>(configProviderInterface_);
	}
	catch (const std::bad_alloc &e)
	{
		qCritical() << "Ошибка выделения памяти в createWeatherCache:"
		            << e.what();
		success = false;
	}
	return success;
}

bool DependencyContainer::createDbInitializer()
{
	bool success = true;
	try
	{
		dbInitializerInterface_ =
		    std::make_shared<WeatherDatabaseInitializer>();
	}
	catch (const std::bad_alloc &e)
	{
		qCritical() << "Ошибка выделения памяти в createDbInitializer:"
		            << e.what();
		success = false;
	}
	return success;
}

bool DependencyContainer::createConfigProvider()
{
	bool success = true;
	try
	{
		configProviderInterface_ =
		    std::make_shared<ConfigProvider>(configLoaderInterface_);
	}
	catch (const std::bad_alloc &e)
	{
		qCritical() << "Ошибка выделения памяти в createConfigProvider:"
		            << e.what();
		success = false;
	}
	return success;
}

bool DependencyContainer::createUserRepository()
{
	bool success = true;
	userRepositoryInterface_ = new (std::nothrow) UserRepository(
	    configProviderInterface_, sharedStateInterface_, qmlRoot_);
	if (!userRepositoryInterface_)
	{
		qCritical() << "Ошибка выделения памяти в createUserRepository";
		success = false;
	}
	return success;
}

bool DependencyContainer::createWeatherApiSource()
{
	bool success = true;
	apiWeatherSourceInterface_ =
	    new (std::nothrow) WeatherApiSource(configProviderInterface_, qmlRoot_);
	if (!apiWeatherSourceInterface_)
	{
		qCritical() << "Ошибка выделения памяти в createWeatherApiSource";
		success = false;
	}
	return success;
}

bool DependencyContainer::setDbWeatherHistoryRepository()
{
	bool success = true;
	dbWeatherHistoryInterface_ =
	    std::make_shared<SqliteWeatherHistoryRepository>(
	        dbInitializerInterface_, sharedStateInterface_);
	if (!apiWeatherSourceInterface_)
	{
		qCritical() << "Ошибка выделения памяти в createWeatherApiSource";
		success = false;
	}
	return success;
}

bool DependencyContainer::createWeatherRepository()
{
	bool success = true;
	weatherRepositoryInterface_ = new (std::nothrow) WeatherRepository(
	    cacheSourceInterface_, apiWeatherSourceInterface_, qmlRoot_);
	if (!weatherRepositoryInterface_)
	{
		qCritical() << "Ошибка выделения памяти в createWeatherRepository";
		success = false;
	}
	return success;
}

bool DependencyContainer::createAuthUseCase()
{
	bool success = true;
	try
	{
		authUseCase_ =
		    std::make_shared<AuthenticateUserUseCase>(userRepositoryInterface_);
	}
	catch (const std::bad_alloc &e)
	{
		qCritical() << "Ошибка выделения памяти в createAuthUseCase:"
		            << e.what();
		success = false;
	}
	return success;
}

bool DependencyContainer::createRegUseCase()
{
	bool success = true;
	try
	{
		regUseCase_ =
		    std::make_shared<RegisterUserUseCase>(userRepositoryInterface_);
	}
	catch (const std::bad_alloc &e)
	{
		qCritical() << "Ошибка выделения памяти в createRegUseCase:"
		            << e.what();
		success = false;
	}
	return success;
}

bool DependencyContainer::createDailyWeatherUseCase()
{
	bool success = true;
	try
	{
		dailyWeatherUseCase_ = std::make_shared<GetDailyWeatherUseCase>(
		    weatherRepositoryInterface_);
	}
	catch (const std::bad_alloc &e)
	{
		qCritical() << "Ошибка выделения памяти в createDailyWeatherUseCase:"
		            << e.what();
		success = false;
	}
	return success;
}

bool DependencyContainer::createWeeklyWeatherUseCase()
{
	bool success = true;
	try
	{
		weeklyWeatherUseCase_ = std::make_shared<GetWeeklyWeatherUseCase>(
		    weatherRepositoryInterface_);
	}
	catch (const std::bad_alloc &e)
	{
		qCritical() << "Ошибка выделения памяти в createWeeklyWeatherUseCase:"
		            << e.what();
		success = false;
	}
	return success;
}

bool DependencyContainer::createSaveHistoryUseCase()
{
	bool success = true;
	try
	{
		saveHistoryUseCase_ = std::make_shared<SaveWeatherHistoryUseCase>(
		    dbWeatherHistoryInterface_);
	}
	catch (const std::bad_alloc &e)
	{
		qCritical() << "Ошибка выделения памяти в createSaveHistoryUseCase:"
		            << e.what();
		success = false;
	}
	return success;
}

bool DependencyContainer::createGetHistoryUseCase()
{
	bool success = true;
	try
	{
		getHistoryUseCase_ = std::make_shared<GetWeatherHistoryUseCase>(
		    dbWeatherHistoryInterface_);
	}
	catch (const std::bad_alloc &e)
	{
		qCritical() << "Ошибка выделения памяти в createGetHistoryUseCase:"
		            << e.what();
		success = false;
	}
	return success;
}

bool DependencyContainer::createAuthViewModel()
{
	bool success = true;
	authViewModel_ =
	    new (std::nothrow) AuthViewModel(authUseCase_, regUseCase_, qmlRoot_);
	if (!authViewModel_)
	{
		qCritical() << "Ошибка выделения памяти в createAuthViewModel";
		success = false;
	}
	return success;
}

bool DependencyContainer::createWeatherViewModel()
{
	bool success = true;
	weatherViewModel = new (std::nothrow)
	    WeatherViewModel(dailyWeatherUseCase_, weeklyWeatherUseCase_,
	                     saveHistoryUseCase_, qmlRoot_);
	if (!weatherViewModel)
	{
		qCritical() << "Ошибка выделения памяти в createWeatherViewModel";
		success = false;
	}
	return success;
}
