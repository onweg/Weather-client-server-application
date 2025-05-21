#ifndef WEATHERHISTORYITEMDTO_H
#define WEATHERHISTORYITEMDTO_H

#include <string>
#include <chrono>

struct WeatherHistoryItemDto {
    int id;
    std::string username;
    std::chrono::system_clock::time_point timestamp;
    std::string city;
    std::string date;
};

#endif // WEATHERHISTORYITEMDTO_H
