#ifndef IWEATHERDATABASEINITIALIZER_H
#define IWEATHERDATABASEINITIALIZER_H

#include "IWeatherDatabaseConnection.h"

class IWeatherDatabaseInitializer
{
  public:
	virtual ~IWeatherDatabaseInitializer() = default;
	virtual DatabaseConnectionPtr initialize() = 0;
};

using DatabaseInitializerPtr = std::shared_ptr<IWeatherDatabaseInitializer>;

#endif // IWEATHERDATABASEINITIALIZER_H
