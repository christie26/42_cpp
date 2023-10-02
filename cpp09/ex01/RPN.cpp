#include "RPN.hpp"
#include <algorithm>
#include <sstream>
#include <iostream>
#include <exception>

RPN::RPN(const std::string& str) {
	try {
		processing(str);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
RPN::~RPN() {}
RPN::RPN(const RPN& copy) : _stack(copy._stack) {}
RPN& RPN::operator=(const RPN& copy) {
	_stack = copy._stack;
	return *this;
}

bool RPN::isNumber(char c) {

	if ('1' <= c && c <= '9')
		processNumber(c - '0');
	else
		return false;
	return true;
}

bool RPN::isOperation(char c) {

	if (c == '+')
		processOperator(plus);
	else if (c == '-')
		processOperator(minus);
	else if (c == '*')
		processOperator(multi);
	else if (c == '/')
		processOperator(div);
	else
		return false;
	return true;
}

void RPN::processNumber(int n) {

	// std::cout << "process number" << std::endl;
	_stack.push(n);
}

void RPN::processOperator(int operation) {

	// std::cout << "process operation" << std::endl;
	if (_stack.size() < 2) {
		throw std::invalid_argument("Error: not enought number in stack.");
	}
	int second = _stack.top();
	_stack.pop();
	int first = _stack.top();
	_stack.pop();
	int result;
	switch(operation) {
		case plus:
			result = first + second;
			break;
		case minus:
			result = first - second;
			break;
		case multi:
			result = first * second;
			break;
		case div:
			result = first / second;
			break;
	}
	_stack.push(result);
}

void RPN::processing(const std::string& str) {

	std::istringstream ss(str);
	std::string token;

	while (std::getline(ss, token, ' ')) {
		if (token.length() != 1) {
			throw std::invalid_argument("Error: token error.");
		}
		if (!isNumber(token[0])) {
			if (!isOperation(token[0])) {
				throw std::invalid_argument("Error: token error.");
			}
		}
	}
	if (_stack.size() != 1)
		throw std::invalid_argument("Error: more than one number left.");
	std::cout << _stack.top() << std::endl;
}
