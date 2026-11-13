#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <exception>

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat &copy);
		Bureaucrat &operator=(const Bureaucrat &copy);
		~Bureaucrat();

		std::string	getName() const;
		int			getGrade() const;

		void		setGrade(int grade);
		void		incrementGrade();
		void		decrementGrade();

		void		checkExceptions();

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
	private:
		std::string	_name;
		int			_grade;
};

std::ostream	&operator<<(std::ostream& os, const Bureaucrat &bureaucrat);


#endif