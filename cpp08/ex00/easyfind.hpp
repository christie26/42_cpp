
#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>

class ValueNotFoundException : public std::exception {
public:
    const char* what() const throw ();
};


template <typename T>
typename T::size_type easyfind(T& container, int targetValue) {
    typename T::iterator it = std::find(container.begin(), container.end(), targetValue);

    if (it != container.end()) {
        std::cout << "Element " << targetValue << " found at position: ";
        std::cout << std::distance(container.begin(), it) << " (counting from zero) \n";
        return std::distance(container.begin(), it);
    } else {
        throw ValueNotFoundException();
    }
}

#endif
