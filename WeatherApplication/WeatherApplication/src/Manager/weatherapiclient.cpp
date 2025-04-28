#include "weatherapiclient.h"

WeatherApiClient::WeatherApiClient(QObject *parent) : QObject(parent)
{
    manager = new QNetworkAccessManager(this);
}

void WeatherApiClient::findWeatherDataInAPI(const QString &city)
{
    qDebug() << urlFindCityByName;
    QString url = urlFindCityByName.arg(city).arg(apiKey);
    qDebug() << url;
    QNetworkRequest request((QUrl(url)));
    replyCity = manager->get(request);
    connect(replyCity, &QNetworkReply::finished, this, &WeatherApiClient::onSlotFindCity);
    return ;
}

bool WeatherApiClient::loadConfig(const QJsonObject &settingsAPI)
{
    if (!settingsAPI.contains("key") || settingsAPI["key"].toString().isEmpty()) {
        qDebug() << "Ошибка: ключ 'key' отсутствует или пуст.";
        return false;
    }
    if (!settingsAPI.contains("urlFindCityByName") || settingsAPI["urlFindCityByName"].toString().isEmpty()) {
        qDebug() << "Ошибка: ключ 'urlFindCityByName' отсутствует или пуст.";
        return false;
    }
    if (!settingsAPI.contains("urlFindWeatherByCoordinates") || settingsAPI["urlFindWeatherByCoordinates"].toString().isEmpty()) {
        qDebug() << "Ошибка: ключ 'urlFindWeatherByCoordinates' отсутствует или пуст.";
        return false;
    }
    apiKey = settingsAPI["key"].toString();
    urlFindCityByName = settingsAPI["urlFindCityByName"].toString();
    urlFindWeatherByCoordinates = settingsAPI["urlFindWeatherByCoordinates"].toString();
    qDebug() << "Конфигурация успешно загружена.";
    return true;
}

void WeatherApiClient::onSlotFindCity()
{
    QNetworkReply *reply = qobject_cast<QNetworkReply*>(sender());
    if (!reply) {
        qDebug() << "Invalid reply";
        return;
    }
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray responseData = reply->readAll();
        QJsonParseError error;
        QJsonDocument jsonDocument = QJsonDocument::fromJson(responseData, &error);
        if (error.error != QJsonParseError::NoError) {
            qDebug() << "Ошибка парсинга Json при поиске города: " << error.errorString();
            ApiReply response = createErroneousResponse("Ошибка парсинга Json при поиске города: " + error.errorString());
            emit sendRecivedWeatherDataFromAPI(response);
            return;
        }
        if (!jsonDocument.isArray()) {
            qDebug() << "Json не является массивом";
            ApiReply response = createErroneousResponse("Json не является массивом");
            emit sendRecivedWeatherDataFromAPI(response);
            return;
        }
        QJsonArray jsonArray = jsonDocument.array();
        if (jsonArray.isEmpty()) {
            qDebug() << "Город не найден";
            ApiReply response = createErroneousResponse("Город не найден");
            emit sendRecivedWeatherDataFromAPI(response);
            return;
        }
        QJsonObject cityData = jsonArray[0].toObject();
        QString lat = QString::number(cityData["lat"].toDouble());
        QString lon = QString::number(cityData["lon"].toDouble());
        findWeatherData(lat, lon);
    } else {
        qDebug() << "Error: " << reply->errorString();
        ApiReply response = createErroneousResponse("Error: " + reply->errorString());
        emit sendRecivedWeatherDataFromAPI(response);
        return;
    }
    reply->deleteLater();
    return;
}

void WeatherApiClient::onSlotFindWeatherData()
{

    QNetworkReply *reply = qobject_cast<QNetworkReply*>(sender());
    if (!reply) {
        qDebug() << "Invalid reply";
        return;
    }
    QJsonObject weatherJsonData;
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray responseData = reply->readAll();
        QJsonParseError error;
        QJsonDocument jsonDocument = QJsonDocument::fromJson(responseData, &error);
        if (error.error != QJsonParseError::NoError) {
            qDebug() << "Ошибка парсинга Json при поиске погоды: " << error.errorString();
            ApiReply response = createErroneousResponse("Error: " + reply->errorString());
            emit sendRecivedWeatherDataFromAPI(response);
            return;
        }
        if (!jsonDocument.isObject()) {
            qDebug() << "Json не является объектом";
            ApiReply response = createErroneousResponse("Json не является объектом");
            emit sendRecivedWeatherDataFromAPI(response);
            return;
        }
        weatherJsonData = jsonDocument.object();
        if (weatherJsonData.isEmpty()) {
            qDebug() << "Погода не найден";
            ApiReply response = createErroneousResponse("Погода не найден");
            emit sendRecivedWeatherDataFromAPI(response);
            return;
        }
        ApiReply response;
        response.data = weatherJsonData;
        emit sendRecivedWeatherDataFromAPI(response);
    } else {
        qDebug() << "Error: " << reply->errorString();
        ApiReply response = createErroneousResponse("Error: " + reply->errorString());
        emit sendRecivedWeatherDataFromAPI(response);
        return;
    }
    reply->deleteLater();
    return;
}

ApiReply WeatherApiClient::createErroneousResponse(const QString &message)
{
    ApiReply response;
    response.success = false;
    response.messageError = message;
    return response;
}

void WeatherApiClient::findWeatherData(const QString &lat, const QString &lon)
{
    QString url = QString(urlFindWeatherByCoordinates).arg(lat).arg(lon).arg(apiKey);
    qDebug() << url;
    QNetworkRequest request((QUrl(url)));
    replyWeather = manager->get(request);
    connect(replyWeather, &QNetworkReply::finished, this, &WeatherApiClient::onSlotFindWeatherData);
    return;
}

