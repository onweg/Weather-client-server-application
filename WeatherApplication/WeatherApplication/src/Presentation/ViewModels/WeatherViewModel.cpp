#include "WeatherViewModel.h"
#include "../../Domain/Utils/Result.h"
#include "../../Domain/Entities/WeatherData.h"
#include "../../Domain/Entities/WeekWeatherData.h"
#include "../Mappers/WeatherUiMapper.h"
#include "../Mappers/WeekWeatherUiMapper.h"
#include <QDebug>


WeatherViewModel::WeatherViewModel(std::shared_ptr<GetDailyWeatherUseCase> getDailyWeatherUC,
                              std::shared_ptr<GetWeeklyWeatherUseCase> getWeeklyWeatherUC,
                              std::shared_ptr<SaveWeatherHistoryUseCase> saveHistoryUC,
                              QObject* parent)
    : QObject(parent),
          getDailyWeatherUseCase_(std::move(getDailyWeatherUC)),
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

    auto future = getDailyWeatherUseCase_->execute(desiredCity_.toStdString(), desiredDate_.toString("yyyy-MM-dd").toStdString());

    auto* watcher = new QFutureWatcher<Result<WeatherData>>(this);
    connect(watcher, &QFutureWatcherBase::finished, this, [this, watcher]() {
        const auto result = watcher->result();
        if (result.isSuccess()) {
            WeatherUiMapper::toUiModel(result.value(), weatherModel_);
        } else {
            WeatherUiMapper::toUiModel({}, weatherModel_);
            weatherModel_->setMessageError(QString::fromStdString(result.errorMessage()));
        }
        emit weatherDataUpdated();
        watcher->deleteLater();
    });
    watcher->setFuture(future);
}

void WeatherViewModel::clickNextDayButton()
{
    QDate nextDate = desiredDate_.addDays(1);
    if (!isDateValid(nextDate)) {
        return;
    }
    desiredDate_ = nextDate;
    
    auto future = getDailyWeatherUseCase_->execute(desiredCity_.toStdString(), desiredDate_.toString("yyyy-MM-dd").toStdString());

    auto* watcher = new QFutureWatcher<Result<WeatherData>>(this);
    connect(watcher, &QFutureWatcherBase::finished, this, [this, watcher]() {
        const auto result = watcher->result();
        if (result.isSuccess()) {
            WeatherUiMapper::toUiModel(result.value(), weatherModel_);
        } else {
            WeatherUiMapper::toUiModel({}, weatherModel_);
            weatherModel_->setMessageError(QString::fromStdString(result.errorMessage()));
        }
        emit weatherDataUpdated();
        watcher->deleteLater();
    });
    watcher->setFuture(future);
}

void WeatherViewModel::clickPrevDayButton()
{
    QDate prevDate = desiredDate_.addDays(-1);
    if (!isDateValid(prevDate)) {
        return;
    }
    desiredDate_ = prevDate;

    auto future = getDailyWeatherUseCase_->execute(desiredCity_.toStdString(), desiredDate_.toString("yyyy-MM-dd").toStdString());

    auto* watcher = new QFutureWatcher<Result<WeatherData>>(this);
    connect(watcher, &QFutureWatcherBase::finished, this, [this, watcher]() {
        const auto result = watcher->result();
        if (result.isSuccess()) {
            WeatherUiMapper::toUiModel(result.value(), weatherModel_);
        } else {
            WeatherUiMapper::toUiModel({}, weatherModel_);
            weatherModel_->setMessageError(QString::fromStdString(result.errorMessage()));
        }
        emit weatherDataUpdated();
        watcher->deleteLater();
    });
    watcher->setFuture(future);
}

void WeatherViewModel::clickWeekWeatherDataButton()
{
    auto future = getWeeklyWeatherUseCase_->execute(desiredCity_.toStdString());

    auto* watcher = new QFutureWatcher<Result<WeekWeatherData>>(this);
    connect(watcher, &QFutureWatcherBase::finished, this, [this, watcher]() {
        const auto result = watcher->result();
        if (result.isSuccess()) {
            WeekWeatherUiMapper::toUiModel(result.value(), weekWeatherModel_);
        } else {
            WeekWeatherUiMapper::toUiModel({}, weekWeatherModel_);
            weekWeatherModel_->setMessageError(QString::fromStdString(result.errorMessage()));
        }
        emit weekWeatherDataUpdated();
        watcher->deleteLater();
    });
    watcher->setFuture(future);
}

WeatherUiModel *WeatherViewModel::getWeatherModel()
{
    return weatherModel_;
}

WeekWeatherUiModel *WeatherViewModel::getWeekWeatherModel()
{
    return weekWeatherModel_;
}

bool WeatherViewModel::isDateValid(const QDate& date)
{
    QDate today = QDate::currentDate();
    QDate daysLater = today.addDays(MAX_COUNT_DAYS - 1);

    return (date >= today) && (date <= daysLater);
}
