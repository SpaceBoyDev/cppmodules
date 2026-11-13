#include "../include/BitcoinExchange.hpp"

#include <ctime>
#include <algorithm>

BitcoinExchange::BitcoinExchange(std::string fileInput) : _fileInput(fileInput), _fileDatabase("data/data.csv")
{
}

BitcoinExchange::BitcoinExchange(std::string fileInput, std::string fileDatabase) :
	_fileInput(fileInput),
	_fileDatabase(fileDatabase)
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : 
	_fileInput(other._fileInput),
	_fileDatabase(other._fileDatabase),
	_database(other._database)
{
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		_fileInput = other._fileInput;
		_fileDatabase = other._fileDatabase;
		_database = other._database;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::startComparison()
{
	openCSV();
	parseInput();
}

void BitcoinExchange::compareValues(const t_pair &entry)
{
	if (_database.empty())
		return;

	std::map<const std::string, float>::iterator it;
	it = _database.lower_bound(entry.date);

	if (it == _database.end() || it->first != entry.date)
	{
		if (it == _database.begin())
			throw DateTooEarly();
		--it;
	}

	std::cout << entry.date << " => "
		  << entry.value << " = " << entry.value * it->second << "\n";
}

void BitcoinExchange::openCSV()
{
	std::ifstream	file(_fileDatabase.c_str());

	if (!file.is_open() || file.fail())
		throw CantOpenFile();

	readSaveCSV(file);

	file.close();
}

void BitcoinExchange::readSaveCSV(std::ifstream &file)
{
	std::string	line;
	
	std::getline(file, line);

	while(std::getline(file, line))
	{
		if (line.empty())
			continue ;

		std::stringstream	row(line);
		std::string			date;
		std::string			priceText;

		if (!std::getline(row, date, ',') ||
			!std::getline(row, priceText))
		{
			std::cerr << "Error: Invalid line: " << line << "\n";
			continue ;
		}

		std::stringstream	priceStream(priceText);
		float				price;

		if (!(priceStream >> price))
		{
			std::cerr << "Error: Invalid price: " << price << "\n";
			continue ;
		}
		_database[date] = price;
	}
}

void BitcoinExchange::parseInput()
{
	std::ifstream	file(_fileInput.c_str());
	std::string		date;
	float			value;
	
	if (!file.is_open() || file.fail())
		throw CantOpenFile();

	std::string	line;
	std::getline(file, line);

	if (line != "date | value")
		throw IncorrectHeader();

	while (std::getline(file, line))
	{
		try
		{
			if (line.empty())
				throw EmptyLine();
			compareValues(parseInputLine(line, date, value));
		}
		catch(const std::invalid_argument& e)
		{
			std::cerr << e.what() << '\n';
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	file.close();
}

t_pair BitcoinExchange::parseInputLine(const std::string &line, std::string &date, float &value)
{
	std::stringstream	row(line);
	std::string			valueText;
	t_pair				pair;

	if (!std::getline(row, date, '|') ||
		!std::getline(row, valueText))
		throw BadInput(line);

	date = trim(date);
	valueText = trim(valueText); 

	if (date.empty() || valueText.empty())
		throw BadInput(line);

	std::stringstream dateStream(date);
	int	year;
	int	month;
	int	day;
	char firstDash;
	char secondDash;

	if (!(dateStream >> year >> firstDash >> month >> secondDash >> day))
		throw BadInput(line);

	if (firstDash != '-' || secondDash != '-' ||
		!isValidDate(year, month, day))
			throw BadInput(line);

	std::stringstream valueStream(valueText);

	if (!(valueStream >> value))
		throw BadInput(line);
	
	valueStream >> std::ws;

	if (!valueStream.eof())
		throw BadInput(line);

	if (value < 0)
		throw NegativeValue();
	else if (value > 1000)
		throw ValueTooLarge();

	pair.date = date;
	pair.value = value;
	return pair;
}

bool BitcoinExchange::isValidDate(int year, int month, int day)
{
	struct std::tm date;
	std::time_t timestamp;

	date.tm_year = year - 1900;
	date.tm_mon = month - 1;
	date.tm_mday = day;
	date.tm_hour = 12;
	date.tm_min = 30;
	date.tm_sec = 1;
	date.tm_isdst = -1;

	timestamp = std::mktime(&date);

	if (timestamp == -1)
		return false;

	return (date.tm_year == year - 1900 &&
		date.tm_mon == month - 1 &&
		date.tm_mday == day);
}

std::string BitcoinExchange::trim(const std::string &text)
{
	std::string::size_type	first;
	std::string::size_type	last;

	first = text.find_first_not_of(" ");
	last = text.find_last_not_of(" ");

	if (first == std::string::npos)
		return "";

	return text.substr(first, last - first + 1);
}

const char *BitcoinExchange::CantOpenFile::what() const throw()
{
	return "\x1B[31mError: could not open file\033[0m";
}

const char *BitcoinExchange::DateTooEarly::what() const throw()
{
	return "\x1B[31mError: date is earlier than database\033[0m";
}

const char *BitcoinExchange::IncorrectHeader::what() const throw()
{
	return "\x1B[31mError: input header must be \"date | value\"\033[0m";
}

const char *BitcoinExchange::EmptyLine::what() const throw()
{
	return "\x1B[31mError: empty line\033[0m";
}

const char *BitcoinExchange::NegativeValue::what() const throw()
{
	return "\x1B[31mError: not a positive number\033[0m";
}

const char *BitcoinExchange::ValueTooLarge::what() const throw()
{
	return "\x1B[31mError: too large a number\033[0m";
}

BitcoinExchange::BadInput::BadInput(const std::string &message)
	: std::invalid_argument("\x1B[31mError: bad input => " + message + "\033[0m")
{
}
