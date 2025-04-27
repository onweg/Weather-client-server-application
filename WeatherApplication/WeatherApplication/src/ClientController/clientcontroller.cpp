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
    // qDebug() << weatherData.city << " " << weatherData.date.toString("yyyy-MM-dd");
    emit findWeatherData(weatherData.city, weatherData.date);
}

void ClientController::clickPrevDayButton()
{
    setPrevDay();
    // qDebug() << weatherData.city << " " << weatherData.date.toString("yyyy-MM-dd");
    emit findWeatherData(weatherData.city, weatherData.date);
}

void ClientController::clickWeekWeatherDataButton()
{
    // if (!weatherData.city.isEmpty() && weatherData.city != "..." && weatherData.city != "Город не найден!") {
         emit findWeekWeatherData();
    // }
}

void ClientController::sendAuthorizationData(const QString &command, const QString &login, const QString &password)
{
    emit sendAuthorizationDataToManager(command, login, password);
}

QVariantMap ClientController::getWeatherDataFromOneDay()
{
    return QVariant::fromValue(weatherData);
}

QVariantMap ClientController::getWeatherDataFromWeek()
{
    return QVariant::fromValue(weekWeatherData);
}

void ClientController::slotWeatherDataArrived(const WeatherData &data)
{
    // qDebug() << "Получил";
    // setData(data);
    weatherData = data;
    emit dataUpdated();
}

void ClientController::slotWeekWeatherDataArrived(const WeekWeatherData &data)
{
    // QJsonDocument doc(jsonObj);
    // qDebug().noquote() << doc.toJson(QJsonDocument::Indented);
    weekWeatherData = data;
    emit weekDataUpdated();
    // qDebug() << "Emit отправлен";
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

// void ClientController::setData(const QJsonObject &jsonObj) {
//     if (jsonObj.contains("error")) {
//         weatherData.city = jsonObj["error"].toString();
//     } else {
//         weatherData.city = jsonObj["city"].toString();
//     }
//     weatherData.date = QDate::fromString(jsonObj["date"].toString(), "yyyy-MM-dd");
//     weatherData.description = jsonObj["description"].toString();
//     weatherData.temp = jsonObj["temp"].toDouble();
//     weatherData.feels_like = jsonObj["feels_like"].toDouble();
//     weatherData.temp_max = jsonObj["temp_max"].toDouble();
//     weatherData.temp_min = jsonObj["temp_min"].toDouble();
//     weatherData.wind_speed = jsonObj["wind_speed"].toDouble();
//     weatherData.humidity = jsonObj["humidity"].toInt();
//     weatherData.pressure = jsonObj["pressure"].toInt();
//     emit dataUpdated();
//     // updater->resetTimer();
//     return;
// }

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

// QVariantMap ClientController::convertToVariantMap(const WeatherData &data) const
// {
//     QVariantMap result;
//     result["city"] = data.city;
//     result["date"] = data.date.toString("yyyy-MM-dd");
//     result["description"] = data.description;
//     result["temp"] = QString::number(data.temp);
//     result["feels_like"] = QString::number(data.feels_like);
//     result["temp_max"] = QString::number(data.temp_max);
//     result["temp_min"] = QString::number(data.temp_min);
//     result["wind_speed"] = QString::number(data.wind_speed);
//     result["humidity"] = QString::number(data.humidity);
//     result["pressure"] = QString::number(data.pressure);
//     return result;
// }



