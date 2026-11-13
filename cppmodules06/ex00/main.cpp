#include "include/ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	if (argc == 2)
		ScalarConverter::convert(argv[1]);
	else
		std::cout << "Input only one argument\nExample: './ex00 34'" << std::endl;
	return (0);
}