
#include "MutantStack.hpp"
#include <iostream>
#include <deque>
#include <list>
#include <vector>

int main()
{
	MutantStack<int> first;
	first.push(5);

	MutantStack<int> second(first);
	MutantStack<int> third;
	third = second;
	std::cout << std::endl;

	/* use MutantStack */
	{	
		std::cout << "## test MutantStack ##" << std::endl;
		MutantStack<int> mstack;
		mstack.push(1);
		mstack.push(2);
		std::cout << "top: " << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "size: " << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(4);
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
	}

	/* use deque */
	{
		std::cout << "## test deque ##" << std::endl;
		std::deque<int> mydeque;
		mydeque.push_back(1);
		mydeque.push_back(2);
		std::cout << "back: " << mydeque.back() << std::endl;
		mydeque.pop_back();
		std::cout << "size: " << mydeque.size() << std::endl;
		mydeque.push_back(3);
		mydeque.push_back(4);
		MutantStack<int>::iterator it2 = mydeque.begin();
		MutantStack<int>::iterator ite2 = mydeque.end();
		++it2;
		--it2;
		while (it2 != ite2)
		{
			std::cout << *it2 << std::endl;
			++it2;
		}
		// both work!
		std::stack<int, std::deque<int> > s2(mydeque);
		// MutantStack<int> s2(mydeque);
		std::cout << "top: " << s2.top() << std::endl;
		std::cout << std::endl;
	}

	/* use list */
	{
		std::cout << "## test list ##" << std::endl;
		std::list<int> mylist;
		mylist.push_back(1);
		mylist.push_back(2);
		std::cout << "back: " << mylist.back() << std::endl;
		mylist.pop_back();
		std::cout << "size: " << mylist.size() << std::endl;
		mylist.push_back(3);
		mylist.push_back(4);
		MutantStack<int, std::list<int> >::iterator it3 = mylist.begin();
		MutantStack<int, std::list<int> >::iterator ite3 = mylist.end();
		++it3;
		--it3;
		while (it3 != ite3)
		{
			std::cout << *it3 << std::endl;
			++it3;
		}
		std::stack<int, std::list<int> > s3(mylist);
		// MutantStack<int, std::list<int> > s3(mylist);
		std::cout << "top: " << s3.top() << std::endl;
		std::cout << std::endl;
	}
	
	/* use vector */
	{
		std::cout << "## test vector ##" << std::endl;
		std::vector<int> myvector;
		myvector.push_back(1);
		myvector.push_back(2);
		std::cout << "back: " << myvector.back() << std::endl;
		myvector.pop_back();
		std::cout << "size: " << myvector.size() << std::endl;
		myvector.push_back(3);
		myvector.push_back(4);
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
		// MutantStack<int, std::vector<int> > s4(myvector);
		std::cout << "top: " << s4.top() << std::endl;
	}

	return 0;
}
