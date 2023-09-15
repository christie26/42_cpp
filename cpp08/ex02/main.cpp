
#include "MutantStack.hpp"
#include <iostream>
#include <deque>
#include <list>
#include <vector>

int main()
{
	/* use MutantStack */
	std::cout << "## test MutantStack ##" << std::endl;
	MutantStack<int> mstack;
	// MutantStack<int, std::stack<int> > mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "top: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "size: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(737);
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
	std::stack<int> s1(mstack);
	std::cout << "top: " << s1.top() << std::endl;
	std::cout << std::endl;

	/* use deque */
	std::cout << "## test deque ##" << std::endl;
	std::deque<int> mydeque;
	mydeque.push_back(5);
	mydeque.push_back(17);
	std::cout << "back: " << mydeque.back() << std::endl;
	mydeque.pop_back();
	std::cout << "size: " << mydeque.size() << std::endl;
	mydeque.push_back(3);
	mydeque.push_back(737);
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
	std::stack<int> s2(mydeque);
	std::cout << "top: " << s2.top() << std::endl;
	std::cout << std::endl;
// we can initialize stack with deque. 

	/* use list */
	std::cout << "## test list ##" << std::endl;
	std::list<int> mylist;
	mylist.push_back(5);
	mylist.push_back(17);
	std::cout << "back: " << mylist.back() << std::endl;
	mylist.pop_back();
	std::cout << "size: " << mylist.size() << std::endl;
	mylist.push_back(3);
	mylist.push_back(737);
	mylist.push_back(0);
	MutantStack<int, std::list<int> >::iterator it3 = mylist.begin();
	// std::list<int>::iterator it3 = mylist.begin();
	std::list<int>::iterator ite3 = mylist.end();
	++it3;
	--it3;
	while (it3 != ite3)
	{
		std::cout << *it3 << std::endl;
		++it3;
	}
	std::stack<int, std::list<int> > s3(mylist);
	std::cout << "top: " << s3.top() << std::endl;
	return 0;

	/* use vector */
	std::cout << "## test vector ##" << std::endl;
	std::vector<int> myvector;
	myvector.push_back(5);
	myvector.push_back(17);
	std::cout << "back: " << myvector.back() << std::endl;
	myvector.pop_back();
	std::cout << "size: " << myvector.size() << std::endl;
	myvector.push_back(3);
	myvector.push_back(737);
	myvector.push_back(0);
	MutantStack<int, std::vector<int> >::iterator it4 = myvector.begin();
	MutantStack<int, std::vector<int> >::iterator ite4 = myvector.end();
	++it4;
	--it4;
	while (it4 != ite4)
	{
		std::cout << *it4 << std::endl;
		++it4;
	}
	std::stack<int, std::vector<int> > s4(myvector);
	std::cout << "top: " << s4.top() << std::endl;
	return 0;
}
