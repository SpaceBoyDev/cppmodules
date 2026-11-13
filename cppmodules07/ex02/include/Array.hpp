#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <cstdio>

template <typename T>
class Array
{
	private:
		T*		_elements;
		size_t	_size;
	
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &other);
		Array &operator=(const Array &other);
		
		~Array();

		T &operator[](size_t n);

		unsigned int size() const;

		void printElements();

		class OutOfBounds : public std::exception
		{
			virtual const char* what() const throw();
		};

};

# include "../Array.tpp"

#endif
