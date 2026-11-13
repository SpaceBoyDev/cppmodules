#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <list>

#include "include/easyfind.hpp"

int	main(void)
{
	std::cout << "----VECTOR----\n";
	{
		std::vector<int> vectorInt;
		int n = 18;
		std::cout << "Trying to find value: " << n << "\n";
		for (size_t i = 0; i < 10; i++)
		{
			vectorInt.push_back(i + 5 * i);
			std::cout << vectorInt[i] << ", ";
		}
		std::cout << "\n";
		std::vector<int>::iterator it = easyfind(vectorInt, n);
		std::cout << "Position (counting 0): " << std::distance(vectorInt.begin(), it);
		std::cout << "\nEasyfind: " << *it << "\n";
	}

	std::cout << "\n----DEQUE----\n";
	{
		std::deque<int> dequeInt;
		int n = 23;
		std::cout << "Trying to find value: " << n << "\n";

		for (size_t i = 0; i < 25; i++)
		{
			dequeInt.push_back(i);
			std::cout << dequeInt[i] << ", ";
		}

		std::cout << "\n";
		std::deque<int>::iterator it = easyfind(dequeInt, n);
		std::cout << "Position (counting 0): " << std::distance(dequeInt.begin(), it);
		std::cout << "\nEasyfind: " << *it << "\n";
		
	}

	std::cout << "\n----LIST----\n";
	{
		std::list<int> listInt;
		int n = 14;
		std::cout << "Trying to find value: " << n << "\n";

		for (size_t i = 0; i < 25; i++)
		{
			listInt.push_back(i);
			std::cout << i << ", ";
		}

		std::cout << "\n";
		std::list<int>::iterator it = easyfind(listInt, n);
		std::cout << "Position (counting 0): " << std::distance(listInt.begin(), it);
		std::cout << "\nEasyfind: " << *it << "\n";
	}


	std::cout << "\n----ERROR VECTOR----\n";
	{
		std::vector<int> vectorInt;
		int n = 1837182;
		std::cout << "Trying to find value: " << n << "\n";

		for (size_t i = 0; i < 10; i++)
		{
			vectorInt.push_back(i + 5 * i);
			std::cout << vectorInt[i] << ", ";
		}
		try
		{
			std::cout << "\n";
			std::vector<int>::iterator it = easyfind(vectorInt, n);
			std::cout << "Position (counting 0): " << std::distance(vectorInt.begin(), it);
			std::cout << "\nEasyfind: " << *it << "\n";
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error: "<< e.what() << '\n';
		}
		
	}

	std::cout << "\n----ERROR DEQUE----\n";
	{
		std::deque<int> dequeInt;
		int n = 4712023;
		std::cout << "Trying to find value: " << n << "\n";

		for (size_t i = 0; i < 25; i++)
		{
			dequeInt.push_back(i);
			std::cout << dequeInt[i] << ", ";
		}

		try
		{
			std::cout << "\n";
			std::deque<int>::iterator it = easyfind(dequeInt, n);
			std::cout << "Position (counting 0): " << std::distance(dequeInt.begin(), it);
			std::cout << "\nEasyfind: " << *it << "\n";	
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error: "<< e.what() << '\n';
		}
	}

	std::cout << "\n----ERROR LIST----\n";
	{
		std::list<int> listInt;
		int n = 25;
		std::cout << "Trying to find value: " << n << "\n";

		for (size_t i = 0; i < 25; i++)
		{
			listInt.push_back(i);
			std::cout << i << ", ";
		}

		try
		{
			std::cout << "\n";
			std::list<int>::iterator it = easyfind(listInt, n);
			std::cout << "Position (counting 0): " << std::distance(listInt.begin(), it);
			std::cout << "\nEasyfind: " << *it << "\n";
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error: "<< e.what() << '\n';
		}
	}
	
	return (0);
}