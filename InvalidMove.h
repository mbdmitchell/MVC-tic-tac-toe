#pragma once

#include <exception>
#include <string>

class InvalidMove : public std::exception {
    std::string msg;
public:
    explicit InvalidMove(std::string_view msg);
    [[nodiscard]] const char* what() const noexcept override;
};

