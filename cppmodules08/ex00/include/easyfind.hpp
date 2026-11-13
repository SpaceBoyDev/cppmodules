#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include "NoResult.hpp"
#include <algorithm>

template <typename T>
typename T::iterator	easyfind(T &container, int value)
{
	typename T::iterator pos;
	pos = std::find(container.begin(), container.end(), value);
	if (pos == container.end())
		throw NoResult();
	return (pos);
}


#endif