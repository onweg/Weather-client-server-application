#ifndef WEATHERHISTORYITEM_H
#define WEATHERHISTORYITEM_H

#include <chrono>
#include <string>

class WeatherHistoryItem
{
  public:
	WeatherHistoryItem();
	WeatherHistoryItem(int id, const std::string &username,
	                   const std::chrono::system_clock::time_point &timestamp,
	                   const std::string &city, const std::string &date);

	int getId() const;
	void setId(int id);

	const std::string &getUsername() const;
	void setUsername(const std::string &username);

	const std::chrono::system_clock::time_point &getTimestamp() const;
	void setTimestamp(const std::chrono::system_clock::time_point &timestamp);

	const std::string &getCity() const;
	void setCity(const std::string &city);

	const std::string &getDate() const;
	void setDate(const std::string &date);

  private:
	int m_id;
	std::string m_username;
	std::chrono::system_clock::time_point m_timestamp;
	std::string m_city;
	std::string m_date;
};

#endif // WEATHERHISTORYITEM_H
