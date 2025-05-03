#ifndef ICONFIGLOADER_H
#define ICONFIGLOADER_H

#include "../Models/AppConfig.h"
#include "../Utils/Result.h"

class IConfigLoader {
public:
    virtual ~IConfigLoader() = default;
    virtual Result<AppConfig> load() = 0;
};

#endif // ICONFIGLOADER_H
