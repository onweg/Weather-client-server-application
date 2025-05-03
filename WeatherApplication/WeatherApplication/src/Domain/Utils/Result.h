#ifndef RESULT_H
#define RESULT_H

#include <string>
#include "SimpleOptional.h"

template<typename T>
class Result {
public:
    Result() : success_(false), value_(SimpleOptional<T>()), errorMessage_("Нет данных в value") {}
    static Result<T> success(const T& value) {
        return Result<T>(value);
    }

    static Result<T> failure(const std::string& errorMessage) {
        return Result<T>(errorMessage);
    }

    bool isSuccess() const {
        return success_;
    }

    const T& value() const {
        return value_.value();
    }

    const std::string &errorMessage() const {
        return errorMessage_;
    }

private:
    bool success_;
    SimpleOptional<T> value_;
    std::string errorMessage_;

    Result(const T& value) : success_(true), value_(value), errorMessage_("") {}
    Result(const std::string& error) : success_(false), value_(), errorMessage_(error) {}
};

#endif // RESULT_H
