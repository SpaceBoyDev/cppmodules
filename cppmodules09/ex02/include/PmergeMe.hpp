#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>

struct Item
{
	int value;
	int partner;

	Item(int value = 0, int partner = 0)
		: value(value), partner(partner) {}
};

class PmergeMe
{
	private:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

		template <typename WorkContainer, typename ResultContainer>
		ResultContainer parseAndSort(int size, char **seq);

		void checkSequence(char **seq, int size);

		std::vector<std::size_t> jacobsthalOrder(std::size_t count);

		template <typename Container>
		Container fordJohnson(Container values);

		template <typename Container>
		typename Container::iterator insertionPosition(Container& values,
			int value, typename Container::iterator limit);

	public:
		static std::vector<int>	sortVector(int size, char **seq);
		static std::deque<int>	sortDeque(int size, char **seq);
};

#endif

