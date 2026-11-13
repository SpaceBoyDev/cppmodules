#include "include/Bureaucrat.hpp"

int	main(void)
{
	try
	{
		std::cout << "---------Creating valid object---------" << std::endl;
		Bureaucrat	buro("buro", 1);

		std::cout << buro << std::endl;
		try
		{
			std::cout << "Substract 1: ";
			buro.decrementGrade();
			std::cout << buro << std::endl;
			std::cout << "Add 1: ";
			buro.incrementGrade();
			std::cout << buro << std::endl;
			std::cout << "Add 1: ";
			buro.incrementGrade();
			std::cout << buro << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		std::cout << "---------Creating valid object---------" << std::endl;
		Bureaucrat	donburo("Don Buro", 148);

		std::cout << donburo << std::endl;
		try
		{
			std::cout << "Add 1: ";
			donburo.decrementGrade();
			std::cout << donburo << std::endl;
			std::cout << "Add 1: ";
			donburo.decrementGrade();
			std::cout << donburo << std::endl;
			std::cout << "Add 1: ";
			donburo.decrementGrade();
			std::cout << donburo << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	
	try
	{
		std::cout << "---Creating invalid object (too high)--" << std::endl;
		Bureaucrat	Addison("Addison", 0);

		std::cout << Addison << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	
	std::cout<< std::endl;
	
	try
	{
		std::cout << "---Creating invalid object (too low)---" << std::endl;
		Bureaucrat	Addison("Addison", 200);

		std::cout << Addison << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	std::cout<< std::endl;
}