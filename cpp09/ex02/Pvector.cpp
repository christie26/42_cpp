
#include "PmergeMe.hpp"
#include <iostream>
#include <sys/time.h>

double PmergeMe::msVector(std::vector<int>& _vector) {
	
	timeval start;
	gettimeofday(&start, 0);

	itV_pairV pairs;
	for (itV it = _vector.begin(); it < _vector.end() - 1; it += 2) {
		itV_pair new_pair;
		new_pair.first = *it > *(it+1) ? it : (it+1);
		new_pair.second = *it <= *(it+1) ? it : (it+1);
		pairs.push_back(new_pair);
	}
	sortPairV(pairs);
	finalChainV(pairs, _vector);
	timeval end;
	gettimeofday(&end, 0);
	std::cout << "After :";
	printVector();
	float diff_time = static_cast<float>(end.tv_sec * 1000000 + end.tv_usec - start.tv_sec * 1000000 - start.tv_usec);
	return diff_time;
}

void PmergeMe::sortPairV(itV_pairV& pairs) {
    if (pairs.size() <= 1) {
		if (*pairs.begin()->first < *pairs.begin()->second)
			std::swap(pairs.begin()->first, pairs.begin()->second);
        return;
	}
	itV_pairV new_pairs;
	for (itV_pairV_it it = pairs.begin(); it < pairs.end() - 1; it += 2) {
		std::pair<itV, itV> new_pair;
		new_pair.first = *it->first > *(it+1)->first ? it->first : (it+1)->first;
		new_pair.second = *it->first <= *(it+1)->first ? it->first : (it+1)->first;
		new_pairs.push_back(new_pair);
	}
	sortPairV(new_pairs);
	fillMainChainV(new_pairs, pairs);
}

void PmergeMe::insertElementV(itV_pairV& main_chain, itV_pairV_it startIt, itV_pairV_it endIt, itV& element, itV_pairV& pairs) {
	itV_pairV_it insertPos = std::lower_bound(startIt, endIt, element, CustomCompareV);
	main_chain.insert(insertPos, findMatchPairV(pairs, element));
}

void PmergeMe::insertElementIntV(std::vector<int>& main_chain, itV startIt, itV endIt, int element) {
    std::vector<int>::iterator insertPos = std::lower_bound(startIt, endIt, element);
    main_chain.insert(insertPos, element);
}

itV_pair PmergeMe::findMatchPairV(itV_pairV& pairs, itV& targetPair) {
	itV_pairV_it it = pairs.begin();
	while (it != pairs.end() && it->first != targetPair) {
		it++;
	}
	return *it;
}

void PmergeMe::fillMainChainV(itV_pairV& new_pairs, itV_pairV& pairs) {
	
	itV_pairV main_chain;
	for (itV_pairV_it it = new_pairs.begin(); it != new_pairs.end(); it++)
		main_chain.push_back(findMatchPairV(pairs, it->first));
	main_chain.insert(main_chain.begin(), findMatchPairV(pairs, new_pairs[0].second));
	
	int i = 2;
	while (true) {
        size_t j = getJacop(i) > new_pairs.size() ? new_pairs.size() : getJacop(i);
		for (; j > getJacop(i - 1); j--) {
			itV_pairV_it pairPos = std::lower_bound(main_chain.begin(), main_chain.end(), new_pairs[j - 1].first, CustomCompareV);
			insertElementV(main_chain, main_chain.begin(), pairPos, new_pairs[j - 1].second, pairs);
		}
		if (getJacop(i) > new_pairs.size())
			break;
		i++;
	}
	if (new_pairs.size() * 2 != pairs.size())
		insertElementV(main_chain, main_chain.begin(), main_chain.end(), (pairs.end() - 1)->first, pairs);
	pairs = main_chain;
}

void PmergeMe::finalChainV(itV_pairV& pairs, std::vector<int>& _vector) {

	std::vector<int> main_chain;
    for (size_t i = 0; i < pairs.size(); i++)
        main_chain.push_back(*(pairs[i].first));
    main_chain.insert(main_chain.begin(), *pairs[0].second);

    int i = 2;
    while (true) {
        size_t j = getJacop(i) > pairs.size() ? pairs.size() : getJacop(i);
        for (; j > getJacop(i - 1); j--) {
            int element = *pairs[j - 1].second;
            itV pairPos = std::lower_bound(main_chain.begin(), main_chain.end(), element);
            insertElementIntV(main_chain, main_chain.begin(), pairPos, element);
        }
		if (getJacop(i) > pairs.size())
			break;
        i++;
    }
    
    if (pairs.size() * 2 != _vector.size())
        insertElementIntV(main_chain, main_chain.begin(), main_chain.end(), *(_vector.end() - 1));
	_vector = main_chain;
}

bool PmergeMe::CustomCompareV(const std::pair<itV, itV>& lhs, const itV& rhs) {
    return *(lhs.first) < *rhs;
}
