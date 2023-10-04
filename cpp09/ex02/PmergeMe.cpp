
#include "PmergeMe.hpp"
#include <sstream>
#include <exception>
#include <iostream>
#include <utility>

PmergeMe::PmergeMe(const std::string& str) : _size(0) {
	try {
		fillContainer(str);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
		return ;
	}
	printBefore();
	// std::deque<int> sortedDeque = msDeque(_deque, _size);
	msDeque(_deque);

	// sort for deque
	// sort for vector

}
PmergeMe::~PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe&) {}
PmergeMe& PmergeMe::operator=(const PmergeMe&) {
	return *this;
}

void PmergeMe::fillContainer(const std::string& str) {
	std::istringstream ss(str);
	
	while (!ss.eof()) {
		int num;
		ss >> num;
		if(ss.fail() || num <= 0) {
			throw std::invalid_argument("Error.");
		}
		_deque.push_back(num);
		_vector.push_back(num);
		_size++;
	}
}

void PmergeMe::printBefore() {

	std::deque<int>::iterator it;
	std::cout << "Before:";

	for (it = _deque.begin(); it != _deque.end(); it++) {
		std::cout << " " << *it;
	}
	std::cout << std::endl;
}

void PmergeMe::msDeque(std::deque<int>& _deque) {
	
	std::deque<std::pair<itD, itD> > pairs;

	for (itD it = _deque.begin(); it < _deque.end() - 1; it += 2) {
		std::pair<itD, itD> new_pair;
		new_pair.first = *it > *(it+1) ? it : (it+1);
		new_pair.second = *it <= *(it+1) ? it : (it+1);
		pairs.push_back(new_pair);
	}
	
	sortPair(pairs);



	
}

void insertElement(itD startIndex, itD endIndex, int element) {

	// binary search
}

void PmergeMe::sortPair(std::deque<std::pair<itD, itD> >& pairs) {

	std::deque<std::pair<itD, itD> > new_pairs;

	std::deque<std::pair<itD, itD> >::iterator it;
	for (it = pairs.begin(); it < pairs.end() - 1; it += 2) {
		std::pair<itD, itD> new_pair;
		new_pair.first = *it->first > *(it+1)->first ? it->first : (it+1)->first;
		new_pair.second = *it->first <= *(it+1)->first ? it->first : (it+1)->first;
		new_pairs.push_back(new_pair);
	}

	sortPair(new_pairs);
	
	// make main chain
	std::deque<int> main_chain;
	std::deque<std::pair<itD, itD> >::iterator it;
	for (it = new_pairs.begin(); it != new_pairs.end(); it++) {
		main_chain.push_back(*it->first);
	}

	// put y1 
	main_chain.push_front(*new_pairs[0].second);

	// put y3, y2
	for (size_t i = 3; i > 1; i++) {
		insertElement(main_chain.begin(), main_chain.begin() + 2, *new_pairs[i - 1].second);
	}



}