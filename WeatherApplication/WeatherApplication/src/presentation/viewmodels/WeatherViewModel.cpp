#include "WeatherViewModel.h"

#include <QDebug>

#include "../../domain/entities/WeatherData.h"
#include "../../domain/entities/WeekWeatherData.h"
#include "../../domain/utils/Result.h"
#include "../mappers/WeatherUiMapper.h"
#include "../mappers/WeekWeatherUiMapper.h"

WeatherViewModel::WeatherViewModel(
    std::shared_ptr<GetDailyWeatherUseCase> getDailyWeatherUC,
    std::shared_ptr<GetWeeklyWeatherUseCase> getWeeklyWeatherUC,
    std::shared_ptr<SaveWeatherHistoryUseCase> saveHistoryUC, QObject *parent)
 : QObject(parent), getDailyWeatherUseCase_(std::move(getDailyWeatherUC)),
   getWeeklyWeatherUseCase_(std::move(getWeeklyWeatherUC)),
   saveHistoryUseCase_(std::move(saveHistoryUC))
{
	weatherModel_ = new WeatherUiModel(this);
	weekWeatherModel_ = new WeekWeatherUiModel(this);
}

void WeatherViewModel::clickSearchCityButton(const QString &city)
{
	desiredCity_ = city;
	desiredDate_ = QDate::currentDate();
	fetchAndSetDailyWeather();
}

void WeatherViewModel::clickNextDayButton()
{
	changeDateAndFetch(1);
}

void WeatherViewModel::clickPrevDayButton()
{
	changeDateAndFetch(-1);
}

void WeatherViewModel::clickWeekWeatherDataButton()
{
	try
	{
		auto future =
		    getWeeklyWeatherUseCase_->execute(desiredCity_.toStdString());
		setupWeeklyWeatherWatcher(future);
	}
	catch (const std::runtime_error &error)
	{
		WeekWeatherUiMapper::toUiModel({}, weekWeatherModel_);
		weekWeatherModel_->setMessageError(
		    QString::fromStdString(error.what()));
		emit weekWeatherDataUpdated();
	}
}

WeatherUiModel *WeatherViewModel::getWeatherModel()
{
	return weatherModel_;
}

WeekWeatherUiModel *WeatherViewModel::getWeekWeatherModel()
{
	return weekWeatherModel_;
}

bool WeatherViewModel::isDateValid(const QDate &date)
{
	QDate today = QDate::currentDate();
	QDate daysLater = today.addDays(MAX_COUNT_DAYS - 1);
	return (date >= today) && (date <= daysLater);
}

void WeatherViewModel::changeDateAndFetch(int daysOffset)
{
	QDate newDate = desiredDate_.addDays(daysOffset);
	if (!isDateValid(newDate))
		return;
	desiredDate_ = newDate;
	fetchAndSetDailyWeather();
}

void WeatherViewModel::fetchAndSetDailyWeather()
{
	try
	{
		auto future = getDailyWeatherUseCase_->execute(
		    desiredCity_.toStdString(),
		    desiredDate_.toString("yyyy-MM-dd").toStdString());
		setupDailyWeatherWatcher(future);
	}
	catch (const std::runtime_error &error)
	{
		WeatherUiMapper::toUiModel({}, weatherModel_);
		weatherModel_->setMessageError(QString::fromStdString(error.what()));
		emit weatherDataUpdated();
	}
}

void WeatherViewModel::setupDailyWeatherWatcher(
    QFuture<Result<WeatherData>> future)
{
	auto *watcher = new QFutureWatcher<Result<WeatherData>>(this);
	connect(watcher, &QFutureWatcherBase::finished, this,
	        [this, watcher]()
	        {
		        handleDailyWeatherResult(watcher->result());
		        watcher->deleteLater();
	        });
	watcher->setFuture(future);
}

void WeatherViewModel::handleDailyWeatherResult(
    const Result<WeatherData> &result)
{
	if (result.isSuccess())
	{
		WeatherUiMapper::toUiModel(result.value(), weatherModel_);
		weatherModel_->setMessageError("");
	}
	else
	{
		WeatherUiMapper::toUiModel({}, weatherModel_);
		weatherModel_->setMessageError(
		    QString::fromStdString(result.errorMessage()));
	}
	emit weatherDataUpdated();
}

void WeatherViewModel::setupWeeklyWeatherWatcher(
    QFuture<Result<WeekWeatherData>> future)
{

	auto *watcher = new QFutureWatcher<Result<WeekWeatherData>>(this);
	connect(watcher, &QFutureWatcherBase::finished, this,
	        [this, watcher]()
	        {
		        handleWeeklyWeatherResult(watcher->result());
		        watcher->deleteLater();
	        });
	watcher->setFuture(future);
}

void WeatherViewModel::handleWeeklyWeatherResult(
    const Result<WeekWeatherData> &result)
{
	if (result.isSuccess())
	{
		WeekWeatherUiMapper::toUiModel(result.value(), weekWeatherModel_);
		weekWeatherModel_->setMessageError("");
	}
	else
	{
		WeekWeatherUiMapper::toUiModel({}, weekWeatherModel_);
		weekWeatherModel_->setMessageError(
		    QString::fromStdString(result.errorMessage()));
	}
}
