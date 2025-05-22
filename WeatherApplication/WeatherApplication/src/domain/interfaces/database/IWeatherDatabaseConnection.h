#ifndef IWEATHERDATABASECONNECTION_H
#define IWEATHERDATABASECONNECTION_H

#include <memory>
#include <string>

class IWeatherDatabaseConnection
{
  public:
	virtual ~IWeatherDatabaseConnection() = default;
	virtual bool isOpen() const = 0;
	virtual std::string getLastError() const = 0;
};

using DatabaseConnectionPtr = std::shared_ptr<IWeatherDatabaseConnection>;

#endif // IWEATHERDATABASECONNECTION_H
