
#include "PmergeMe.hpp"
#include <sstream>
#include <exception>
#include <iostream>
#include <utility>
#include <cmath>
#include <ctime>
#include <unistd.h>
#include <sys/time.h>

void printTime(std::string containerType, std::clock_t time, int size);

void printTime(std::string containerType, std::clock_t time, int size)
{
	double clock_per_ms = static_cast<double>(CLOCKS_PER_SEC) / 1000;
	double timeInMs = time / clock_per_ms;

	std::cout << "Time to process a range of " << size << " elements with std::"
		<< containerType << ": " << time << " clock ticks (";
	std::cout << std::fixed;
	std::cout.precision( 6 );
	std::cout << timeInMs << " ms)" << std::endl;
}

PmergeMe::PmergeMe(const std::string& str) : _size(0)  {
	try {
		fillContainer(str);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
		return ;
	}
// timeval start;
// gettimeofday(&start, 0);
// usleep(3000000);
// timeval end;
// gettimeofday(&end, 0);
// 	double diff_time = static_cast<double>(end.tv_sec * 1000000 + end.tv_usec - start.tv_usec - start.tv_sec * 1000000);
// 	std::cout << "Time to process a range of " << _size << " elements with std::vector : ";
// 	std::cout << diff_time << " ms" << std::endl;


	// msVector(_vector);
	// msList(_list);

	std::clock_t start = clock();
	usleep(3000000);
	std::clock_t end = clock();
	double diff_time = 1000 * static_cast<double>(end - start) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << _size << " elements with std::list : ";
	std::cout << diff_time << " ms" << std::endl;

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
