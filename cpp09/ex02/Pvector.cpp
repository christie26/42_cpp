
#include "PmergeMe.hpp"
#include <iostream>

void PmergeMe::msVector(std::vector<int>& _vector) {
	
	std::cout << "Before:";
	printVector();
	std::vector<std::pair<itV, itV> > pairs;

	for (itV it = _vector.begin(); it < _vector.end() - 1; it += 2) {
		std::pair<itV, itV> new_pair;
		new_pair.first = *it > *(it+1) ? it : (it+1);
		new_pair.second = *it <= *(it+1) ? it : (it+1);
		pairs.push_back(new_pair);
	}
	sortVectorPair(pairs);
	lastChain(pairs, _vector);
	std::cout << "After :";
	printVector();
}

void PmergeMe::sortVectorPair(it_pairV& pairs) {
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
	sortVectorPair(new_pairs);
	fillMainChain(new_pairs, pairs);
}

void PmergeMe::insertElement(it_pairV& main_chain, it_pair_itV startIt, it_pair_itV endIt, itV& element, it_pairV& pairs) {
	it_pair_itV insertPos = std::lower_bound(startIt, endIt, element, CustomCompare);
	main_chain.insert(insertPos, findMatchPair(pairs, element));
}

void PmergeMe::insertElementInt(std::vector<int>& main_chain, itV startIt, itV endIt, int element) {
    std::vector<int>::iterator insertPos = std::lower_bound(startIt, endIt, element);
    main_chain.insert(insertPos, element);
}

itP PmergeMe::findMatchPair(it_pairV& pairs, itV& targetPair) {
	it_pair_itV it = pairs.begin();
	while (it != pairs.end() && it->first != targetPair) {
		it++;
	}
	return *it;
}

void PmergeMe::fillMainChain(it_pairV& new_pairs, it_pairV& pairs) {
	
	it_pairV main_chain;
	for (it_pair_itV it = new_pairs.begin(); it != new_pairs.end(); it++)
		main_chain.push_back(findMatchPair(pairs, it->first));
	main_chain.insert(main_chain.begin(), findMatchPair(pairs, new_pairs[0].second));
	
	int i = 2;
	while (true) {
        size_t j = getJacop(i) > new_pairs.size() ? new_pairs.size() : getJacop(i);
		for (; j > getJacop(i - 1); j--) {
			it_pair_itV pairPos = std::lower_bound(main_chain.begin(), main_chain.end(), new_pairs[j - 1].first, CustomCompare);
			insertElement(main_chain, main_chain.begin(), pairPos, new_pairs[j - 1].second, pairs);
		}
		if (getJacop(i) > new_pairs.size())
			break;
		i++;
	}
	if (new_pairs.size() * 2 != pairs.size())
		insertElement(main_chain, main_chain.begin(), main_chain.end(), (pairs.end() - 1)->first, pairs);
	pairs = main_chain;
}

void PmergeMe::lastChain(it_pairV& pairs, std::vector<int>& _vector) {

	std::vector<int> main_chain;
    for (size_t i = 0; i < pairs.size(); i++)
        main_chain.push_back(*(pairs[i].first));
    main_chain.insert(main_chain.begin(), *pairs[0].second);

    int i = 2;
    while (true) {
        size_t j = getJacop(i) > pairs.size() ? pairs.size() : getJacop(i);
        for (; j > getJacop(i - 1); j--) {
            int element = *pairs[j - 1].second;
            std::vector<int>::iterator pairPos = std::lower_bound(main_chain.begin(), main_chain.end(), element);
            insertElementInt(main_chain, main_chain.begin(), pairPos, element);
        }
		if (getJacop(i) > pairs.size())
			break;
        i++;
    }
    
    if (pairs.size() * 2 != _vector.size())
        insertElementInt(main_chain, main_chain.begin(), main_chain.end(), *(_vector.end() - 1));
	_vector = main_chain;
}

bool PmergeMe::CustomCompare(const std::pair<itV, itV>& lhs, const itV& rhs) {
    return *(lhs.first) < *rhs;
}
