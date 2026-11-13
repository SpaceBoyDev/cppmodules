#include "../include/PmergeMe.hpp"
#include <climits>
#include <stdexcept>
#include <algorithm>

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	(void)other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	(void)other;
	return (*this);
}

PmergeMe::~PmergeMe()
{
}

std::vector<std::size_t> PmergeMe::jacobsthalOrder(std::size_t count)
{
	std::vector<std::size_t> order;
	if (count == 0)
		return (order);
	order.push_back(0);
	std::size_t previous = 1;
	std::size_t current = 3;
	while (order.size() < count)
	{
		std::size_t upper;

		if (current < count)
			upper = current;
		else
			upper = count;

		std::size_t lower = previous + 1;
	
		for (std::size_t index = upper; index >= lower; --index)
			order.push_back(index - 1);

		std::size_t next = current + 2 * previous;
		previous = current;
		current = next;
	}
	return (order);
}

template <typename Container>
typename Container::iterator PmergeMe::insertionPosition(Container& values,
	int value, typename Container::iterator limit)
{
	typename Container::iterator first = values.begin();
	while (first != limit)
	{
		typename Container::iterator middle = first;
		std::advance(middle, std::distance(first, limit) / 2);
		if (middle->value < value)
			first = ++middle;
		else
			limit = middle;
	}
	return (first);
}

template <typename Container>
Container PmergeMe::fordJohnson(Container values)
{
	if (values.size() <= 1)
		return (values);

	Container winners;
	std::vector<Item> pending;
	bool hasStraggler = false;
	Item straggler;

	std::size_t index = 0;
	while (index + 1 < values.size())
	{
		Item first = values[index];
		Item second = values[index + 1];
		if (first.value > second.value)
			std::swap(first, second);
		pending.push_back(Item(first.value, second.value));
		winners.push_back(Item(second.value, 0));
		index += 2;
	}

	if (index < values.size())
	{
		hasStraggler = true;
		straggler = values[index];
	}

	winners = fordJohnson(winners);
	Container result = winners;
	std::vector<std::size_t> order = jacobsthalOrder(pending.size());
	for (std::vector<std::size_t>::const_iterator it = order.begin();
		it != order.end(); ++it)
	{
		const Item item = pending[*it];
		typename Container::iterator limit = result.begin();
		while (limit != result.end() && limit->value < item.partner)
			++limit;
		typename Container::iterator position =
			insertionPosition(result, item.value, limit);
		result.insert(position, item);
	}

	if (hasStraggler)
	{
		typename Container::iterator position =
			insertionPosition(result, straggler.value, result.end());
		result.insert(position, straggler);
	}
	return (result);
}

template <typename WorkContainer, typename ResultContainer>
ResultContainer PmergeMe::parseAndSort(int size, char **seq)
{
	checkSequence(seq, size);
	WorkContainer values;
	for (int index = 0; index < size; ++index)
		values.push_back(Item(std::atoi(seq[index])));
	WorkContainer sorted = fordJohnson(values);
	ResultContainer result;
	for (typename WorkContainer::const_iterator it = sorted.begin();
		it != sorted.end(); ++it)
		result.push_back(it->value);
	return (result);
}

void PmergeMe::checkSequence(char **seq, int size)
{
	for (int i = 0; i < size; ++i)
	{
		if (seq[i][0] == '\0')
			throw std::logic_error("invalid argument");
		for (int j = 0; seq[i][j]; ++j)
			if (!std::isdigit(static_cast<unsigned char>(seq[i][j])))
				throw std::logic_error("argument must be a positive integer");
		char *end = 0;
		long value = std::strtol(seq[i], &end, 10);
		if (*end != '\0' || value > INT_MAX)
			throw std::logic_error("number outside of int limits");
	}
}

std::vector<int> PmergeMe::sortVector(int size, char **seq)
{
	PmergeMe sorter;
	return (sorter.parseAndSort<std::vector<Item>, std::vector<int> >(size, seq));
}

std::deque<int> PmergeMe::sortDeque(int size, char **seq)
{
	PmergeMe sorter;
	return (sorter.parseAndSort<std::deque<Item>, std::deque<int> >(size, seq));
}
