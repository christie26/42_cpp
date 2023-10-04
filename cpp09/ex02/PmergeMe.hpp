
#pragma once 

// double-end queue
#include <deque>
#include <vector>
#include <string>
#include <algorithm>

typedef std::deque<int>::iterator itD;
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
	void msDeque(std::deque<int>&);
	void sortPair(std::deque<std::pair<itD, itD> >&);
	// void insertElement(itD startIndex, itD endIndex, int element);
	void insertElement(std::deque<int>& arr, int startIndex, int endIndex, int element);
};
