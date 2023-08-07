
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>

Base* generate( void ) {

	std::srand(std::time(0));
	int randomNumber = std::rand();
    // std::cout << "Random number : " << randomNumber << std::endl;

	if (randomNumber % 3 == 0) {
		A* a = new A;
		return (a);
	}
	else if (randomNumber % 3 == 1) {
		B* b = new B;
		return (b);
	}
	else {
		C* c = new C;
		return (c);
	}

}

void identify( Base* p ) {

	if (dynamic_cast<A*>(p))
		std::cout << "pointer is point to class A\n";

	else if (dynamic_cast<B*>(p))
		std::cout << "pointer is point to class B\n";

	else if (dynamic_cast<C*>(p))
		std::cout << "pointer is point to class C\n";

	else 
		std::cout << "this is not derived class" << std::endl;

}

void identify( Base& p ) {

	try 
	{
		A &a = dynamic_cast<A&>(p);
		std::cout << "reference is reference of class A\n";
		static_cast<void>(a);
		return ;
	}
  	catch (std::exception&) {}

	try 
	{
		B &b = dynamic_cast<B&>(p);
		std::cout << "reference is reference of class B\n";
		static_cast<void>(b);
		return ;
	}
  	catch (std::exception&) {}

	try {
		C &c = dynamic_cast<C&>(p);
		std::cout << "reference is reference of class C\n";
		static_cast<void>(c);
		return ;
	}
  	catch (std::exception&) {}

	std::cout << "this is not derived class" << std::endl;
}