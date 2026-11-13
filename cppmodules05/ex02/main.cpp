#include "include/Bureaucrat.hpp"
#include "include/ShrubberyCreationForm.hpp"
#include "include/RobotomyRequestForm.hpp"
#include "include/PresidentialPardonForm.hpp"

int main(void)
{
	ShrubberyCreationForm	shrubbery("Cow");
	RobotomyRequestForm		robotomy("ChibiRobo");
	PresidentialPardonForm	presidential("presi");
	Bureaucrat				admin("admin", 1);
	Bureaucrat				buroDefault("Default", 150);
	srand(time(NULL));

	std::cout << std::endl;
	std::cout << "Created:" << std::endl;
	std::cout << admin << std::endl;
	std::cout << std::endl;
	std::cout << "Trying to execute unsigned form..." << std::endl;

	try
	{
		shrubbery.execute(admin);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Couldn't execute because " << e.what() << '\n';
	}
	admin.executeForm(robotomy);
	buroDefault.executeForm(robotomy);
	std::cout << std::endl;
	std::cout << "Signing..." << std::endl;
	admin.signForm(shrubbery);
	admin.signForm(robotomy);
	admin.signForm(presidential);
	std::cout << std::endl;
	std::cout << "Executing forms..." << std::endl;
	admin.executeForm(robotomy);
	buroDefault.executeForm(robotomy);
	try
	{
		shrubbery.execute(admin);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Couldn't execute because " << e.what() << '\n';
	}
	std::cout << std::endl;
	try
	{
		robotomy.execute(admin);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Couldn't execute because " << e.what() << '\n';
	}
	std::cout << std::endl;
	try
	{
		presidential.execute(admin);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Couldn't execute because " << e.what() << '\n';
	}
	std::cout << std::endl;
	std::cout << "Trying to execute without permissions..." << std::endl;
	try
	{
		presidential.execute(buroDefault);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Couldn't execute because " << e.what() << '\n';
	}
	std::cout << std::endl;

}
