#ifndef IWEATHERDATABASEINITIALIZER_H
#define IWEATHERDATABASEINITIALIZER_H

#include <QSqlDatabase>

class IWeatherDatabaseInitializer
{
  public:
 virtual ~IWeatherDatabaseInitializer() = default;
 virtual QSqlDatabase initialize() = 0;
};

#endif // IWEATHERDATABASEINITIALIZER_H
