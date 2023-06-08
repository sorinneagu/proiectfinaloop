#include "SongException.h"

SongException::SongException(const std::string& error)
{
	this->errorMessage = error;
}

const char* SongException::what() const noexcept
{
	return errorMessage.c_str();
}
