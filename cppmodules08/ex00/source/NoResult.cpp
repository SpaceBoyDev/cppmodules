#include "../include/NoResult.hpp"

const char *NoResult::what() const throw()
{
	return "Value not found";
}
