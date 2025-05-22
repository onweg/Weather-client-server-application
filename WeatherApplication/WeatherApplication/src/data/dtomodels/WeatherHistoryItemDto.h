#ifndef WEATHERHISTORYITEMDTO_H
#define WEATHERHISTORYITEMDTO_H

#include <chrono>
#include <string>

struct WeatherHistoryItemDto
{
	int id;
	std::string username;
	std::chrono::system_clock::time_point timestamp;
	std::string city;
	std::string date;
};

#endif // WEATHERHISTORYITEMDTO_H
