
#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>
#include <iostream>

class ValueNotFoundException : public std::exception {
public:
    const char* what() const throw ();
};

template <typename T>
typename T::size_type easyfind(T& container, int targetValue) {
    typename T::iterator it = std::find(container.begin(), container.end(), targetValue);

    if (it != container.end()) {
        return std::distance(container.begin(), it);
    } else {
        throw ValueNotFoundException();
    }
}

#endif
