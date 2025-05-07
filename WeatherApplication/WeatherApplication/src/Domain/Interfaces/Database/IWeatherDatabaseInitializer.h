#ifndef IWEATHERDATABASEINITIALIZER_H
#define IWEATHERDATABASEINITIALIZER_H

class IWeatherDatabaseInitializer {
public:
    virtual ~IWeatherDatabaseInitializer() = default;
    virtual bool initialize() = 0;
};

#endif // IWEATHERDATABASEINITIALIZER_H
