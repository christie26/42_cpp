
#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array {
private:
    T* data;
    size_t size;

public:
    Array(size_t initialSize);
    ~Array();

    void insert(size_t index, const T& value);
    T& get(size_t index);
};

#include "array.tpp"  // Include the template definitions

#endif // ARRAY_HPP
