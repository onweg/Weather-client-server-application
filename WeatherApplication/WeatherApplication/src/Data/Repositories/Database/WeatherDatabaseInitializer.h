#ifndef WEATHERDATABASEINITIALIZER_H
#define WEATHERDATABASEINITIALIZER_H

#include <QString>

#include "../../../Domain/Interfaces/Database/IWeatherDatabaseInitializer.h"

class WeatherDatabaseInitializer : public IWeatherDatabaseInitializer {
 public:
  bool initialize() override;

 private:
  const QString DB_PATH = "weather_data_request.db";
};

#endif  // WEATHERDATABASEINITIALIZER_H
