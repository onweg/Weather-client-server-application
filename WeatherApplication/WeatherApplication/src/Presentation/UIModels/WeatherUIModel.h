#ifndef WEATHERUIMODEL_H
#define WEATHERUIMODEL_H

#include <QObject>

class WeatherUiModel : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString city READ city WRITE setCity NOTIFY cityChanged)
    Q_PROPERTY(QString date READ date WRITE setDate NOTIFY dateChanged)
    Q_PROPERTY(QString description READ description WRITE setDescription NOTIFY descriptionChanged)
    Q_PROPERTY(double lat READ lat WRITE setLat NOTIFY latChanged)
    Q_PROPERTY(double lon READ lon WRITE setLon NOTIFY lonChanged)
    Q_PROPERTY(double temp READ temp WRITE setTemp NOTIFY tempChanged)
    Q_PROPERTY(double feelsLike READ feelsLike WRITE setFeelsLike NOTIFY feelsLikeChanged)
    Q_PROPERTY(double tempMax READ tempMax WRITE setTempMax NOTIFY tempMaxChanged)
    Q_PROPERTY(double tempMin READ tempMin WRITE setTempMin NOTIFY tempMinChanged)
    Q_PROPERTY(double windSpeed READ windSpeed WRITE setWindSpeed NOTIFY windSpeedChanged)
    Q_PROPERTY(int humidity READ humidity WRITE setHumidity NOTIFY humidityChanged)
    Q_PROPERTY(int pressure READ pressure WRITE setPressure NOTIFY pressureChanged)
    Q_PROPERTY(QString messageError READ messageError WRITE setMessageError NOTIFY messageErrorChanged)

public:
    explicit WeatherUiModel(QObject* parent = nullptr) : QObject(parent) {}

    // Getters
    QString city() const { return m_city; }
    QString date() const { return m_date; }
    QString description() const { return m_description; }
    double lat() const { return m_lat; }
    double lon() const { return m_lon; }
    double temp() const { return m_temp; }
    double feelsLike() const { return m_feelsLike; }
    double tempMax() const { return m_tempMax; }
    double tempMin() const { return m_tempMin; }
    double windSpeed() const { return m_windSpeed; }
    int humidity() const { return m_humidity; }
    int pressure() const { return m_pressure; }
    QString messageError() const { return m_messageError; }

    // Setters
    void setCity(const QString& val) { if (m_city != val) { m_city = val; emit cityChanged(); }}
    void setDate(const QString& val) { if (m_date != val) { m_date = val; emit dateChanged(); }}
    void setDescription(const QString& val) { if (m_description != val) { m_description = val; emit descriptionChanged(); }}
    void setLat(double val) { if (!qFuzzyCompare(m_lat, val)) { m_lat = val; emit latChanged(); }}
    void setLon(double val) { if (!qFuzzyCompare(m_lon, val)) { m_lon = val; emit lonChanged(); }}
    void setTemp(double val) { if (!qFuzzyCompare(m_temp, val)) { m_temp = val; emit tempChanged(); }}
    void setFeelsLike(double val) { if (!qFuzzyCompare(m_feelsLike, val)) { m_feelsLike = val; emit feelsLikeChanged(); }}
    void setTempMax(double val) { if (!qFuzzyCompare(m_tempMax, val)) { m_tempMax = val; emit tempMaxChanged(); }}
    void setTempMin(double val) { if (!qFuzzyCompare(m_tempMin, val)) { m_tempMin = val; emit tempMinChanged(); }}
    void setWindSpeed(double val) { if (!qFuzzyCompare(m_windSpeed, val)) { m_windSpeed = val; emit windSpeedChanged(); }}
    void setHumidity(int val) { if (m_humidity != val) { m_humidity = val; emit humidityChanged(); }}
    void setPressure(int val) { if (m_pressure != val) { m_pressure = val; emit pressureChanged(); }}
    void setMessageError(const QString& val) { if (m_messageError != val) { m_messageError = val; emit messageErrorChanged(); }}

signals:
    void cityChanged();
    void dateChanged();
    void descriptionChanged();
    void latChanged();
    void lonChanged();
    void tempChanged();
    void feelsLikeChanged();
    void tempMaxChanged();
    void tempMinChanged();
    void windSpeedChanged();
    void humidityChanged();
    void pressureChanged();
    void messageErrorChanged();

private:
    QString m_city;
    QString m_date;
    QString m_description;
    double m_lat = 0.0;
    double m_lon = 0.0;
    double m_temp = 0.0;
    double m_feelsLike = 0.0;
    double m_tempMax = 0.0;
    double m_tempMin = 0.0;
    double m_windSpeed = 0.0;
    int m_humidity = 0;
    int m_pressure = 0;
    QString m_messageError;
};
#endif // WEATHERUIMODEL_H
