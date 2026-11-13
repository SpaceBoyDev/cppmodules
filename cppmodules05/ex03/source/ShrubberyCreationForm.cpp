#include "../include/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() :
	AForm("Shrubbery", 145, 137),
	_target("none")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
	AForm("Shrubbery", 145, 137),
	_target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &copy) :
	AForm(copy),
	_target(copy._target)
{
}
ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm &copy)
{
	if (this != &copy)
	{
		AForm::operator=(copy);
		_target = copy._target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::executeAction() const
{
	std::string		fileName(_target + "_shrubbery");
	std::ofstream	file(fileName.c_str());

	file << "   oxoxoo    ooxoo									\n";
	file << " ooxoxo oo  oxoxooo                                \n";  
	file << "oooo xxoxoo ooo ooox   	  ccee88oo				\n";
	file << "oxo o oxoxo  xoxxoxo    C8O8O8Q8PoOb o8oo			\n";
	file << " oxo xooxoooo o ooo   dOB69QO8PdUOpugoO9bD			\n";
	file << "   ooo\\oo\\  /o/o	   CgggbU8OU qOp qOdoUOdcb		\n";
	file << "       \\  \\/ /		    6OuU  /p u gcoUodpP		\n";
	file << "        |   /		         \\\\//  /douUP			\n";
	file << "        |  |		           \\\\////				\n";
	file << "        | D|		            |||/\\				\n";
	file << "        |  |		            |||\\/				\n";
	file << "        |  |		            |||||				\n";
	file << " ______/____\\____	    .....//||||\\....			\n";
                                       
	file.close();

	std::cout << fileName << " has been created" << std::endl;
}
