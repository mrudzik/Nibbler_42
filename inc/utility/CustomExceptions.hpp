

#ifndef CUSTOM_EXCEPTIONS_HPP
#define CUSTOM_EXCEPTIONS_HPP

#include <string>
#include <stdexcept>

class CustomException : public std::logic_error
{
public:
	CustomException(std::string str)
		: logic_error("\033[21;31mError:\033[0m " + str)
	{ }
};


#endif