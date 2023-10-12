
#pragma once 

// double-end queue
#include <vector>
#include <list>
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
	std::vector<int>	_vector;
	std::list<int>		_list;
	// unsigned int		_size;

private: /* common */
	void 	fillContainer(const std::string&);
	void 	printVector();
	void 	printList();
	
private: /* Pvector.cpp */
	void	msVector(std::vector<int>&);
	void	sortVectorPair(it_pairV&);
	void	insertElement(it_pairV& arr, it_pair_itV startIt, it_pair_itV endIt, itV& element, it_pairV& pairs);
	void	insertElementInt(std::vector<int>& main_chain, itV startIt, itV endIt, int element);
	itP		findMatchPair(it_pairV& pairs, itV& targetPair);
	void	fillMainChain(it_pairV& new_pairs, it_pairV& pairs);
	void	lastChain(it_pairV& pairs, std::vector<int>& _vector);

private:
	void	msList(std::list<int>&);
	// void	sortPair(it_pairV&);
	// void	insertElement(it_pairV& arr, it_pair_itV startIt, it_pair_itV endIt, itV& element, it_pairV& pairs);
	// void	insertElementInt(std::vector<int>& main_chain, itV startIt, itV endIt, int element);
	// itP		findMatchPair(it_pairV& pairs, itV& targetPair);
	// void	fillMainChain(it_pairV& new_pairs, it_pairV& pairs);
	// void	lastChain(it_pairV& pairs, std::vector<int>& _vector);


private: /* utils */
	size_t		getJacop(int n);
	static bool	CustomCompare(const std::pair<itV, itV>& lhs, const itV& rhs);

};
