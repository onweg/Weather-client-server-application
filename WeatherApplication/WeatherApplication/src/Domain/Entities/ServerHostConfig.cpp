#include "ServerHostConfig.h"

ServerHostConfig::ServerHostConfig()
    : m_ip(""), m_port("")
{
}

ServerHostConfig::ServerHostConfig(const std::string& ip, const std::string& port)
    : m_ip(ip), m_port(port)
{
}

const std::string& ServerHostConfig::getIp() const
{
    return m_ip;
}

void ServerHostConfig::setIp(const std::string& ip)
{
    m_ip = ip;
}

const std::string& ServerHostConfig::getPort() const
{
    return m_port;
}

void ServerHostConfig::setPort(const std::string& port)
{
    m_port = port;
}
