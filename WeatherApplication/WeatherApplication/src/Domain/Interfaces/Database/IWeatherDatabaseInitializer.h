#ifndef IWEATHERDATABASEINITIALIZER_H
#define IWEATHERDATABASEINITIALIZER_H

class IWeatherDatabaseInitializer {
public:
    virtual ~IWeatherDatabaseInitializer() = default;
    // принимаем ничего, возврааем примитив на db
    virtual bool initialize() = 0;
};

#endif // IWEATHERDATABASEINITIALIZER_H
