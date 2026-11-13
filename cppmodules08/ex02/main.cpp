#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "include/MutantStack.hpp"

int	main(void)
{
	std::srand((std::time(NULL)));
	std::cout << "----SUBJECT MAIN----\n";
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << "Top: " << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "Size: " << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}

	std::cout << "\n----MUTANT STACK----\n";
	{
		MutantStack<int> mstack;
		int stackSize = 15;
		for (int i = 0; i < stackSize; ++i)
			mstack.push(std::rand() % 100);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::cout << "Top: " << mstack.top() << std::endl;
		std::cout << "Size: " << mstack.size() << std::endl;
		std::cout << "Stack.pop()\n";
		mstack.pop();
		std::cout << "Top: " << mstack.top() << std::endl;
		std::cout << "Size: " << mstack.size() << std::endl;
	}

	std::cout << "\n----COPY STACK----\n";
	{
		MutantStack<int> mstack;
		int stackSize = 5;
		for (int i = 0; i < stackSize; ++i)
			mstack.push(std::rand() % 100);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		std::cout << "Original Stack\n";
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		MutantStack<int> copyStack(mstack);
		it = copyStack.begin();
		ite = copyStack.end();

		mstack.pop();
		
		std::cout << "\nCopy Stack\n";
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}

		MutantStack<int> assignStack;
		assignStack = copyStack;
		it = assignStack.begin();
		ite = assignStack.end();

		copyStack.pop();
		copyStack.pop();
		
		std::cout << "\nAssign Stack\n";
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}

		std::cout << "\n----Stacks Info after changes----\n";
		std::cout << "----Original Stack Info----\nSize: " << mstack.size()
			<< " Top: " << mstack.top() << std::endl;
		std::cout << "----Copy Stack Info----\nSize: " << copyStack.size()
			<< " Top: " << copyStack.top() << std::endl;
		std::cout << "----Assign Stack Info----\nSize: " << assignStack.size()
			<< " Top: " << assignStack.top() << std::endl;
	}

	return 0;
}