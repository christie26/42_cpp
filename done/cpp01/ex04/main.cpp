
#include "Sed.hpp"

void leak() {
	system("leaks sed");
}

int main(int ac, char **av)
{
	if (ac != 4) {
		std::cout << "Error: put three arguments" << std::endl;
		exit(EXIT_FAILURE);
	}
	
	Sed sed = Sed(av[1], av[2], av[3]);

	std::ifstream ReadFile = sed.getReadFile();
	std::ofstream WriteFile = sed.getWriteFile();
	
	sed.copyRoutine(ReadFile, WriteFile);

	// atexit(&leak);

	return 0;
}
