
#pragma once 

// double-end queue
#include <vector>
#include <list>
#include <string>
#include <algorithm>

typedef std::vector<int>::iterator					itV;
typedef std::pair<itV, itV>							itV_pair;
typedef std::vector<std::pair<itV, itV> >			itV_pairV;
typedef std::vector<std::pair<itV, itV> >::iterator	itV_pairV_it;

typedef std::list<int>::iterator					itL;
typedef std::pair<itL, itL>							itL_pair;
typedef std::list<std::pair<itL, itL> >				itL_pairL;
typedef std::list<std::pair<itL, itL> >::iterator	itL_pairL_it;
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
	unsigned int		_size;

private: /* common */
	void 	fillContainer(const std::string&);
	void 	printVector();
	void 	printList();
	
private: /* Pvector.cpp */
	double		msVector(std::vector<int>&);
	void		sortPairV(itV_pairV&);
	void		insertElementV(itV_pairV& arr, itV_pairV_it startIt, itV_pairV_it endIt, itV& element, itV_pairV& pairs);
	void		insertElementIntV(std::vector<int>& main_chain, itV startIt, itV endIt, int element);
	itV_pair	findMatchPairV(itV_pairV& pairs, itV& targetPair);
	void		fillMainChainV(itV_pairV& new_pairs, itV_pairV& pairs);
	void		finalChainV(itV_pairV& pairs, std::vector<int>& _vector);
	static bool	CustomCompareV(const std::pair<itV, itV>& lhs, const itV& rhs);

private: /* Plist.cpp */
	double		msList(std::list<int>&);
	void		sortPairL(itL_pairL&);
	void		insertElementL(itL_pairL& arr, itL_pairL_it startIt, itL_pairL_it endIt, itL& element, itL_pairL& pairs);
	void		insertElementIntL(std::list<int>& main_chain, itL startIt, itL endIt, int element);
	itL_pair	findMatchPairL(itL_pairL& pairs, itL& targetPair);
	void		fillMainChainL(itL_pairL& new_pairs, itL_pairL& pairs);
	void		finalChainL(itL_pairL& pairs, std::list<int>& _list);
	static bool	CustomCompareL(const std::pair<itL, itL>& lhs, const itL& rhs);

private: /* utils */
	size_t		getJacop(int n);
	void 		printTime(std::string containerType, double time, int size);

};
