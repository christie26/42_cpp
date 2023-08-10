
#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

typedef std::vector<int>	ints_t;

class Span {

private:

	unsigned int N;

	std::vector<int> numbers;
	void sortVector( void );

public:
	Span ( unsigned int N );
	~Span ( void );
	Span ( const Span& );
	Span& operator= ( const Span& );
	
	void addNumber ( int n );
	unsigned int shortestSpan ( void );
	unsigned int longestSpan ( void );

};

#endif
