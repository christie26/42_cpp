
#ifndef ARRAY_TPP
#define ARRAY_TPP

template <typename T>
Array<T>::Array(size_t initialSize) : size(initialSize) {
    data = new T[size];
}

template <typename T>
Array<T>::~Array() {
    delete[] data;
}

template <typename T>
void Array<T>::insert(size_t index, const T& value) {
    if (index < size) {
        data[index] = value;
    }
}

template <typename T>
T& Array<T>::get(size_t index) {
    return data[index];
}

#endif // ARRAY_TPP
