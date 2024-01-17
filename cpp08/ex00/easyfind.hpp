
#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>
#include <iostream>

// class ValueNotFoundException : public std::exception {
// public:
//     const char* what() const throw ();
// };
/* easyfind.cpp */
/*
#include "easyfind.hpp"

const char* ValueNotFoundException::what() const throw () { return "Value not found in container"; }
*/

// template <typename T>
// typename T::size_type easyfind(T& container, int targetValue) {
//     typename T::iterator it = std::find(container.begin(), container.end(), targetValue);

//     if (it != container.end()) {
//         return std::distance(container.begin(), it);
//     } else {
//         throw ValueNotFoundException();
//     }
// }

template <typename T>
// typename T::iterator easyfind( T& const container, int targetValue) {
typename T::const_iterator easyfind(const T& container, int targetValue) {
    typename T::const_iterator it = std::find(container.begin(), container.end(), targetValue);

    return it;
}

#endif
