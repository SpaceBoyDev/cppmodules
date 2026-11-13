#include "../include/utils.hpp"

Base *generate(void)
{
	int		random = rand() % 3;

	std::cout << "Random Class: ";
	switch (random)
	{
		case 0:
			std::cout << "A" << std::endl;
			return (new A);
		case 1:
			std::cout << "B" << std::endl;
			return (new B);
		case 2:
			std::cout << "C" << std::endl;
			return (new C);
		default:
			return NULL;
	}
}
void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base &p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    }
    catch (std::exception &e) {}

	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
	}
	catch (std::exception &e) {}

	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	}
	catch (std::exception &e) {}

}
