
#include "Span.hpp"
#include <iostream>

int main()
{
	Span sp = Span(5);

	try {
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		// sp.addNumber(10);
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	unsigned int shortSpan;
	try { 
		shortSpan = sp.shortestSpan(); 
		std::cout << "shortest span: " << shortSpan << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	unsigned int longSpan;
	try { 
		longSpan = sp.longestSpan(); 
		std::cout << "longest span: " << longSpan << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << std::endl;
	return 0;
}
