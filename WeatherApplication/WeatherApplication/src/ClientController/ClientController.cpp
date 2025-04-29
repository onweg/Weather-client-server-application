#include "ClientController.h"

ClientController::ClientController(QObject *parent) : QObject(parent)
{
    updater_ = new WeatherUpdater();
    updaterThread_.reset(new QThread());
    QObject::connect(updaterThread_.data(), &QThread::started, updater_, &WeatherUpdater::start);
    QObject::connect(updater_, &WeatherUpdater::updateWeatherData, this, &ClientController::slotUpdateWeatherFromUpdater);
    
    updater_->moveToThread(updaterThread_.data());
    updaterThread_->start();

    weatherModel_ = new WeatherModel(this);
    weekWeatherModel_ = new WeekWeatherModel(this);

}

ClientController::~ClientController()
{
    if (updaterThread_) {
        updaterThread_->quit();
        updaterThread_->wait();
    }
    delete updater_;
    updater_ = nullptr;
}

void ClientController::clickSearchCityButton(const QString &city)
{
    emit findWeatherData(city);
}

void ClientController::clickNextDayButton()
{
    setNextDay();
    emit findWeatherData(weatherData_.city, weatherData_.date);
}

void ClientController::clickPrevDayButton()
{
    setPrevDay();
    emit findWeatherData(weatherData_.city, weatherData_.date);
}

void ClientController::clickWeekWeatherDataButton()
{
    emit findWeekWeatherData();
}

void ClientController::sendAuthorizationData(const QString &command, const QString &login, const QString &password)
{
    emit sendAuthorizationDataToManager(command, login, password);
}

void ClientController::slotWeatherDataArrived(const WeatherData &data)
{
    if (weatherData_ == data) {
        return;
    }
    weatherData_ = data;
    weatherModel_->setData(weatherData_);
    emit weatherDataUpdated();
}

void ClientController::slotWeekWeatherDataArrived(const WeekWeatherData &data)
{
    weekWeatherData_ = data;
    weekWeatherModel_->setData(weekWeatherData_);
    emit weekWeatherDataUpdated();
}

void ClientController::slotRecivedAuthorizationData(const AuthorizationReply &authorizationReply)
{
    if (authorizationReply.success) {
        emit authorizationCompleted();
    } else {
        emit authorizationFailed(authorizationReply.message);
    }
}

void ClientController::slotUpdateWeatherFromUpdater()
{
    emit findWeatherData(weatherData_.city, weatherData_.date);
}

void ClientController::setNextDay()
{
    if (!weatherData_.date.isValid()) {
        weatherData_.date = QDate();
    }
    const QDate tmp = QDate::currentDate();
    int diff = tmp.daysTo(weatherData_.date);
    if (diff < NUMBEROFDAYS - 1) {
        weatherData_.date = weatherData_.date.addDays(1);
    }
    return;
}

void ClientController::setPrevDay()
{
    if (!weatherData_.date.isValid()) {
        weatherData_.date = QDate();
    }
    const QDate tmp = QDate::currentDate();
    int diff = tmp.daysTo(weatherData_.date);
    if (diff > 0) {
        weatherData_.date = weatherData_.date.addDays(-1);
    }
    return;
}

WeatherModel* ClientController::getWeatherModel()
{
    return weatherModel_;
}

WeekWeatherModel* ClientController::getWeekWeatherModel()
{
    return weekWeatherModel_;
}



