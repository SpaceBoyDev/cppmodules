#ifndef SHRUBBERY_CREATION_FORM
# define SHRUBBERY_CREATION_FORM

#include "AForm.hpp"

#include <fstream>

class ShrubberyCreationForm : public AForm
{
	private:
		std::string	_target;

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm &copy);
		ShrubberyCreationForm &operator=(ShrubberyCreationForm &copy);

		~ShrubberyCreationForm();

		void executeAction() const;
};

#endif