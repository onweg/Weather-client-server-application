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
    explicit WeatherUiModel(QObject* parent = nullptr);

    QString city() const;
    QString date() const;
    QString description() const;
    double lat() const;
    double lon() const;
    double temp() const;
    double feelsLike() const;
    double tempMax() const;
    double tempMin() const;
    double windSpeed() const;
    int humidity() const;
    int pressure() const;
    QString messageError() const;

    void setCity(const QString& val);
    void setDate(const QString& val);
    void setDescription(const QString& val);
    void setLat(double val);
    void setLon(double val);
    void setTemp(double val);
    void setFeelsLike(double val);
    void setTempMax(double val);
    void setTempMin(double val);
    void setWindSpeed(double val);
    void setHumidity(int val);
    void setPressure(int val);
    void setMessageError(const QString& val);

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
    QString city_;
    QString date_;
    QString description_;
    double lat_ = 0.0;
    double lon_ = 0.0;
    double temp_ = 0.0;
    double feelsLike_ = 0.0;
    double tempMax_ = 0.0;
    double tempMin_ = 0.0;
    double windSpeed_ = 0.0;
    int humidity_ = 0;
    int pressure_ = 0;
    QString messageError_;
};
#endif // WEATHERUIMODEL_H
