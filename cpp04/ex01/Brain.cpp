
#include "Brain.hpp"
#include "PrintColor.hpp"

Brain::Brain () {
	printConstructor("Brain");
}

Brain::~Brain () {
	printDestructor("Brain");
}

Brain::Brain (Brain &brain) {
	printCopyConstructor("Brain");
	std::memcpy(this->_ideas, brain._ideas, sizeof(this->_ideas));
// We can't use a line below with array
	// this->_ideas = brain._ideas;
}

Brain& Brain::operator= (const Brain& brain) {
	printCopyAssignmentOperator("Brain");
	if (this != &brain)
		std::memcpy(this->_ideas, brain._ideas, sizeof(this->_ideas));
	return *this;
}

std::string Brain::getIdea(int index) {
	// if (_ideas[index])
		return (_ideas[index]);
}

void Brain::setIdea(int index, std::string idea) {
	_ideas[index] = idea;
}