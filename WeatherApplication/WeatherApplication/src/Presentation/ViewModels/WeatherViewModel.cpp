#include "WeatherViewModel.h"
#include "../../Domain/Utils/Result.h"
#include "../../Domain/Entities/WeatherData.h"
#include "../../Domain/Entities/WeekWeatherData.h"
#include "../Mappers/WeatherUiMapper.h"
#include "../Mappers/WeekWeatherUiMapper.h"
#include <QDebug>


WeatherViewModel::WeatherViewModel(std::shared_ptr<GetDailyWeatherFromCacheUseCase> dailyCacheUC,
                                   std::shared_ptr<GetWeeklyWeatherFromCacheUseCase> weeklyCacheUC,
                                   std::shared_ptr<SaveWeeklyWeatherToCacheUseCase> weeklyCacheSaveUC,
                                   std::shared_ptr<GetWeeklyWeatherFromApiUseCase> weeklyApiUC,
                                   std::shared_ptr<SaveWeatherHistoryUseCase> saveHistory,
                                   QObject *parent)
    : QObject(parent),
          dailyCacheUseCase_(std::move(dailyCacheUC)),
          weeklyCacheUseCase_(std::move(weeklyCacheUC)),
          weeklyCacheSaveUseCase_(std::move(weeklyCacheSaveUC)),
          weeklyApiUseCase_(std::move(weeklyApiUC)),
          saveHistoryUseCase_(std::move(saveHistory))
{
    weatherModel_ = new WeatherUiModel(this);
    weekWeatherModel_ = new WeekWeatherUiModel(this);
}

void WeatherViewModel::clickSearchCityButton(const QString &city)
{
    desiredCity_ = city;
    desiredDate_ = QDate::currentDate();
    currentReqestType_ = RequestType::DailyRequest;
    auto result = dailyCacheUseCase_->execute(desiredCity_.toStdString(), desiredDate_.toString("yyyy-MM-dd").toStdString());
    if (result.isSuccess()) {
        WeatherUiMapper::toUiModel(result.value(), weatherModel_);
    } else {
        if (weeklyApiWatcher_.isRunning()) {
            weeklyApiWatcher_.cancel();
            weeklyApiWatcher_.waitForFinished();
        }
        connect(&weeklyApiWatcher_, &QFutureWatcher<Result<WeekWeatherData>>::finished, this, &WeatherViewModel::onWeeklyApiFinished);
        QFuture<Result<WeekWeatherData>> future = weeklyApiUseCase_->execute(desiredCity_.toStdString());
        weeklyApiWatcher_.setFuture(future);
    }
}

void WeatherViewModel::clickNextDayButton()
{
    QDate nextDate = desiredDate_.addDays(1);
    if (!isDateValid(nextDate)) {
        // отправить на UI
        qDebug() << "Дата выходит за пределы допустимого диапазона";
        return;
    }
    desiredDate_ = nextDate;
    currentReqestType_ = RequestType::DailyRequest;
    auto result = dailyCacheUseCase_->execute(desiredCity_.toStdString(), desiredDate_.toString("yyyy-MM-dd").toStdString());
    if (result.isSuccess()) {
        WeatherUiMapper::toUiModel(result.value(), weatherModel_);
    } else {
        if (weeklyApiWatcher_.isRunning()) {
            weeklyApiWatcher_.cancel();
            weeklyApiWatcher_.waitForFinished();
        }
        connect(&weeklyApiWatcher_, &QFutureWatcher<Result<WeekWeatherData>>::finished, this, &WeatherViewModel::onWeeklyApiFinished);
        QFuture<Result<WeekWeatherData>> future = weeklyApiUseCase_->execute(desiredCity_.toStdString());
        weeklyApiWatcher_.setFuture(future);
    }
}

void WeatherViewModel::clickPrevDayButton()
{
    QDate prevDate = desiredDate_.addDays(-1);
    if (!isDateValid(prevDate)) {
        qDebug() << "Дата выходит за пределы допустимого диапазона";
        return;
    }
    desiredDate_ = prevDate;
    currentReqestType_ = RequestType::DailyRequest;
    auto result = dailyCacheUseCase_->execute(desiredCity_.toStdString(), desiredDate_.toString("yyyy-MM-dd").toStdString());
    if (result.isSuccess()) {
        WeatherUiMapper::toUiModel(result.value(), weatherModel_);
    } else {
        if (weeklyApiWatcher_.isRunning()) {
            weeklyApiWatcher_.cancel();
            weeklyApiWatcher_.waitForFinished();
        }
        connect(&weeklyApiWatcher_, &QFutureWatcher<Result<WeekWeatherData>>::finished, this, &WeatherViewModel::onWeeklyApiFinished);
        QFuture<Result<WeekWeatherData>> future = weeklyApiUseCase_->execute(desiredCity_.toStdString());
        weeklyApiWatcher_.setFuture(future);
    }
}

void WeatherViewModel::clickWeekWeatherDataButton()
{
    currentReqestType_ = RequestType::WeeklyRequest;
    auto result = weeklyCacheUseCase_->execute(desiredCity_.toStdString());
    if (result.isSuccess()) {
        WeatherUiMapper::toUiModel(result.value(), weekWeatherModel_);
        weekWeatherModel_->setMessageError("");
        // emit weatherDataUpdated();
    } else {
        qDebug() << "Данных на неделю нет в кеше, запрашиваем из API";
        if (weeklyApiWatcher_.isRunning()) {
            weeklyApiWatcher_.cancel();
            weeklyApiWatcher_.waitForFinished();
        }

        connect(&weeklyApiWatcher_, &QFutureWatcher<Result<WeekWeatherData>>::finished,
                this, &WeatherViewModel::onWeeklyApiFinished);

        QFuture<Result<WeekWeatherData>> future = weeklyApiUseCase_->execute(desiredCity_.toStdString());
        weeklyApiWatcher_.setFuture(future);
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

bool WeatherViewModel::isDateValid(const QDate& date)
{
    QDate today = QDate::currentDate();
    QDate daysLater = today.addDays(MAX_COUNT_DAYS - 1);

    return (date >= today) && (date <= daysLater);
}

void WeatherViewModel::onWeeklyApiFinished()
{
    Result<WeekWeatherData> apiResult = weeklyApiWatcher_.result();
    if (apiResult.isSuccess()) {
        bool saved = weeklyCacheSaveUseCase_->execute(desiredCity_.toStdString(), apiResult.value());
        if (!saved) {
            qDebug() << "Ошибка в сохранении недельных данных в кеш";
            // throw потому что это прям косяк
        }
        if (currentReqestType_ == RequestType::DailyRequest) {
            auto dayResult = dailyCacheUseCase_->execute(desiredCity_.toStdString(), desiredDate_.toString("yyyy-MM-dd").toStdString());
            if (dayResult.isSuccess()) {
                WeatherUiMapper::toUiModel(dayResult.value(), weatherModel_);
            } else {
                WeatherUiMapper::toUiModel({}, weatherModel_);
                weatherModel_->setMessageError(QString::fromStdString(dayResult.errorMessage()));
            }
        } else if (currentReqestType_ == RequestType::WeeklyRequest) {
            auto weekResult = weeklyCacheUseCase_->execute(desiredCity_.toStdString());
            if (weekResult.isSuccess()) {
                WeekWeatherUiMapper::toUiModel(weekResult.value(), weekWeatherModel_);
            } else {
                WeekWeatherUiMapper::toUiModel({}, weekWeatherModel_);
                weekWeatherModel_->setMessageError(QString::fromStdString(weekResult.errorMessage()));
            }
        }

//         emit weatherDataUpdated();
    } else {
        if (currentReqestType_ == RequestType::DailyRequest) {
            WeatherUiMapper::toUiModel({}, weatherModel_);
            weatherModel_->setMessageError(QString::fromStdString(apiResult.errorMessage()));
        } else if (currentReqestType_ == RequestType::WeeklyRequest) {
            WeekWeatherUiMapper::toUiModel({}, weekWeatherModel_);
            weekWeatherModel_->setMessageError(QString::fromStdString(apiResult.errorMessage()));
        }
//        emit weatherDataUpdated();
    }

    disconnect(&weeklyApiWatcher_, &QFutureWatcher<Result<WeekWeatherData>>::finished,
                   this, &WeatherViewModel::onWeeklyApiFinished);
}

