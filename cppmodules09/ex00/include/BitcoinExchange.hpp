#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <exception>

typedef struct s_pair {
	std::string	date;
	float		value;
} t_pair;


class BitcoinExchange
{
	private:
		std::string						_fileInput;
		std::string						_fileDatabase;
		std::map<std::string, float>	_database;

		void							compareValues(const t_pair &entry);
		void							openCSV();
		void							readSaveCSV(std::ifstream &file);
		void							parseInput();
		t_pair							parseInputLine(const std::string &line,
												std::string &date, float &value);
		bool							isValidDate(int year, int month, int day);
		std::string						trim(const std::string &text);

		class CantOpenFile : public std::exception
		{
			virtual const char* what() const throw();
		};

		class DateTooEarly : public std::exception
		{
			virtual const char* what() const throw();
		};

		class IncorrectHeader : public std::exception
		{
			virtual const char* what() const throw();
		};

		class EmptyLine : public std::exception
		{
			virtual const char* what() const throw();
		};

		class NegativeValue : public std::exception
		{
			virtual const char* what() const throw();
		};

		class ValueTooLarge : public std::exception
		{
			virtual const char* what() const throw();
		};

		class BadInput : public std::invalid_argument
		{
			public:
			BadInput(const std::string &message);
		};

	public:
		BitcoinExchange(std::string fileInput);
		BitcoinExchange(std::string fileInput, std::string fileDatabase);
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange	&operator=(const BitcoinExchange &other);

		~BitcoinExchange();

		void	startComparison();
};

#endif