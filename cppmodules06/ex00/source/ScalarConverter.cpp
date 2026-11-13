#include "../include/ScalarConverter.hpp"

#include <iostream>
#include <cstdlib>
#include <climits>
#include <cfloat>
#include <cmath>
#include <iomanip>

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	(void)copy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy)
{
	(void)copy;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
}

void ScalarConverter::displayType(DataType &dataType)
{
	switch (dataType)
	{
	case TYPE_CHAR:
		std::cout << "Type Char\n";
		break;
	case TYPE_DOUBLE:
		std::cout << "Type Double\n";
		break;
	case TYPE_FLOAT:
		std::cout << "Type Float\n";
		break;
	case TYPE_INT:
		std::cout << "Type Int\n";
		break;
	case TYPE_NAN:
		std::cout << "Type Nan\n";
		break;
	case TYPE_NEG_INF:
		std::cout << "Type Neg Inf\n";
		break;
	case TYPE_POS_INF:
		std::cout << "Type Pos Inf\n";
		break;
	case TYPE_UNKNOWN:
		std::cout << "Type Unknown\n";
		break;
	
	default:
		std::cout << "???";
		break;
	}
}

void ScalarConverter::convertLiteral(DataType &dataType, const std::string &literal)
{
	double d = std::strtod(literal.c_str(), NULL);

	switch (dataType)
	{
	case TYPE_CHAR:
		std::cout
		<< "char: " << "'" << literal[0] << "'"
		<< "\nint: " << static_cast<int>(literal[0])
		<< "\nfloat: " << static_cast<float>(literal[0]) << ".0f"
		<< "\ndouble: " << static_cast<double>(literal[0]) << ".0"
		<< std::endl;
		break;
	case TYPE_DOUBLE:
		printChar(d);
		std::cout
		<< "int: " << static_cast<int>(d)
		<< "\nfloat: " << static_cast<float>(d) << "f"
		<< "\ndouble: " << d
		<< std::endl;
		break;
	case TYPE_FLOAT:
		printChar(d);
		std::cout
		<< "int: " << static_cast<int>(d)
		<< "\nfloat: " << static_cast<float>(d) << "f"
		<< "\ndouble: " << d
		<< std::endl;
		break;
	case TYPE_INT:
		printChar(d);
		std::cout
		<< "int: " << static_cast<int>(d)
		<< "\nfloat: " << static_cast<float>(d) << ".0f"
		<< "\ndouble: " << static_cast<double>(d) << ".0"
		<< std::endl;
		break;
	case TYPE_NAN:
		std::cout
		<< "char: " << "impossible"
		<< "\nint: " << "impossible"
		<< "\nfloat: " << "nanf"
		<< "\ndouble: " << "nan"
		<< std::endl;
		break;
	case TYPE_NEG_INF:
		std::cout
		<< "char: " << "impossible"
		<< "\nint: " << "impossible"
		<< "\nfloat: " << "-inff"
		<< "\ndouble: " << "-inf"
		<< std::endl;
		break;
	case TYPE_POS_INF:
		std::cout
		<< "char: " << "impossible"
		<< "\nint: " << "impossible"
		<< "\nfloat: " << "+inff"
		<< "\ndouble: " << "+inf"
		<< std::endl;
		break;
	case TYPE_UNKNOWN:
		std::cout
		<< "char: " << "impossible"
		<< "\nint: " << "impossible"
		<< "\nfloat: " << "impossible"
		<< "\ndouble: " << "impossible"
		<< std::endl;
		break;
	default:
		std::cout << "???";
		break;

	}
}
void ScalarConverter::parseLiteral(DataType &dataType, const std::string &literal)
{
	bool onlyDigits = true;
	bool error = false;
	int dots = 0;

	for (int i = 0; literal[i]; i++)
	{
		if (literal[i] == '.')
			++dots;
		if (i == 0 && (literal[i] == '+' || literal[i] == '-'))
			continue ;
		if (!std::isdigit(literal[i]))
			onlyDigits = false;
		if (((dataType == TYPE_FLOAT && literal[i + 1]))
			|| (std::isalpha(literal[i]) && literal[i] != 'f'))
			error = true;
		else if (literal[i] == '.' && literal[i - 1]
			&& std::isdigit(literal[i - 1]))
			dataType = TYPE_DOUBLE;
		else if (literal[i] == 'f' && dataType == TYPE_DOUBLE)
		{
			if (literal[i + 1])
				error = true;
			dataType = TYPE_FLOAT;
		}
	}

	if (onlyDigits)
		dataType = TYPE_INT;
	if (error || dots > 1)
		dataType = TYPE_UNKNOWN;
	if (literal == "nan" || literal == "nanf")
		dataType = TYPE_NAN;
	else if (literal == "+inff" || literal == "+inf")
		dataType = TYPE_POS_INF;
	else if (literal == "-inff" || literal == "-inf")
		dataType = TYPE_NEG_INF;
	else if (literal.length() == 1 && std::isprint(literal[0])
		&& !std::isdigit(literal[0]))
		dataType = TYPE_CHAR;
}



void ScalarConverter::convert(const std::string literal)
{
	ScalarConverter converter;
	DataType dataType = TYPE_UNKNOWN;

	converter.parseLiteral(dataType, literal);
	converter.convertLiteral(dataType, literal);
}

void ScalarConverter::printChar(double d)
{
	std::cout << "char: ";
	if (std::isnan(d) || std::isinf(d) || d < CHAR_MIN || d > CHAR_MAX)
		std::cout << "impossible" << std::endl;
	else
	{
		char c = static_cast<char>(d);
		if (std::isprint(c))
			std::cout << "'" << c << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}
}
