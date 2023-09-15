
#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>
#include <list>
#include <vector>

// template <typename T> 
// class MutantStack : public std::stack<T> {

// public:
// 	MutantStack() : std::stack<T>() {};
 
//     typedef typename std::stack<T>::container_type::iterator				iterator;
//     typedef typename std::stack<T>::container_type::const_iterator			const_iterator;
//     typedef typename std::stack<T>::container_type::reverse_iterator		reverse_iterator;
//     typedef typename std::stack<T>::container_type::const_reverse_iterator	const_reverse_iterator;

// 	iterator begin()				{ return std::stack<T>::c.begin(); }
// 	iterator end()					{ return std::stack<T>::c.end(); }
// 	const_iterator begin() const	{ return std::stack<T>::c.begin(); }
// 	const_iterator end() const		{ return std::stack<T>::c.end(); }

// 	reverse_iterator rbegin()				{ return std::stack<T>::c.rbegin(); }
// 	reverse_iterator rend()					{ return std::stack<T>::c.rend(); }
// 	const_reverse_iterator rbegin() const	{ return std::stack<T>::c.rbegin(); }
// 	const_reverse_iterator rend() const		{ return std::stack<T>::c.rend(); }

// // container_type: underlying containter type 
// // it can be deque or vector depend on the way to initialize stack

// // c: the underlying container (protected member object)

// };


template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
public:
    // Define your own iterator types based on the container
    typedef typename Container::iterator iterator;
    typedef typename Container::const_iterator const_iterator;
    typedef typename Container::reverse_iterator reverse_iterator;
    typedef typename Container::const_reverse_iterator const_reverse_iterator;

    // Constructors
    MutantStack() : std::stack<T, Container>() {}
    MutantStack(const Container& c) : std::stack<T, Container>(c) {}

    // Iterator functions
    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }

    const_iterator begin() const { return this->c.begin(); }
    const_iterator end() const { return this->c.end(); }

    reverse_iterator rbegin() { return this->c.rbegin(); }
    reverse_iterator rend() { return this->c.rend(); }

    const_reverse_iterator rbegin() const { return this->c.rbegin(); }
    const_reverse_iterator rend() const { return this->c.rend(); }
};

#endif
