#include "../include/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() :
	AForm("Presidential", 25, 5),
	_target("none")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
	AForm("Presidential", 25, 5),
	_target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &copy) :
	AForm(copy),
	_target(copy._target)
{
}
PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm &copy)
{
	if (this != &copy)
	{
		AForm::operator=(copy);
		_target = copy._target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void PresidentialPardonForm::executeAction() const
{
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
