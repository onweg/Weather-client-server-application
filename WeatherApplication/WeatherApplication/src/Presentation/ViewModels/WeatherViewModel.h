#ifndef WEATHERVIEWMODEL_H
#define WEATHERVIEWMODEL_H

#include <QFutureWatcher>
#include <QObject>
#include <memory>

#include "../../Domain/UseCases/GetDailyWeatherUseCase.h"
#include "../../Domain/UseCases/GetWeeklyWeatherUseCase.h"
#include "../../Domain/UseCases/SaveWeatherHistoryUseCase.h"
#include "../UIModels/WeatherUiModel.h"
#include "../UIModels/WeekWeatherUiModel.h"

class WeatherViewModel : public QObject
{
	Q_OBJECT

	Q_PROPERTY(WeatherUiModel *weatherModel READ getWeatherModel NOTIFY
	               weatherDataUpdated)
	Q_PROPERTY(WeekWeatherUiModel *weekWeatherModel READ getWeekWeatherModel
	               NOTIFY weekWeatherDataUpdated)
  public:
	explicit WeatherViewModel(
	    std::shared_ptr<GetDailyWeatherUseCase> getDailyWeatherUC,
	    std::shared_ptr<GetWeeklyWeatherUseCase> getWeeklyWeatherUC,
	    std::shared_ptr<SaveWeatherHistoryUseCase> saveHistory,
	    QObject *parent = nullptr);

	Q_INVOKABLE void clickSearchCityButton(const QString &city);
	Q_INVOKABLE void clickNextDayButton();
	Q_INVOKABLE void clickPrevDayButton();
	Q_INVOKABLE void clickWeekWeatherDataButton();

  private:
	QString desiredCity_;
	QDate desiredDate_;

	WeatherUiModel *weatherModel_;
	WeekWeatherUiModel *weekWeatherModel_;

	std::shared_ptr<GetDailyWeatherUseCase> getDailyWeatherUseCase_;
	std::shared_ptr<GetWeeklyWeatherUseCase> getWeeklyWeatherUseCase_;
	std::shared_ptr<SaveWeatherHistoryUseCase> saveHistoryUseCase_;

	const int MAX_COUNT_DAYS = 5;

	WeatherUiModel *getWeatherModel();
	WeekWeatherUiModel *getWeekWeatherModel();
	bool isDateValid(const QDate &date);
	void changeDateAndFetch(int daysOffset);
	void fetchAndSetDailyWeather();
	void setupDailyWeatherWatcher(QFuture<Result<WeatherData>> future);
	void handleDailyWeatherResult(const Result<WeatherData> &result);
	void setupWeeklyWeatherWatcher(QFuture<Result<WeekWeatherData>> future);
	void handleWeeklyWeatherResult(const Result<WeekWeatherData> &result);

  signals:
	void weatherDataUpdated();
	void weekWeatherDataUpdated();
};

#endif // WEATHERVIEWMODEL_H
