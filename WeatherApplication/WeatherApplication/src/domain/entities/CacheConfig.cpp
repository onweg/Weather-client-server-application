#include "CacheConfig.h"

CacheConfig::CacheConfig()
{

}

CacheConfig::CacheConfig(const size_t maxMemoryBytes)
    :m_maxMemoryBytes(maxMemoryBytes)
{

}

size_t CacheConfig::getMaxMemoryBytes() const
{
    return m_maxMemoryBytes;
}

void CacheConfig::setMaxMemoryBytes(const size_t &newMemory)
{
    m_maxMemoryBytes = newMemory;
}
