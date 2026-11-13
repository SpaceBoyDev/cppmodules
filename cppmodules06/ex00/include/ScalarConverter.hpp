#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

#include <string>
#include <iostream>
#include "DataTypes.hpp"

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &copy);
		ScalarConverter &operator=(const ScalarConverter &copy);

		~ScalarConverter();

		void	displayType(DataType &dataType);
		void	convertLiteral(DataType &dataType, const std::string &literal);
		void	parseLiteral(DataType &dataType, const std::string &literal);

		void	printChar(double d);

	public:
		static void convert(const std::string literal);
};

#endif