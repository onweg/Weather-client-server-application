#include "ClientController.h"

ClientController::ClientController(QObject *parent) : QObject(parent)
{
    updater_ = new WeatherUpdater();
    updaterThread_.reset(new QThread());
    QObject::connect(updaterThread_.data(), &QThread::started, updater_, &WeatherUpdater::start);
    QObject::connect(updater_, &WeatherUpdater::updateWeatherData, this, &ClientController::slotUpdateWeatherFromUpdater);
    
    updater_->moveToThread(updaterThread_.data());
    updaterThread_->start();

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

QVariantMap ClientController::getWeatherDataFromOneDay()
{
    return weatherData_.toVariantMap();
}

QVariantMap ClientController::getWeatherDataFromWeek()
{
    return weekWeatherData_.toVariantMap();
}

void ClientController::slotWeatherDataArrived(const WeatherData &data)
{
    weatherData_ = data;
    emit dataUpdated();
}

void ClientController::slotWeekWeatherDataArrived(const WeekWeatherData &data)
{
    weekWeatherData_ = data;
    emit weekDataUpdated();
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


