#include "../include/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() :
	AForm("Robotomy", 72, 45),
	_target("none")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
	AForm("Robotomy", 72, 45),
	_target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &copy) :
	AForm(copy),
	_target(copy._target)
{
}
RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm &copy)
{
	if (this != &copy)
	{
		AForm::operator=(copy);
		_target = copy._target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}
void RobotomyRequestForm::executeAction() const
{
	bool success = rand() % 2;
	std::cout << "*Makes drilling noises*\n" << _target
			<< (success ? " has been succesfully robotomized!" : " robotomy has failed...")
			<< std::endl;
}