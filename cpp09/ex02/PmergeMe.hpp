
#pragma once 

// double-end queue
#include <deque>
#include <vector>
#include <string>
#include <algorithm>

class PmergeMe {
public:
	PmergeMe(const std::string&);
	~PmergeMe();
private:
	PmergeMe(const PmergeMe&);
	PmergeMe& operator=(const PmergeMe&);
private:
	std::deque<int> _deque;
	std::vector<int> _vector;
private:
	void fillContainer(const std::string& str);
	void printBefore() const;

};
