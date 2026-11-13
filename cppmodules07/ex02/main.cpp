#include <iostream>

#include "include/Array.hpp"

int	main(void)
{
	Array<int> empty;

	std::cout << "---EMPTY---" << std::endl; 
	empty.printElements();
	std::cout << "Array empty has " << empty.size() << " elements" << std::endl;
	
	Array<int> five(5);
	std::cout << "\n---FIVE---" << std::endl;
	five.printElements();
	std::cout << "Array five has " << five.size() << " elements" << std::endl;
	std::cout << "Filling five array...\n";
	for (size_t i = 0; i < five.size(); i++)
		five[i] = i;
	five.printElements();

	Array<int> copyFive(five);
	Array<int> assignFive;

	assignFive = five;

	std::cout << "\n---COPYFIVE---" << std::endl; 
	copyFive.printElements();
	std::cout << "Array copyFive has " << copyFive.size() << " elements" << std::endl;

	std::cout << "\n---ASSIGNFIVE---" << std::endl; 
	assignFive.printElements();
	std::cout << "Array assignFive has " << assignFive.size() << " elements" << std::endl;

	std::cout << "\n---MODIFY COPYFIVE---" << std::endl;
	for (size_t i = 0; i < copyFive.size(); i++)
		copyFive[i] *= 32;
	copyFive.printElements();

	std::cout << "\n---MODIFY ASSIGNFIVE---" << std::endl;
	for (size_t i = 0; i < assignFive.size(); i++)
		assignFive[i] *= 128;
	assignFive.printElements();

	std::cout << "\n---SEE UNMODIFIED ORIGINAL FIVE ARRAY---" << std::endl; 
	five.printElements();

	try
	{
		std::cout << "Accessing out of bounds at five[8]: " << std::endl;
		std::cout << five[8] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "Accessing out of bounds at five[-2]: " << std::endl;
		std::cout << five[-2] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return (0);
}