#include "../include/RPN.hpp"

#include <sstream>
#include <climits>

bool RPN::isOperator(char c)
{
	return (c == ADD || c == SUBSTRACT || c == MULTIPLY || c == DIVIDE);
}

RPN::RPN(std::string input) : _input(input)
{
}

RPN::RPN(const RPN &other) : _input(other._input)
{
}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
	{
		_input = other._input;
	}
	return (*this);
}

RPN::~RPN()
{
}

long RPN::solve()
{
	std::stringstream	line(_input);
	std::string			token;

	while (line >> token)
	{
		if (token.size() != 1)
			throw InvalidToken();
		if (std::isdigit(token[0]))
			_op.push(token[0] - '0');
		else if (isOperator(token[0]))
		{
			evaluateOp(token[0]);
			// std::cout << "Por ahora: " << _op.top() << "\n";
		}
	}

	if (_op.size() != 1)
		throw InvalidSyntax();
	else if (_op.top() >= INT_MAX || _op.top() <= INT_MIN)
		throw OutOfBounds();
		
	return (_op.top());
}

void RPN::evaluateOp(char op)
{
	if (_op.size() < 2)
		throw InvalidSyntax();

	long		second = _op.top();
	_op.pop();
	long		first = _op.top();
	_op.pop();

	switch (op)
	{
		case ADD:
			_op.push(first + second);
			break;
		case SUBSTRACT:
			_op.push(first - second);
			break;
		case MULTIPLY:
			_op.push(first * second);
			break;
		case DIVIDE:
			if (second == 0)
				throw DivideByZero();
			_op.push(first / second);
			break;
	}
}

const char *RPN::InvalidSyntax::what() const throw()
{
	return "Error: invalid syntax";
}

const char *RPN::InvalidToken::what() const throw()
{
	return "Error: invalid token";
}

const char *RPN::DivideByZero::what() const throw()
{
	return "Error: cannot divide by zero";
}

const char *RPN::OutOfBounds::what() const throw()
{
	return "Error: result out of int limits";
}

