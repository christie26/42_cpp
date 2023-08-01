
#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain {

private:
	std::string _ideas[100];

public:
	Brain( void );
	~Brain( void );
	Brain (Brain &brain);
	Brain& operator= (const Brain& brain);

	std::string getIdea(int index);
	void setIdea(int index, std::string idea);
};

#endif
