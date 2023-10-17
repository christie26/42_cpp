
#pragma once 

#include <stack>
#include <string>

class RPN {
public:
	RPN(const std::string&);
	~RPN();
private:
	RPN(const RPN&);
	RPN& operator=(const RPN&);

private:
	std::stack<int>		_stack;
	enum operation {
		plus, 
		minus, 
		multi, 
		div
	};
private:
	bool	isNumber(char c);
	bool	isOperation(char c);
	void	processNumber(int n);
	void	processOperator(int operation);
	void	processing(const std::string& str);

};