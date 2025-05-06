#include "WeatherViewModel.h"
#include "../../Domain/Utils/Result.h"
#include "../../Domain/Entities/WeatherData.h"
#include "../../Domain/Entities/WeekWeatherData.h"
#include "../Mappers/WeatherUIMapper.h"
#include "../Mappers/WeekWeatherUIMapper.h"
#include <QDebug>

WeatherViewModel::WeatherViewModel(std::shared_ptr<GetDailyWeatherUseCase> dailyUC, std::shared_ptr<GetWeeklyWeatherUseCase> weeklyUC, QObject *parent)
    : QObject(parent), dailyUseCase_(std::move(dailyUC)), weeklyUseCase_(std::move(weeklyUC))
{
    weatherModel_ = new WeatherUiModel(this);
    weekWeatherModel_ = new WeekWeatherUiModel(this);
}

void WeatherViewModel::clickSearchCityButton(const QString &city)
{
    desiredCity_ = city;
    desiredDate_ = QDate::currentDate();
    dailyUseCase_->execute(city.toStdString(), QDate::currentDate().toString("yyyy-MM-dd").toStdString(), [this](Result<WeatherData> result){
        if (result.isSuccess()) {
            WeatherUiMapper::toUiModel(result.value(), weatherModel_);
        } else {
            WeatherUiMapper::toUiModel({}, weatherModel_);
            weatherModel_->setMessageError(QString::fromStdString(result.errorMessage()));
        }
    });
}

void WeatherViewModel::clickNextDayButton()
{
    QDate nextDate = desiredDate_.addDays(1);
    if (!isDateValid(nextDate)) {
        qDebug() << "Дата выходит за пределы допустимого диапазона";
        return;
    }
    desiredDate_ = nextDate;
    dailyUseCase_->execute(desiredCity_.toStdString(), nextDate.toString("yyyy-MM-dd").toStdString(), [this](Result<WeatherData> result){
        if (result.isSuccess()) {
            WeatherUiMapper::toUiModel(result.value(), weatherModel_);
        } else {
            WeatherUiMapper::toUiModel({}, weatherModel_);
            weatherModel_->setMessageError(QString::fromStdString(result.errorMessage()));
        }

    });
}

void WeatherViewModel::clickPrevDayButton()
{
    QDate prevDate = desiredDate_.addDays(-1);
    if (!isDateValid(prevDate)) {
        qDebug() << "Дата выходит за пределы допустимого диапазона";
        return;
    }
    desiredDate_ = prevDate;
    dailyUseCase_->execute(desiredCity_.toStdString(), prevDate.toString("yyyy-MM-dd").toStdString(), [this](Result<WeatherData> result){
        if (result.isSuccess()) {
            WeatherUiMapper::toUiModel(result.value(), weatherModel_);
        } else {
            WeatherUiMapper::toUiModel({}, weatherModel_);
            weatherModel_->setMessageError(QString::fromStdString(result.errorMessage()));
        }

    });
}

void WeatherViewModel::clickWeekWeatherDataButton()
{
    weeklyUseCase_->execute(desiredCity_.toStdString(), [this](Result<WeekWeatherData> result) {
    if (result.isSuccess()) {
        WeekWeatherUiMapper::toUiModel(result.value(), weekWeatherModel_);
    } else {
        WeekWeatherUiMapper::toUiModel({}, weekWeatherModel_);
        weekWeatherModel_->setMessageError(QString::fromStdString(result.errorMessage()));
    }

    });
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

