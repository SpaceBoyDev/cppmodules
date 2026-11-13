#include "include/iter.hpp"

int	main(void)
{
	int		intArray[] = {1, 2, 3, 4, 5};
	double	doubleArray[] = {5.1, 2.982, 1233.4, 321.4, 6.554532};
	char	charArray[] = {'a', 'b', 'c', 'd', 'e'};

	size_t	len = 5;
	
	std::cout << "---------" << std::endl;
	std::cout << "INT ARRAY" << std::endl;
	std::cout << "---------" << std::endl;
	std::cout << "Print Var: " << std::endl;
	iter(intArray, len, printVar);
	std::cout << "Increment Var" << std::endl;
	iter(intArray, len, increment);
	std::cout << "Print Var: " << std::endl;
	iter(intArray, len, printVar);

	
	std::cout << std::endl << "------------" << std::endl;
	std::cout << "DOUBLE ARRAY" << std::endl;
	std::cout << "------------" << std::endl;
	std::cout << "Print Var: " << std::endl;
	iter(doubleArray, len, printVar);
	std::cout << "Increment Var" << std::endl;
	iter(doubleArray, len, increment);
	std::cout << "Print Var: " << std::endl;
	iter(doubleArray, len, printVar);
	
	std::cout << std::endl << "----------" << std::endl;
	std::cout << "CHAR ARRAY" << std::endl;
	std::cout << "----------" << std::endl;
	std::cout << "Print Var: " << std::endl;
	iter(charArray, len, printVar);
	std::cout << "Increment Var" << std::endl;
	iter(charArray, len, increment);
	std::cout << "Print Var: " << std::endl;
	iter(charArray, len, printVar);

	return (0);
}