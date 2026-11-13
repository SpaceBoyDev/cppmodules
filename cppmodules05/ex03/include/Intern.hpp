#ifndef INTERN_HPP
# define INTERN_HPP

#include <string>
#include "AForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(Intern &copy);
		Intern &operator=(Intern &copy);

		~Intern();

		AForm *makeForm(std::string formType, std::string formTarget);
};

#endif