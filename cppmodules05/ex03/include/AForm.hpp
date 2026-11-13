#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <math.h>

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_signGrade;
		const int			_execGrade;

		virtual void	executeAction() const = 0;

	public:
		AForm();
		AForm(const std::string name, const int signGrade, const int execGrade);
		AForm(AForm &copy);
		AForm &operator=(const AForm &copy);

		virtual ~AForm();

		std::string	getName() const;
		bool		getIsSigned() const;
		int			getSignGrade() const;
		int			getExecGrade() const;

		void		beSigned(Bureaucrat *bureaucrat);
		void		execute(Bureaucrat const &executor) const;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class FormNotSigned : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream	&operator<<(std::ostream& os, const AForm &form);

#endif