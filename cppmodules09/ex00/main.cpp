#include <iostream>

#include "include/BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Need one argument to execute: './btc <file path>'\n";
		return (1);
	}

	std::string		fileInput = argv[1];
	BitcoinExchange	btc(fileInput);
	try
	{
		btc.startComparison();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}