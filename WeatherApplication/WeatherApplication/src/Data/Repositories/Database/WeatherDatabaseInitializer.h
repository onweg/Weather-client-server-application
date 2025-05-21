#ifndef WEATHERDATABASEINITIALIZER_H
#define WEATHERDATABASEINITIALIZER_H

#include "../../../Domain/Interfaces/Database/IWeatherDatabaseInitializer.h"
#include <QString>
#include <memory>

class WeatherDatabaseInitializer : public IWeatherDatabaseInitializer {
public:
    WeatherDatabaseInitializer();
    ~WeatherDatabaseInitializer();

    DatabaseConnectionPtr initialize() override;

private:
    const QString DB_PATH = "weather_data_request.db";

    bool connectToDatabase();
    bool createTableIfNotExists();

    class Impl;
    std::unique_ptr<Impl> pimpl_;
};

#endif // WEATHERDATABASEINITIALIZER_H
