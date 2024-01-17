
#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array {

private:
	unsigned int arraySize;

public:
	T* data;
	Array ();
	Array ( unsigned int n );
	Array ( const Array& array );
	Array<T>& operator= ( const Array& array );
	~Array ();

	T& operator[]( size_t index );
	const T& operator[]( size_t index ) const;

	size_t size ( void ) const;
};

#include "Array.tpp" 

#endif // ARRAY_HPP
