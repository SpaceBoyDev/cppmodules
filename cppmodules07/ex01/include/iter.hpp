#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T>
void iter(T *arr, size_t const len, void (*f)(T &))
{	
	for (size_t i = 0; i < len; i++)
		f(arr[i]);
}

template <typename T>
void iter(const T *arr, size_t const len, void (*f)(const T &))
{	
	for (size_t i = 0; i < len; i++)
		f(arr[i]);
}

template <typename T>
void increment(T &a)
{
	++a;
}

template <typename T>
void printVar(T &a)
{
	std::cout << a << std::endl;
}

#endif