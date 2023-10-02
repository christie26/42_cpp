
#include <iostream>
#include <sstream>
#include <algorithm>
#include "Parser.hpp"
#include "Date.hpp"

Parser::Parser() 
: _fs("/Users/yoonseo/project/circle4/cpp/cpp09/ex00/data.csv"){

	if (!_fs.is_open()) {
		throw std::out_of_range("data.csv: could not open file.");
	}
    
    parseFirstLine();
	parseLine();
}
Parser::~Parser() {}
Parser::Parser (const Parser& copy) : _datas(copy._datas) {}
Parser& Parser::operator= (const Parser& copy) {
	if (this != &copy) {
		this->_datas = copy._datas;
	}
	return *this;
}

void Parser::parseFirstLine() {
	std::string first_line;
	std::getline(_fs, first_line);
	if (first_line != "date,exchange_rate") {
		throw std::out_of_range("data.cvs: first line error.");
	}
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

void Parser::parseData(const std::string& line) {
    size_t pos = line.find(',');
    Date new_date(line.substr(0, pos));

    float ratio = stringToFloat(line.substr(pos + 1, line.length()));

    _datas.insert(std::make_pair(new_date, ratio));

}

float Parser::stringToFloat(const std::string& str) {
    std::istringstream iss(str);
    float result;
    iss >> std::noskipws >> result;

    if (iss.eof() && !iss.fail()) {
        return result;
    } else {
        throw std::invalid_argument("data.csv: invalid float format.");
    }
}

std::map<Date, float> Parser::getDatas () const {
    return _datas;
}
