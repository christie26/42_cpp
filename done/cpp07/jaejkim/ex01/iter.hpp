
#ifndef ITER_HPP
#define ITER_HPP

template <typename T>
void iter(T array[], int size, void (*func)(T&)){
	for (int i = 0; i < size; i++)
		(*func)(array[i]);
}

template <typename T>
void iter(T array[], int size, void (*func)(T const &)){
	for (int i = 0; i < size; i++)
		(*func)(array[i]);
}

// as put reference, we can change the value. 
// template <typename T>
// void iter(T array[], int size, void (*func)(const T&)){
// 	for (int i = 0; i < size; i++)
// 		(*func)(array[i]);
// }

#endif
