
#include "Sed.hpp"

Sed::Sed(std::string filename, std::string s1, std::string s2) 
	: _filename( filename ), _s1 ( s1 ), _s2( s2 ) { }

std::ifstream Sed::getReadFile () {

	std::ifstream ReadFile(this->_filename);
	if (!ReadFile.is_open()) {
    	std::cerr << "Error opening file: " << this->_filename << std::endl;
    	exit(EXIT_FAILURE);
	}
	return (ReadFile);
}

std::ofstream Sed::getWriteFile () {

	std::string new_file = this->_filename + ".replace";

	std::ofstream WriteFile(new_file);
	if (!WriteFile.is_open()) {
    	std::cerr << "Error opening file: " << new_file << std::endl;
    	exit(EXIT_FAILURE);
	}
	return (WriteFile);
}

void Sed::copyRoutine(std::ifstream& ReadFile, std::ofstream& WriteFile) {
	
    std::string buffer;
    size_t len_s1 = this->_s1.length();

    while (std::getline(ReadFile, buffer)) {
        size_t found = buffer.find(this->_s1);
        size_t start = 0;

        while (found != std::string::npos) {
            WriteFile << buffer.substr(start, found - start);
            WriteFile << this->_s2;
            start = found + len_s1;
            found = buffer.find(this->_s1, start);
        }

        WriteFile << buffer.substr(start) << std::endl;
    }
}
