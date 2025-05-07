#ifndef WEATHERHISTORYITEM_H
#define WEATHERHISTORYITEM_H

#include <string>
#include <chrono>

struct WeatherHistoryItem {
    int id;
    std::string username;
    std::chrono::system_clock::time_point timestamp;
    std::string city;
    std::string date;
};

#endif // WEATHERHISTORYITEM_H
