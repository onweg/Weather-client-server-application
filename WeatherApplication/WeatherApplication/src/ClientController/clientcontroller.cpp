#include "clientcontroller.h"

ClientController::ClientController(QObject *parent) : QObject(parent)
{
    updater = new WeatherUpdater();
    updaterThread.reset(new QThread());
    QObject::connect(updaterThread.data(), &QThread::started, updater, &WeatherUpdater::start);
    QObject::connect(updater, &WeatherUpdater::updateWeatherData, this, &ClientController::slotUpdateWeatherFromUpdater);
    
    updater->moveToThread(updaterThread.data());
    updaterThread->start();

}

ClientController::~ClientController()
{
    if (updaterThread) {
        updaterThread->quit();
        updaterThread->wait();
    }
    delete updater;
    updater = nullptr;
}

void ClientController::clickSearchCityButton(const QString &city)
{
    emit findWeatherData(city);
}

void ClientController::clickNextDayButton()
{
    setNextDay();
    emit findWeatherData(weatherData.city, weatherData.date);
}

void ClientController::clickPrevDayButton()
{
    setPrevDay();
    emit findWeatherData(weatherData.city, weatherData.date);
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
    return weatherData.toVariantMap();
}

QVariantMap ClientController::getWeatherDataFromWeek()
{
    return weekWeatherData.toVariantMap();
}

void ClientController::slotWeatherDataArrived(const WeatherData &data)
{
    weatherData = data;
    emit dataUpdated();
}

void ClientController::slotWeekWeatherDataArrived(const WeekWeatherData &data)
{
    weekWeatherData = data;
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
    emit findWeatherData(weatherData.city, weatherData.date);
}

void ClientController::setNextDay()
{
    if (!weatherData.date.isValid()) {
        weatherData.date = QDate();
    }
    const QDate tmp = QDate::currentDate();
    int diff = tmp.daysTo(weatherData.date);
    if (diff < NUMBEROFDAYS - 1) {
        weatherData.date = weatherData.date.addDays(1);
    }
    return;
}

void ClientController::setPrevDay()
{
    if (!weatherData.date.isValid()) {
        weatherData.date = QDate();
    }
    const QDate tmp = QDate::currentDate();
    int diff = tmp.daysTo(weatherData.date);
    if (diff > 0) {
        weatherData.date = weatherData.date.addDays(-1);
    }
    return;
}


