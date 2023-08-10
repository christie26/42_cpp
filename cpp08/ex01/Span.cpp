
#include "Span.hpp"
#include <iostream>

Span::Span ( unsigned int N )
:N ( N ) {
	std::cout << "Default constructor called" << std::endl;
}

Span::~Span () {
	std::cout << "Default destructor called" << std::endl;
}

Span::Span ( const Span& span ) 
: N ( span.N ), numbers ( span.numbers ) {
	std::cout << "Copy constructor called" << std::endl;
}

Span& Span::operator= ( const Span& span ) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &span) {
		N = span.N;
		numbers = span.numbers;
	}
	return *this;
}

void Span::addNumber ( int n ) {
	try {
		if (numbers.size() == N)
			throw std::invalid_argument("Span class alreay have N integers");
		numbers.push_back(n);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}

void Span::sortVector( void ) {
	
	if (numbers.size() < 2) 
		throw std::invalid_argument("Span has no or one element"); 
	ints_t::iterator num_begin	= numbers.begin();
	ints_t::iterator num_end	= numbers.end();

	std::sort(num_begin, num_end);
}

unsigned int Span::shortestSpan ( void ) {

	sortVector();

	unsigned int shortSpan = std::numeric_limits<unsigned int>::max();

	for (ints_t::iterator it = numbers.begin(); it < numbers.end() - 1; ++it) {
		unsigned int span = *(it + 1) - *it;
		if (span < shortSpan)
			shortSpan = span;
	}

	return (shortSpan);
}

unsigned int Span::longestSpan ( void ) {

	sortVector();

	return (*(numbers.end() - 1) - *numbers.begin());
}