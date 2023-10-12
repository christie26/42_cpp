
#include "PmergeMe.hpp"
#include <sstream>
#include <exception>
#include <iostream>
#include <utility>
#include <cmath>
#include <ctime>
#include <unistd.h>

void PmergeMe::printTime(std::string containerType, double time, int size)
{
	std::cout << "Time to process a range of " << size << " elements with std::" << containerType << " : ";
	std::cout << time << " us" << std::endl;
}

PmergeMe::PmergeMe(const std::string& str) : _size(0)  {
	try {
		fillContainer(str);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
		return ;
	}
	std::cout << "Before:";
	printVector();
	// usleep(30000);
	printTime("vector", msVector(_vector), _size);

	// msList(_list);
}

PmergeMe::~PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe&) {}
PmergeMe& PmergeMe::operator=(const PmergeMe&) { return *this; }

void PmergeMe::fillContainer(const std::string& str) {
	std::istringstream ss(str);
	
	while (!ss.eof()) {
		int num;
		ss >> num;
		if(ss.fail() || num <= 0) {
			throw std::invalid_argument("Error: element error.");
		}
		_vector.push_back(num);
		_list.push_back(num);
		_size++;
	}
}
void PmergeMe::printVector() {

	for (std::vector<int>::iterator it = _vector.begin(); it != _vector.end(); it++) {
		std::cout << " " << *it;
	}
	std::cout << std::endl;
}
void PmergeMe::printList() {
	for (std::list<int>::iterator it = _list.begin(); it != _list.end(); it++) {
		std::cout << " " << *it;
	}
	std::cout << std::endl;

}

size_t PmergeMe::getJacop(int n) {
	if (n % 2) {
        return (std::pow(2, n) + 1) / 3.0;
    } else {
        return (std::pow(2, n) - 1) / 3.0;
    }
}
