
#include <iostream>
#include <string>

#define Black "\033[1;30m"
#define Red "\033[1;31m"
#define Green "\033[1;32m"
#define Yellow "\033[1;33m"
#define Blue "\033[1;34m"
#define Magenta "\033[1;35m"
#define Cyan "\033[1;36m"
#define White "\033[1;37m"
#define Reset "\033[1;0m"

void printConstructor(std::string className);

void printDestructor(std::string className);

void printCopyConstructor(std::string className);

void printCopyAssignmentOperator(std::string className);