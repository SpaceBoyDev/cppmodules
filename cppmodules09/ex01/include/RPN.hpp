#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <exception>

# define ADD '+'
# define SUBSTRACT '-'
# define MULTIPLY '*'
# define DIVIDE '/'

class RPN
{
	private:
		std::stack<long>	_op;
		std::string			_input;

		bool				isOperator(char c);
		void				evaluateOp(char op);
		
		class InvalidSyntax : public std::exception{
			virtual const char* what() const throw();
		};
		class InvalidToken : public std::exception{
			virtual const char* what() const throw();
		};
		class DivideByZero : public std::exception{
			virtual const char* what() const throw();
		};
		class OutOfBounds : public std::exception{
			virtual const char* what() const throw();
		};

	public:
		RPN(std::string input);
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);

		~RPN();

		long			solve();
};

#endif