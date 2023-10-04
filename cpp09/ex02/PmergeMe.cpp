
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
	
	insertElement(_deque, 0, _deque.size(), 7);
	
	sortPair(pairs);
	
	printBefore();
}

int binarySearch(const std::deque<int>& arr, int left, int right, int element) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == element) {
            return mid; // Element already exists, return its index
        }
        if (arr[mid] < element) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left;
}

void PmergeMe::insertElement(std::deque<int>& arr, int startIndex, int endIndex, int element) {
	int insertPos = binarySearch(arr, startIndex, endIndex, element);

	while (endIndex >= insertPos) {
		arr[endIndex + 1] = arr[endIndex];
		endIndex--;
	}
	arr[insertPos] = element;
}

void PmergeMe::sortPair(std::deque<std::pair<itD, itD> >& pairs) {
    if (pairs.size() <= 1) {
        return; // Termination condition: nothing to sort
    }
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
	// std::deque<std::pair<itD, itD> >::iterator it;
	for (it = new_pairs.begin(); it != new_pairs.end(); it++) {
		main_chain.push_back(*it->first);
	}

	// put y1 
	main_chain.push_front(*new_pairs[0].second);

	// put y3, y2
	for (size_t i = 3; i > 1; i++) {
		insertElement(main_chain, 0, 0 + 2, *new_pairs[i - 1].second);
	}

}
