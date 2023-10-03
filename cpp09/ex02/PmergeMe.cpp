
#include "PmergeMe.hpp"
#include <sstream>
#include <exception>
#include <iostream>

PmergeMe::PmergeMe(const std::string& str) {
	try {
		fillContainer(str);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
		return ;
	}
	printBefore();
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
	}
}

void PmergeMe::printBefore() const {

	std::deque<int>::const_iterator it;
	std::cout << "Before:";

	for (it = _deque.begin(); it != _deque.end(); it++) {
		std::cout << " " << *it;
	}
	std::cout << std::endl;
}