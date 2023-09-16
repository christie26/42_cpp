
#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>
#include <list>
#include <vector>

/*
By default, if no container class is specified for a particular stack class instantiation, 
the standard container std::deque is used.
*/
template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
public:
    // Canonical Form
    MutantStack() : std::stack<T, Container>() {
        #ifdef LOG
        std::cout << "constructor is called" << std::endl;
        #endif
    }
    MutantStack(const MutantStack& copy) : std::stack<T, Container>(copy) {
        #ifdef LOG
        std::cout << "copy constructor is called" << std::endl;
        #endif
    }
    MutantStack& operator= (const MutantStack& copy) {
        #ifdef LOG
        std::cout << "copy operator is called" << std::endl;
        #endif

        std::stack<T, Container>::operator=(copy);
        return (*this);
    }
    ~MutantStack() {
        #ifdef LOG
        std::cout << "destructor is called" << std::endl;
        #endif
    }

public:
    typedef typename Container::iterator iterator;
    typedef typename Container::const_iterator const_iterator;
    typedef typename Container::reverse_iterator reverse_iterator;
    typedef typename Container::const_reverse_iterator const_reverse_iterator;

    // Iterator 
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
