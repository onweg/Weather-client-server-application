#ifndef WEATHERVIEWMODEL_H
#define WEATHERVIEWMODEL_H


#include <QObject>
#include "../../Data/DtoModels/WeatherDataDto.h"

class WeatherViewModel : public QObject  {
     Q_OBJECT
public:
    explicit WeatherViewModel(QObject* parent = nullptr);
    Q_INVOKABLE void clickSearchCityButton(const QString &data);
    Q_INVOKABLE void clickNextDayButton();
    Q_INVOKABLE void clickPrevDayButton();
    Q_INVOKABLE void clickWeekWeatherDataButton();

//    Q_PROPERTY(WeatherDataUIModel* weatherModel READ getWeatherModel NOTIFY weatherDataUpdated)
//    Q_PROPERTY(WeekWeatherDataUIModel* weatherModel READ getWeatherModel NOTIFY weatherDataUpdated)
private:


signals:
    void weatherDataUpdated();


};

#endif // WEATHERVIEWMODEL_H
