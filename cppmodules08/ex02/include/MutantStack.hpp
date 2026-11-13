#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	private:
	public:
		MutantStack();
		MutantStack(const MutantStack &other);
		MutantStack &operator=(const MutantStack &other);

		~MutantStack();

		typedef typename std::stack<T>::container_type::const_iterator iterator;
		typename MutantStack<T>::iterator	begin();
		typename MutantStack<T>::iterator	end();

};

#include "../source/MutantStack.tpp"

#endif
