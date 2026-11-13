#ifndef SPAN_HPP
# define SPAN_HPP

#include <exception>
#include <vector>
#include <algorithm>
#include <iostream>

class Span
{
	private:
		unsigned int		_N;
		std::vector<int>	_list;

	public:
		Span();
		Span(unsigned int n);
		Span(const Span &other);
		Span &operator=(const Span &other);

		~Span();

		unsigned int		getN() const;
		std::vector<int>	getList() const;

		void	addNumber(int n);
		void	addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int		shortestSpan();
		int		longestSpan();

		class	SpanIsFull : public std::exception
		{
			virtual const char* what() const throw();
		};

		class	SpanIsTooSmall : public std::exception
		{
			virtual const char* what() const throw();
		};
		
};

std::ostream	&operator<<(std::ostream& os, const Span &span);

#endif
