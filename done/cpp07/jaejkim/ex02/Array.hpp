
#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array {

private:
	T* data;
	unsigned int arraySize;

public:
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
