#include "../include/Bureaucrat.hpp"

#include "../include/AForm.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(1)
{
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	setGrade(grade);
}

Bureaucrat::Bureaucrat(Bureaucrat &copy)
{
	this->_name = copy._name;
	this->_grade = copy._grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy)
{
	if (this != &copy)
	{
		this->_name = copy._name;
		this->_grade = copy._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
}

std::string Bureaucrat::getName() const
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void Bureaucrat::setGrade(int grade)
{
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	_grade = grade;
}

void Bureaucrat::incrementGrade()
{
	setGrade(_grade - 1);
}

void Bureaucrat::decrementGrade()
{
	setGrade(_grade + 1);
}

void Bureaucrat::checkExceptions()
{
	if (_grade > 150)
		throw GradeTooLowException();
	else if (_grade < 1)
		throw GradeTooHighException();
}

void Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << _name << " couldn't sign " << form.getName() << " because: " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form) const
{
	try
	{
		form.execute(*this);
	}
	catch(const std::exception& e)
	{
		std::cout << "Failed to execute " << form.getName() << " because " << e.what() << std::endl;
	}
	
}


std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
	return (os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade());
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}