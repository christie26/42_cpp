
#pragma once 

// double-end queue
#include <deque>
#include <vector>
#include <string>
#include <algorithm>

typedef std::vector<int>::iterator					itV;
typedef std::pair<itV, itV>							itP;
typedef std::vector<std::pair<itV, itV> >			it_pairV;
typedef std::vector<std::pair<itV, itV> >::iterator	it_pair_itV;
class PmergeMe {
public:
	PmergeMe(const std::string&);
	~PmergeMe();
private:
	PmergeMe(const PmergeMe&);
	PmergeMe& operator=(const PmergeMe&);
private:
	std::deque<int>		_deque;
	std::vector<int>	_vector;
	unsigned int		_size;
private:
	void fillContainer(const std::string&);
	void printBefore();
	void msVector(std::vector<int>&);
	void sortPair(it_pairV&);
	void insertElement(it_pairV& arr, it_pair_itV startIt, it_pair_itV endIt, itV& element, it_pairV& pairs);
	it_pair_itV findMatchPair(it_pairV& pairs, itV targetPair);

};
