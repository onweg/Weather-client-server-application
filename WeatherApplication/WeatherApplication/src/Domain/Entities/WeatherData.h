#ifndef WEATHERDATA_H
#define WEATHERDATA_H

#include <string>
#include <cmath>

class WeatherData
{
public:
    WeatherData();
    WeatherData(double lat,
                double lon,
                const std::string& city,
                const std::string& date,
                const std::string& description,
                double temp,
                double feels_like,
                double temp_max,
                double temp_min,
                double wind_speed,
                int humidity,
                int pressure,
                const std::string& messageError);

    double getLat() const;
    void setLat(double lat);

    double getLon() const;
    void setLon(double lon);

    const std::string& getCity() const;
    void setCity(const std::string& city);

    const std::string& getDate() const;
    void setDate(const std::string& date);

    const std::string& getDescription() const;
    void setDescription(const std::string& description);

    double getTemp() const;
    void setTemp(double temp);

    double getFeelsLike() const;
    void setFeelsLike(double feels_like);

    double getTempMax() const;
    void setTempMax(double temp_max);

    double getTempMin() const;
    void setTempMin(double temp_min);

    double getWindSpeed() const;
    void setWindSpeed(double wind_speed);

    int getHumidity() const;
    void setHumidity(int humidity);

    int getPressure() const;
    void setPressure(int pressure);

    const std::string& getMessageError() const;
    void setMessageError(const std::string& messageError);

    bool operator==(const WeatherData& other) const;
    bool operator!=(const WeatherData& other) const;

private:
    double m_lat;
    double m_lon;
    std::string m_city;
    std::string m_date;
    std::string m_description;
    double m_temp;
    double m_feels_like;
    double m_temp_max;
    double m_temp_min;
    double m_wind_speed;
    int m_humidity;
    int m_pressure;
    std::string m_messageError;
};

inline bool areAlmostEqual(double a, double b, double epsilon = 1e-9) {
    return std::fabs(a - b) <= epsilon * std::max(std::fabs(a), std::fabs(b));
}

#endif // WEATHERDATA_H
