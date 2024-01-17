
#ifndef ITER_HPP
#define ITER_HPP

template <typename T1, typename T2>
//  void (*func)(T&)
void iter(T1 array[], int size, T2* func){
	for (int i = 0; i < size; i++)
		(*func)(array[i]);
}
// as put reference, we can change the value. 

#endif
