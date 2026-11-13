#include "../include/AForm.hpp"

#include "../include/Bureaucrat.hpp"

AForm::AForm() : 
	_name("Default"),
	_isSigned(false),
	_signGrade(1),
	_execGrade(1)
{
}
AForm::AForm(const std::string name, const int signGrade, const int execGrade) : 
	_name(name),
	_isSigned(false),
	_signGrade(signGrade),
	_execGrade(execGrade)
{
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
	else if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
}
AForm::AForm(AForm &copy) : 
	_name(copy._name),
	_isSigned(copy._isSigned),
	_signGrade(copy._signGrade),
	_execGrade(copy._execGrade)
{
}
AForm &AForm::operator=(const AForm &copy)
{
	if (this != &copy)
	{
		this->_isSigned = copy._isSigned;
	}
	return (*this);
}

AForm::~AForm()
{
}

std::string AForm::getName() const
{
	return (this->_name);
}

bool AForm::getIsSigned() const
{
	return (this->_isSigned);
}

int AForm::getSignGrade() const
{
	return (this->_signGrade);
}

int AForm::getExecGrade() const
{
	return (this->_execGrade);
}

void AForm::beSigned(Bureaucrat *bureaucrat)
{
	if (!bureaucrat)
		return ;

	if (bureaucrat->getGrade() <= this->_signGrade)
		this->_isSigned = true;
	else
		throw AForm::GradeTooLowException();
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (!this->_isSigned)
		throw FormNotSigned();
	if (executor.getGrade() > this->_execGrade)
		throw GradeTooLowException();
	executeAction();
}

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
	return (os << form.getName() << " form " << (form.getIsSigned() ? "IS signed" : "IS NOT signed")
			<< ". Sign grade is " << form.getSignGrade() << ". Execution grade is " << form.getExecGrade());
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high for Form";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low for Form";
}

const char* AForm::FormNotSigned::what() const throw()
{
	return "The Form is NOT signed";
}