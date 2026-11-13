#include "../include/Span.hpp"

#include <algorithm>
#include <limits>

Span::Span() : _N(0)
{
}

Span::Span(unsigned int n) : _N(n)
{
}

Span::Span(const Span &other) : _N(other._N), _list(other._list)
{
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_N = other._N;
		_list = other._list;
	}
	return (*this);
}

Span::~Span()
{
}

unsigned int Span::getN() const
{
	return (_N);
}

std::vector<int> Span::getList() const
{
	return (_list);
}

void Span::addNumber(int n)
{
	if (_list.size() >= _N)
		throw SpanIsFull();
	_list.push_back(n);
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if ((static_cast<unsigned int>(std::distance(begin, end)) + static_cast<unsigned int>(_list.size())) > _N)
		throw SpanIsFull();
	
	std::copy(begin, end, std::back_inserter(_list));
	
}

int Span::shortestSpan()
{
	if (_N < 2)
		throw SpanIsTooSmall();
	
	std::vector<int> tmp = _list;
	std::sort(tmp.begin(), tmp.end());

	int shortest = std::numeric_limits<int>::max();
	for (size_t i = 0; i < tmp.size(); i++)
	{
		shortest = std::min(shortest, tmp[i] - tmp[i - 1]);
	}
	return (shortest);
}

int Span::longestSpan()
{
	if (_N < 2)
		throw SpanIsTooSmall();

	return (*std::max_element(_list.begin(), _list.end()) -
		*std::min_element(_list.begin(), _list.end()));
}

const char *Span::SpanIsFull::what() const throw()
{
	return "Span is full";
}

const char *Span::SpanIsTooSmall::what() const throw()
{
	return "Span doesn't have enough elements";
}

std::ostream &operator<<(std::ostream &os, const Span &span)
{
	std::vector<int> list = const_cast<Span &>(span).getList();

	os << "Span(_N=" << span.getN() << ", _list=[";
	for (std::vector<int>::const_iterator it = list.begin(); it != list.end(); ++it)
	{
		if (it != list.begin())
			os << ", ";
		os << *it;
	}
	os << "])";
	return (os);
}
