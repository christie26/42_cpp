
#include "PmergeMe.hpp"
#include <iostream>
#include <sys/time.h>

double PmergeMe::msList(std::list<int>& _list) {
	
	timeval start;
	gettimeofday(&start, 0);

    itL_pairL pairs;
    itL it = _list.begin();
    while (std::distance(it, _list.end()) >= 2) {
        itL_pair new_pair;
        itL it1 = it;
        itL it2 = std::next(it, 1);
        
        new_pair.first = (*it1 > *it2) ? it1 : it2;
        new_pair.second = (*it1 <= *it2) ? it1 : it2;
        
        pairs.push_back(new_pair);
        
        std::advance(it, 2);
    }
	sortPairL(pairs);
	finalChainL(pairs, _list);
	timeval end;
	gettimeofday(&end, 0);
	float diff_time = static_cast<float>(end.tv_sec * 1000000 + end.tv_usec - start.tv_sec * 1000000 - start.tv_usec);
	return diff_time;
	return 416;
}

void PmergeMe::sortPairL(itL_pairL& pairs) {
    if (pairs.size() <= 1) {
		if (*pairs.begin()->first < *pairs.begin()->second) {
			std::swap(pairs.begin()->first, pairs.begin()->second);
		}
        return;
	}
	itL_pairL new_pairs;
	itL_pairL_it it = pairs.begin();
	while (std::next(it) != pairs.end()) {
		itL_pair new_pair;
		itL_pairL_it next_it = std::next(it);

		new_pair.first = (*it->first > *next_it->first) ? it->first : next_it->first;
		new_pair.second = (*it->first <= *next_it->first) ? it->first : next_it->first;

		new_pairs.push_back(new_pair);

		std::advance(it, 2);
	}
	sortPairL(new_pairs);
	fillMainChainL(new_pairs, pairs);
}
void PmergeMe::insertElementL(itL_pairL& main_chain, itL_pairL_it startIt, itL_pairL_it endIt, itL& element, itL_pairL& pairs) {
	itL_pairL_it insertPos = std::lower_bound(startIt, endIt, element, CustomCompareL);
	main_chain.insert(insertPos, findMatchPairL(pairs, element));
}
void PmergeMe::insertElementIntL(std::list<int>& main_chain, itL startIt, itL endIt, int element) {
    std::list<int>::iterator insertPos = std::lower_bound(startIt, endIt, element);
    main_chain.insert(insertPos, element);
}
itL_pair PmergeMe::findMatchPairL(itL_pairL& pairs, itL& targetPair) {
	itL_pairL_it it = pairs.begin();
	while (it != pairs.end() && it->first != targetPair) {
		it++;
	}
	return *it;
}
void PmergeMe::fillMainChainL(itL_pairL& new_pairs, itL_pairL& pairs) {
	itL_pairL main_chain;
	for (itL_pairL_it it = new_pairs.begin(); it != new_pairs.end(); it++)
		main_chain.push_back(findMatchPairL(pairs, it->first));
	// itL_pairL_it it = new_pairs.begin();
	// std::advance(it, index);
	main_chain.insert(main_chain.begin(), findMatchPairL(pairs, new_pairs.begin()->second));
	
	int i = 2;
	while (true) {
        size_t j = getJacop(i) > new_pairs.size() ? new_pairs.size() : getJacop(i);
		for (; j > getJacop(i - 1); j--) {
			itL_pairL_it it = new_pairs.begin();
			std::advance(it, j - 1);
			itL_pairL_it pairPos = std::lower_bound(main_chain.begin(), main_chain.end(), it->first, CustomCompareL);
			insertElementL(main_chain, main_chain.begin(), pairPos, it->second, pairs);
		}
		if (getJacop(i) > new_pairs.size())
			break;
		i++;
	}
	// if (new_pairs.size() * 2 != pairs.size())
	// 	insertElementL(main_chain, main_chain.begin(), main_chain.end(), (pairs.end() - 1)->first, pairs);
	if (new_pairs.size() * 2 != pairs.size()) {
		std::list<int>::iterator lastElementIt = std::prev(pairs.end())->first;
		insertElementL(main_chain, main_chain.begin(), main_chain.end(), lastElementIt, pairs);
	}
	pairs = main_chain;
}
void PmergeMe::finalChainL(itL_pairL& pairs, std::list<int>& _list) {
    std::list<int> main_chain;

    for (itL_pairL_it it = pairs.begin(); it != pairs.end(); ++it) {
        main_chain.push_back(*(it->first));
    }

    main_chain.push_front(*pairs.begin()->second);

    int i = 2;
    while (true) {
        size_t j = getJacop(i) > pairs.size() ? pairs.size() : getJacop(i);

        // for (; j > getJacop(i - 1); j--) {
		// for (auto it = pairs.begin(); std::distance(it, pairs.end()) >= getJacop(i - 1) && j > getJacop(i - 1); --j) {
        for (itL_pairL_it it = pairs.begin(); j > getJacop(i - 1); --j) {
            --it;
            int element = *(it->second);
            itL pairPos = std::lower_bound(main_chain.begin(), main_chain.end(), element);
            main_chain.insert(pairPos, element);
        }

        if (getJacop(i) > pairs.size()) {
            break;
        }
        i++;
    }

    if (pairs.size() * 2 != _list.size()) {
        main_chain.push_back(*std::prev(_list.end()));
    }

    _list = main_chain;
}

// void PmergeMe::finalChainL(itL_pairL& pairs, std::list<int>& _list) {
// 	std::list<int> main_chain;
//     for (size_t i = 0; i < pairs.size(); i++)
//         main_chain.push_back(*(pairs[i].first));
//     main_chain.insert(main_chain.begin(), *pairs[0].second);

//     int i = 2;
//     while (true) {
//         size_t j = getJacop(i) > pairs.size() ? pairs.size() : getJacop(i);
//         for (; j > getJacop(i - 1); j--) {
//             int element = *pairs[j - 1].second;
//             std::list<int>::iterator pairPos = std::lower_bound(main_chain.begin(), main_chain.end(), element);
//             insertElementIntL(main_chain, main_chain.begin(), pairPos, element);
//         }
// 		if (getJacop(i) > pairs.size())
// 			break;
//         i++;
//     }
    
//     if (pairs.size() * 2 != _list.size())
//         insertElementIntL(main_chain, main_chain.begin(), main_chain.end(), *(_list.end() - 1));
// 	_list = main_chain;
// }
bool PmergeMe::CustomCompareL(const std::pair<itL, itL>& lhs, const itL& rhs) {
    return *(lhs.first) < *rhs;
}
