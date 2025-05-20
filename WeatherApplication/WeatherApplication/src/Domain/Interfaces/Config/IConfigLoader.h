#ifndef ICONFIGLOADER_H
#define ICONFIGLOADER_H

#include "../../Entities/AppConfig.h"
#include "../../Utils/Result.h"

class IConfigLoader {
public:
    virtual ~IConfigLoader() = default;
    // принимаем ничего возвращаем entiry
    virtual Result<AppConfig> load() = 0;
};

#endif // ICONFIGLOADER_H
