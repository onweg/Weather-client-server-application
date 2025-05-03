#ifndef SIMPLEOPTIONAL_H
#define SIMPLEOPTIONAL_H

template<typename T>
class SimpleOptional {
public:
    SimpleOptional() : hasValue_(false) {}
    SimpleOptional(const T& value) : hasValue_(true), value_(value) {}

    bool hasValue() const { return hasValue_; }
    const T& value() const { return value_; }
    T& value() { return value_; }

private:
    bool hasValue_;
    T value_;
};

#endif // SIMPLEOPTIONAL_H
