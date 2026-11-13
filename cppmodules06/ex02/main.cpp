#include <iostream>
#include "include/utils.hpp"
#include "include/Base.hpp"

int	main(void)
{
	srand(time(NULL));

	for (int i = 0; i < 4; i++)
	{
		Base *rand = generate();
		std::cout << "* Identify: ";
		identify(rand);
		std::cout << "& Identify: ";
		identify(*rand);
		delete rand;
	}

	return (0);
}