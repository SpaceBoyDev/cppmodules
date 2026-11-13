#include "../include/Intern.hpp"

#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

Intern::Intern()
{
}

Intern::Intern(Intern &copy)
{
	(void)copy;
}

Intern &Intern::operator=(Intern &copy)
{
	(void)copy;

	return (*this);
}

Intern::~Intern()
{
}

AForm *Intern::makeForm(std::string formType, std::string formTarget)
{
	std::string forms[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	for (size_t i = 0; i < 3; i++)
	{
		if (formType == forms[i])
		{
			std::cout << "Intern creates " << forms[i] << " form."<< std::endl;
			switch (i)
			{
			case 0:
				return (new ShrubberyCreationForm(formTarget));
				break;
			case 1:
				return (new RobotomyRequestForm(formTarget));
				break;
			case 2:
				return (new PresidentialPardonForm(formTarget));
				break;
			default:
				break;
			}
		}
	}
	std::cout << "Provided form type does not exist" << std::endl;
	return (NULL);
}
