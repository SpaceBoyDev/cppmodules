#include "../include/Form.hpp"
#include "../include/Bureaucrat.hpp"

Form::Form() : 
	_name("Default"),
	_isSigned(false),
	_signGrade(1),
	_execGrade(1)
{
}
Form::Form(const std::string name, const int signGrade, const int execGrade) : 
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
Form::Form(Form &copy) : 
	_name(copy._name),
	_isSigned(copy._isSigned),
	_signGrade(copy._signGrade),
	_execGrade(copy._execGrade)
{
}
Form &Form::operator=(const Form &copy)
{
	if (this != &copy)
	{
		this->_isSigned = copy._isSigned;
	}
	return (*this);
}

Form::~Form()
{
}

std::string Form::getName() const
{
	return (this->_name);
}

bool Form::getIsSigned() const
{
	return (this->_isSigned);
}

int Form::getSignGrade() const
{
	return (this->_signGrade);
}

int Form::getExecGrade() const
{
	return (this->_execGrade);
}

void Form::beSigned(Bureaucrat *bureaucrat)
{
	if (!bureaucrat)
		return ;

	if (bureaucrat->getGrade() <= this->_signGrade)
		this->_isSigned = true;
	else
		throw Form::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
	return (os << form.getName() << " form " << (form.getIsSigned() ? "IS signed" : "IS NOT signed")
			<< ". Sign grade is " << form.getSignGrade() << ". Execution grade is " << form.getExecGrade());
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade too high for Form";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade too low for Form";
}