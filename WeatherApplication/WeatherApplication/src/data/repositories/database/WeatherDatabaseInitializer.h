#ifndef WEATHERDATABASEINITIALIZER_H
#define WEATHERDATABASEINITIALIZER_H

#include <QSqlDatabase>

#include "../../../domain/interfaces/database/IWeatherDatabaseInitializer.h"

class WeatherDatabaseInitializer : public IWeatherDatabaseInitializer
{
  public:
	QSqlDatabase initialize() override;

  private:
	const QString DB_PATH = "weather_data_request.db";
	bool createTableIfNotExists(QSqlDatabase &db);
};

#endif // WEATHERDATABASEINITIALIZER_H
