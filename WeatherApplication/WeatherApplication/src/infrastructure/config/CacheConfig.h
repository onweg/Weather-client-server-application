#ifndef CACHECONFIG_H
#define CACHECONFIG_H

#include <cstddef>

class CacheConfig
{
  public:
	CacheConfig();
	CacheConfig(const size_t maxMemoryBytes);

	size_t getMaxMemoryBytes() const;
	void setMaxMemoryBytes(const size_t &newMemory);

  private:
	size_t m_maxMemoryBytes;
};

#endif // CACHECONFIG_H
