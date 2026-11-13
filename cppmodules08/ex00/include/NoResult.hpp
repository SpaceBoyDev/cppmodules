#ifndef NORESULT_HPP
# define NORESULT_HPP

#include <exception>

class NoResult : public std::exception
{
	virtual const char* what() const throw();
};

#endif