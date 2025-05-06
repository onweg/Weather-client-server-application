#ifndef WEATHERVIEWMODEL_H
#define WEATHERVIEWMODEL_H

#include <QObject>
#include <memory>
#include "../UIModels/WeatherUIModel.h"
#include "../UIModels/WeekWeatherUIModel.h"
#include "../../Domain/UseCases/GetDailyWeatherUseCase.h"
#include "../../Domain/UseCases/GetWeeklyWeatherUseCase.h"

class WeatherViewModel : public QObject  {
     Q_OBJECT
public:
    explicit WeatherViewModel(std::shared_ptr<GetDailyWeatherUseCase> dailyUC, std::shared_ptr<GetWeeklyWeatherUseCase> weeklyUC, QObject* parent = nullptr);
    Q_INVOKABLE void clickSearchCityButton(const QString &city);
    Q_INVOKABLE void clickNextDayButton();
    Q_INVOKABLE void clickPrevDayButton();
    Q_INVOKABLE void clickWeekWeatherDataButton();

    Q_PROPERTY(WeatherUiModel* weatherModel READ getWeatherModel NOTIFY weatherDataUpdated)
    Q_PROPERTY(WeekWeatherUiModel* weekWeatherModel READ getWeekWeatherModel NOTIFY weatherDataUpdated)

private:
    QString desiredCity_;
    QDate desiredDate_;

    WeatherUiModel* weatherModel_;
    WeekWeatherUiModel* weekWeatherModel_;

    WeatherUiModel* getWeatherModel();
    WeekWeatherUiModel* getWeekWeatherModel();
    bool isDateValid(const QDate& date);

    std::shared_ptr<GetDailyWeatherUseCase> dailyUseCase_;
    std::shared_ptr<GetWeeklyWeatherUseCase> weeklyUseCase_;

    const int MAX_COUNT_DAYS = 5;

signals:
    void weatherDataUpdated();


};

#endif // WEATHERVIEWMODEL_H
