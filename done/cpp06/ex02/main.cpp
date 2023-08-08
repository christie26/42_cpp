
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>

void leak ( void ) {

	system("leaks a.out");
}

int main( void ) {

	Base* base = generate();
	Base base_stack;
	Base* base_heap = new Base;

	identify(base);
	identify(*base);
	std::cout << std::endl;

	identify(&base_stack);
	identify(base_stack);
	std::cout << std::endl;
	
	identify(base_heap);
	identify(*base_heap);
	std::cout << std::endl;
	

	delete base;
	delete base_heap;

	// atexit(&leak);

	return 0;
}