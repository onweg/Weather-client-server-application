#ifndef WEATHERDATABASEINITIALIZER_H
#define WEATHERDATABASEINITIALIZER_H

#include "../../../Domain/Interfaces/Database/IWeatherDatabaseInitializer.h"
#include <QString>

class WeatherDatabaseInitializer : public IWeatherDatabaseInitializer {
public:
    bool initialize() override;
private:
    const QString DB_PATH = "weather_data_request.db";

    bool connectToDatabase();
    bool createTableIfNotExists();
};

#endif // WEATHERDATABASEINITIALIZER_H
