
#include "PmergeMe.hpp"
#include <sstream>
#include <exception>
#include <iostream>
#include <utility>
#include <cmath>
#include <algorithm>

PmergeMe::PmergeMe(const std::string& str) : _size(0) {
	try {
		fillContainer(str);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
		return ;
	}
	printBefore();
	msVector(_vector);

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
		_vector.push_back(num);
		// _vector.push_back(num);
		_size++;
	}
}

void PmergeMe::printBefore() {

	std::vector<int>::iterator it;
	std::cout << "Before:";

	for (it = _vector.begin(); it != _vector.end(); it++) {
		std::cout << " " << *it;
	}
	std::cout << std::endl;
}

void PmergeMe::msVector(std::vector<int>& _vector) {
	
	std::vector<std::pair<itV, itV> > pairs;

	for (itV it = _vector.begin(); it < _vector.end() - 1; it += 2) {
		std::pair<itV, itV> new_pair;
		new_pair.first = *it > *(it+1) ? it : (it+1);
		new_pair.second = *it <= *(it+1) ? it : (it+1);
		pairs.push_back(new_pair);
	}
	
	sortPair(pairs);
	
	printBefore();
}

void PmergeMe::insertElement(it_pairV& main_chain, it_pair_itV startIt, it_pair_itV endIt, itV& element, it_pairV& pairs) {
	if (endIt >= main_chain.end())
		endIt = main_chain.end() - 1;

	it_pair_itV insertPos = std::lower_bound(startIt, endIt, element, CustomCompare);

	main_chain.insert(insertPos, *findMatchPair(pairs, element));
}

it_pair_itV PmergeMe::findMatchPair(it_pairV& pairs, itV targetPair) {

	it_pair_itV it = pairs.begin();
	while (it != pairs.end() && it->first != targetPair) {
		it++;
	}
	return it;
}

size_t getJ(int n) {
	if (n % 2) {
        return (std::pow(2, n) + 1) / 3.0;
    } else {
        return (std::pow(2, n) - 1) / 3.0;
    }
}

void PmergeMe::sortPair(it_pairV& pairs) {
    if (pairs.size() <= 1) {
		if (*pairs.begin()->first < *pairs.begin()->second) {
			std::swap(pairs.begin()->first, pairs.begin()->second);
		}
        return;
	}
	
	it_pairV new_pairs;
	for (it_pair_itV it = pairs.begin(); it < pairs.end() - 1; it += 2) {
		std::pair<itV, itV> new_pair;
		new_pair.first = *it->first > *(it+1)->first ? it->first : (it+1)->first;
		new_pair.second = *it->first <= *(it+1)->first ? it->first : (it+1)->first;
		new_pairs.push_back(new_pair);
	}
	sortPair(new_pairs);

	it_pairV main_chain;
	for (it_pair_itV it = new_pairs.begin(); it != new_pairs.end(); it++)
		main_chain.push_back(*findMatchPair(pairs, it->first));

	main_chain.insert(main_chain.begin(), *findMatchPair(pairs, new_pairs[0].second));

	if (pairs.size() == 2 || pairs.size() == 3) {
		insertElement(main_chain, main_chain.begin(), main_chain.begin() + 2, pairs[2].first, pairs);
		pairs = main_chain;
		return ;
	}

	int i = 3;
	while (true) {
		size_t j = getJ(i) > pairs.size() ? pairs.size() : getJ(i);
		for (; j > getJ(i - 1); j--)
			insertElement(main_chain, main_chain.begin(), main_chain.begin() + 3/* partner */, new_pairs[j - 1].second, pairs);
		if (pairs.size() < getJ(i))
			break;
		i++;
	}
	insertElement(main_chain, main_chain.begin(), main_chain.end(), (pairs.end()-1)->first, pairs);

	pairs = main_chain;
}

