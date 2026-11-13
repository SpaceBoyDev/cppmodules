#include <iostream>
#include <iomanip>
#include <ctime>

#include "include/PmergeMe.hpp"

int	main(int argc, char **argv)
{
	try
	{
		if (argc < 2)
			throw std::logic_error("not enought parameters. Example: \"./PmergeMe 54 6 87 123 0\"");
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
		return (1);
	}

	try
	{
		std::clock_t vectorStart = std::clock();
		std::vector<int> vectorResult = PmergeMe::sortVector(argc - 1, argv + 1);
		std::clock_t vectorEnd = std::clock();

		std::clock_t dequeStart = std::clock();
		std::deque<int> dequeResult = PmergeMe::sortDeque(argc - 1, argv + 1);
		std::clock_t dequeEnd = std::clock();

		std::cout << "Before: ";
		for (int i = 1; i < argc; ++i)
			std::cout << argv[i] << (i + 1 == argc ? '\n' : ' ');

		std::cout << "After:  ";
		for (std::vector<int>::const_iterator it = vectorResult.begin(); it != vectorResult.end(); ++it)
			std::cout << *it << (it + 1 == vectorResult.end() ? '\n' : ' ');

		const double vectorTime = 1000000.0 * (vectorEnd - vectorStart) / CLOCKS_PER_SEC;
		const double dequeTime = 1000000.0 * (dequeEnd - dequeStart) / CLOCKS_PER_SEC;

		std::cout << std::fixed << std::setprecision(2);
		std::cout << std::fixed << std::setprecision(5);
		std::cout << "Time to process a range of " << vectorResult.size()
			<< " elements with std::vector : " << vectorTime << " us\n";
		std::cout << "Time to process a range of " << dequeResult.size()
			<< " elements with std::deque  : " << dequeTime << " us\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << "\n";
		return (1);
	}
	return (0);
}