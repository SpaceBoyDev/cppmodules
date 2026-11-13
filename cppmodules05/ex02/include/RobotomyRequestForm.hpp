#ifndef ROBOTOMY_REQUEST_FORM
# define ROBOTOMY_REQUEST_FORM

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string	_target;

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm &copy);
		RobotomyRequestForm &operator=(RobotomyRequestForm &copy);

		~RobotomyRequestForm();

		void executeAction() const;
};

#endif