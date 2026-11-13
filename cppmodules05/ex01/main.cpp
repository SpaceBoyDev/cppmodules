#include "include/Bureaucrat.hpp"
#include "include/Form.hpp"

int main(void)
{
	std::cout<< std::endl;
	try
	{
		std::cout << "----------Creating bureaucrats and form----------" << std::endl;
		Bureaucrat	buro("buro", 1);
		Bureaucrat	buroLow("buroLow", 150);
		Form		payment("Payment", 2, 2);
		Form		paymentWrong("Payment Wrong", 2, 2);
		std::cout << std::endl;
		std::cout << "---------Presenting bureaucrats and form---------" << std::endl;
		std::cout << buro << std::endl;
		std::cout << buroLow << std::endl;
		std::cout << payment << std::endl;
		std::cout << paymentWrong << std::endl;
		std::cout << std::endl;
		try
		{
			std::cout << "---------Signing with permissions---------" << std::endl;
			buro.signForm(payment);
		}
		catch (std::exception& e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
		std::cout << payment << std::endl;
		std::cout << std::endl;
		try
		{
			std::cout << "--------Signing without permissions-------" << std::endl;
			buroLow.signForm(paymentWrong);
			buroLow.signForm(payment);
		}
		catch (std::exception& e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
		std::cout << paymentWrong << std::endl;
		std::cout << payment << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

		std::cout << std::endl;
		std::cout << "-----Creating wrong form (signGrade too low)-----" << std::endl;

	try
	{
		Form		wrongSign("wrongSign", 151, 2);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout<< std::endl;
	std::cout << "-----Creating wrong form (exeGrade too high)-----" << std::endl;

	try
	{
		Form		wrongExe("wrongExe", 1, 0);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	std::cout<< std::endl;
}
