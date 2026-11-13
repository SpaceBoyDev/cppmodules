#ifndef PRESIDENTIAL_PARDON_FORM
# define PRESIDENTIAL_PARDON_FORM

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string	_target;

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm &copy);
		PresidentialPardonForm &operator=(PresidentialPardonForm &copy);

		~PresidentialPardonForm();

		void executeAction() const;
};

#endif