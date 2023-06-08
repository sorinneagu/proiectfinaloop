#pragma once

#include <exception>
#include <string>

class SongException : public std::exception
{
private:
    std::string errorMessage;

public:
    SongException(const std::string& error);

    const char* what() const noexcept override;
};
