#include <iostream>
#include <vector>

#include "include/Span.hpp"

int	main(void)
{
	std::cout << "----SUBJECT MAIN----\n";
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
		std::cout << sp << std::endl;
	}
	
	std::cout << "\n----SPAN WITH 25 ELEMENTS----\n";
	{
		Span sp = Span(25);
		std::vector<int> vec;

		for (size_t i = 0; i < 25; i++)
			vec.push_back(i + 10);

		sp.addNumbers(vec.begin(), vec.end());

		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
		std::cout << sp << std::endl;
	}

	std::cout << "\n----SPAN WITH 10.000 ELEMENTS----\n";
	{
		Span sp = Span(10000);
		std::vector<int> vec;

		for (size_t i = 0; i < 10000; i++)
			vec.push_back(i + 10);

		sp.addNumbers(vec.begin(), vec.end());

		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
	}

	std::cout << "\n----SPAN WITH 50.000 ELEMENTS----\n";
	{
		Span sp = Span(50000);
		std::vector<int> vec;

		for (size_t i = 0; i < 50000; i++)
			vec.push_back(i + 10);

		sp.addNumbers(vec.begin(), vec.end());

		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
	}

	std::cout << "\n----SPAN WITH 1.000.000 ELEMENTS----\n";
	{
		Span sp = Span(1000000);
		std::vector<int> vec;

		for (size_t i = 0; i < 1000000; i++)
			vec.push_back(i + 1);

		sp.addNumbers(vec.begin(), vec.end());

		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
	}

	std::cout << "\n----ERROR FULL SPAN----\n";
	{
		try
		{
			Span sp = Span(5);
			sp.addNumber(4);
			sp.addNumber(54);
			sp.addNumber(3);
			sp.addNumber(53);
			sp.addNumber(8732);
			sp.addNumber(3);
			sp.addNumber(1);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	std::cout << "\n----ERROR FULL SPAN----\n";
	{
		try
		{
			Span sp = Span(5);
			std::vector<int> vec;

			for (size_t i = 0; i < 6; i++)
				vec.push_back(i + 10);
			sp.addNumbers(vec.begin(), vec.end());
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	std::cout << "\n----ERROR SPAN TOO SMALL----\n";
	{
		try
		{
			Span sp = Span(1);
			std::vector<int> vec;

			for (size_t i = 0; i < 1; i++)
				vec.push_back(i + 10);
			sp.addNumbers(vec.begin(), vec.end());

			std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		try
		{
			Span sp = Span(1);
			std::vector<int> vec;

			for (size_t i = 0; i < 1; i++)
				vec.push_back(i + 10);
			sp.addNumbers(vec.begin(), vec.end());

			std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	return 0;
}