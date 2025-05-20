#ifndef SERVERHOSTCONFIG_H
#define SERVERHOSTCONFIG_H

#include <string>

class ServerHostConfig
{
private:
    std::string m_ip;
    std::string m_port;

public:
    const std::string& getIp() const;
    void setIp(const std::string& ip);

    const std::string& getPort() const;
    void setPort(const std::string& port);
};

#endif // SERVERHOSTCONFIG_H
