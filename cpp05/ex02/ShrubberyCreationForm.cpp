
#include "ShrubberyCreationForm.hpp"

// ShrubberyCreationForm::ShrubberyCreationForm ( void )
// {
// 	std::cout	<< Green << "ShrubberyCreationForm" << ", "
// 				<< Reset << "Default constructor called" << std::endl;
// }

ShrubberyCreationForm::ShrubberyCreationForm ( std::string target )
: Form("shrubbery", 147, 137), _target ( target ) {
	std::cout	<< Green << "ShrubberyCreationForm" << ", "
				<< Reset << "Default constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm () {
	std::cout	<< Red << "ShrubberyCreationForm" << ", "
				<< Reset << "Default destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm ( const ShrubberyCreationForm &form )
: Form(form), _target ( form._target ) {
	std::cout	<< Yellow << "ShrubberyCreationForm" << ", "
				<< Reset << "Copy constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator= ( const ShrubberyCreationForm& form ) {
	std::cout	<< Yellow << "ShrubberyCreationForm" << ", "
				<< Reset << "Copy assignment operator called" << std::endl;
	if (this != &form) {
		Form::operator=(form);
		_target = form.getTarget();
	}
	return *this;
}

std::string ShrubberyCreationForm::getTarget( void ) const	{
	return (_target);
}

void writeTree(const std::string& str, int depth, int length, std::ofstream& outFile) {
    
	if (depth < 0) {
        return;
    }
	// std::cout << "str: " << str[length - depth] << ", depth: " << depth << std::endl;
    std::string indentation(2 * (depth - 1), ' ');
    outFile << indentation << ' ';

	for (int i = 0; i < length - depth + 1; i++) {
		outFile << str[length - depth] << "   ";
	}
	outFile << std::endl;

    outFile << indentation;
	if (depth == 1)
		return ;
	for (int i = 0; i < length - depth + 1; i++) {
		outFile << "/ \\ ";
	}
	outFile << std::endl;

    writeTree(str, depth - 1, length, outFile);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {

	if (!isSigned())
		throw UnSigned();
	handleInvalidGrade(getSignGrade() - executor.getGrade() + 1);

	std::string fileName = getTarget() + "_shrubbery";

	std::ofstream outFile(fileName);

	writeTree(getTarget(), getTarget().length(), getTarget().length(), outFile);
    outFile.close();
}
