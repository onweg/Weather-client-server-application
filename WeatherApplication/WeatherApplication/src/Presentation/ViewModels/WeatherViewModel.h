#ifndef WEATHERVIEWMODEL_H
#define WEATHERVIEWMODEL_H

#include <QObject>
#include <memory>
#include <QFutureWatcher>
#include "../UIModels/WeatherUiModel.h"
#include "../UIModels/WeekWeatherUiModel.h"
#include "../../Domain/UseCases/GetDailyWeatherUseCase.h"
#include "../../Domain/UseCases/GetWeeklyWeatherUseCase.h"
#include "../../Domain/UseCases/SaveWeatherHistoryUseCase.h"

class WeatherViewModel : public QObject  {
     Q_OBJECT

    Q_PROPERTY(WeatherUiModel* weatherModel READ getWeatherModel NOTIFY weatherDataUpdated)
    Q_PROPERTY(WeekWeatherUiModel* weekWeatherModel READ getWeekWeatherModel NOTIFY weatherDataUpdated)
public:
    explicit WeatherViewModel(std::shared_ptr<GetDailyWeatherFromCacheUseCase> dailyCacheUC,
                              std::shared_ptr<GetWeeklyWeatherFromCacheUseCase> weeklyCacheUC,
                              std::shared_ptr<SaveWeeklyWeatherToCacheUseCase> weeklyCacheSaveUseCase_,
                              std::shared_ptr<GetWeeklyWeatherFromApiUseCase> weeklyApiUC,
                              std::shared_ptr<SaveWeatherHistoryUseCase> saveHistory,
                              QObject* parent = nullptr);
    Q_INVOKABLE void clickSearchCityButton(const QString &city);
    Q_INVOKABLE void clickNextDayButton();
    Q_INVOKABLE void clickPrevDayButton();
    Q_INVOKABLE void clickWeekWeatherDataButton();


private:
    QString desiredCity_;
    QDate desiredDate_;

    WeatherUiModel* weatherModel_;
    WeekWeatherUiModel* weekWeatherModel_;

    WeatherUiModel* getWeatherModel();
    WeekWeatherUiModel* getWeekWeatherModel();
    bool isDateValid(const QDate& date);

    std::shared_ptr<GetDailyWeatherFromCacheUseCase> dailyCacheUseCase_;
    std::shared_ptr<GetWeeklyWeatherFromCacheUseCase> weeklyCacheUseCase_;
    std::shared_ptr<GetWeeklyWeatherFromApiUseCase> weeklyApiUseCase_;
    std::shared_ptr<SaveWeeklyWeatherToCacheUseCase> weeklyCacheSaveUseCase_;
    std::shared_ptr<SaveWeatherHistoryUseCase> saveHistoryUseCase_;

    QFutureWatcher<Result<WeekWeatherData>> weeklyApiWatcher_;

    const int MAX_COUNT_DAYS = 5;

    enum class RequestType {
        DailyRequest,
        WeeklyRequest
    };

    RequestType currentReqestType_;


private slots:
    void onWeeklyApiFinished();

signals:
    void weatherDataUpdated();


};

#endif // WEATHERVIEWMODEL_H
