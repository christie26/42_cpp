
#include "Brain.hpp"
#include "PrintColor.hpp"
#include "Brain.hpp"

Brain::Brain() {
	printConstructor("Brain");
    for (int i = 0; i < 100; ++i) {
        _ideas[i] = "";
    }
}

Brain::~Brain() {
	printDestructor("Brain");
}

Brain::Brain( const Brain &brain ) {
	printCopyConstructor("Brain");
	std::memcpy(this->_ideas, brain._ideas, sizeof(this->_ideas));
}

Brain& Brain::operator=( const Brain& brain ) {
	printCopyAssignmentOperator("Brain");
    if (this != &brain)
    	std::memcpy(this->_ideas, brain._ideas, sizeof(this->_ideas));

    return *this;
}

std::string Brain::getIdea( int index ) {
    if (index >= 0 && index < 100) {
        return _ideas[index];
    }
    return "";
}

void Brain::setIdea( int index, std::string idea ) {
    if (index >= 0 && index < 100) {
        _ideas[index] = idea;
    }
}
