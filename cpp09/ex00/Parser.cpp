
#include "Parser.hpp"
#include <iostream>
#include <sstream>
#include <algorithm>

Parser::Parser() {

	_fs.open("/Users/yoonseo/project/circle4/cpp/cpp09/ex00/data.csv");
	// _fs.open("./data.csv");
	if (!_fs.is_open()) {
		throw std::out_of_range("Error: data.csv: could not open file.");
	}

	std::string first_line;
	std::getline(_fs, first_line);
	std::cout << "first_line: " << first_line << std::endl;
	if (first_line != "date,exchange_rate") {
		throw std::out_of_range("Error: data.cvs: file error.");
	}
	parseLine();
}

Parser::~Parser() {}

Parser::Parser (const Parser& copy) {
	// this->_data = copy._data;
	(void)(copy);
}

Parser& Parser::operator= (const Parser& copy) {
	// this->_data = copy._data;
	(void)(copy);
	return *this;
}

void Parser::parseLine() {
    std::string line;

    while (true) {
        std::getline(_fs, line);
        if (!_fs) {
            break;
        }
        
        parseData(line);
    }
}

void Parser::parseData(std::string line) {
    data new_data;
    std::istringstream ss(line);

    char dash;
    ss >> new_data.year >> dash;
    if (ss.fail() || dash != '-') {
        throw std::out_of_range("Error: data.csv: format error.");
    }

	ss >> new_data.month >> dash;
    if (ss.fail() || dash != '-') {
        throw std::out_of_range("Error: data.csv: format error.");
    }

	ss >> new_data.day >> dash;
    if (ss.fail() || dash != ',') {
        throw std::out_of_range("Error: data.csv: format error.");
    }

	ss >> new_data.ratio;
    if (ss.fail() || ss.get() != EOF) {
        throw std::out_of_range("Error: data.csv: format error.");
    }
	_datas.push_back(new_data);
}

/* example of 'data.cvs | head'
date,exchange_rate
2009-01-02,0
2009-01-05,0
*/