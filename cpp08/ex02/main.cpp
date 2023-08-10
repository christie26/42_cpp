
#include "MutantStack.hpp"
#include <iostream>
#include <deque>

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "top: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "size: " << mstack.size() << std::endl;
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

	std::cout << std::endl;

	std::deque<int> mydeque;
	mydeque.push_back(5);
	mydeque.push_back(17);
	std::cout << "back: " << mydeque.back() << std::endl;
	mydeque.pop_back();
	std::cout << "size: " << mydeque.size() << std::endl;
	mydeque.push_back(3);
	mydeque.push_back(5);
	mydeque.push_back(737);
	//[...]
	mydeque.push_back(0);
	MutantStack<int>::iterator it2 = mydeque.begin();
	MutantStack<int>::iterator ite2 = mydeque.end();
	++it2;
	--it2;
	while (it2 != ite2)
	{
	std::cout << *it2 << std::endl;
	++it2;
	}
	std::stack<int> s1(mydeque);
	return 0;
}
