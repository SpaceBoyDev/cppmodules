#include <iostream>

#include "include/RPN.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "How to execute: './RPN \"1 2 * 2 / 2 * 2 4 - +\"'\n";
		return (1);
	}

	RPN	polish(argv[1]);
	try
	{
		std::cout << polish.solve() << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}