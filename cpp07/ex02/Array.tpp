
#ifndef ARRAY_TPP
#define ARRAY_TPP

template <typename T>
Array<T>::Array( )  {
	std::cout << "Default constructor called" << std::endl;
}

template <typename T>
Array<T>::Array( unsigned int n ) 
: arraySize(n) {
	std::cout << "Default constructor called" << std::endl;
	data = new T[arraySize];
}

template <typename T>
Array<T>::~Array() {
	std::cout << "Default destructor called" << std::endl;
	delete[] data;
}

template <typename T>
Array<T>::Array ( const Array& array ) 
: arraySize(array.arraySize) {
	std::cout << "Copy constructor called" << std::endl;

	data = new T[arraySize];
	for (size_t i = 0; i < arraySize; ++i)
		data[i] = array.data[i];
}

template <typename T>
Array<T>& Array<T>::operator= ( const Array& array ) {
	std::cout << "Copy assignment operator called" << std::endl;

	if (this != &array) {
		arraySize = array.arraySize;
		data = new T[arraySize];
		for (size_t i = 0; i < arraySize; ++i)
			data[i] = array.data[i];
	}
	return *this;
}

template <typename T>
T& Array<T>::operator[]( size_t index ) {
	if (index >= arraySize) {
		throw std::out_of_range("Index out of range");
	}
	return data[index];
}

template <typename T>
const T& Array<T>::operator[]( size_t index ) const {
	if (index >= arraySize) {
		throw std::out_of_range("Index out of range");
	}
	return data[index];
}

template <typename T>
size_t Array<T>::size( void ) const {
	 return arraySize;
}

#endif // ARRAY_TPP
