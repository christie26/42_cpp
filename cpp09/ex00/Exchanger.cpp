
#include "Exchanger.hpp"
#include <iostream>
#include <algorithm>
#include <sstream>

Exchanger::Exchanger(std::map<Date,float> datas, const std::string& file_name) : _datas(datas) {

	std::ifstream fs(file_name);
	if (!fs.is_open()) {
        throw std::invalid_argument("av[1]: could not open file.");
	}

	std::string first_line;
	std::getline(fs, first_line);
	if (first_line != "date | value") {
		throw std::out_of_range("av[1]: first line error.");
 	}

	std::string line;
    while (true) {
        std::getline(fs, line);
        if (!fs) {
            break;
        }
        processEachLine(line);
    }
}
Exchanger::~Exchanger() {}
Exchanger::Exchanger (const Exchanger& copy) : _datas(copy._datas) {}
Exchanger& Exchanger::operator= (const Exchanger& copy) {
	if (this != &copy) {
		this->_datas = copy._datas;
	}
	return *this;
}

float Exchanger::findClosestDate(const Date& target) const{

	itm it;
    itm prev;

	for (it = _datas.begin(); it != _datas.end(); it++) {
		if (target < it->first)
            break;
        prev = it;
	}
	return prev->second;
}

float Exchanger::stringToValue(std::string& str) const {

	std::istringstream iss(str);
    float value;
    iss >> std::noskipws >> value;

    if (!iss.eof() || iss.fail()) {
        throw std::invalid_argument("invalid float format");
    } else if (value < 0) {
        throw std::invalid_argument("not a positive number.");
    } else if (value > 1000) {
        throw std::invalid_argument("too large a number.");
    } else {
		return value;
	}
}

void Exchanger::processEachLine(std::string& line) {
	size_t pos = line.find(' ');

    if (pos == std::string::npos) {
        std::cerr << "Error: bad input => " << line << std::endl;
        return;
    }

    std::string date_str = line.substr(0, pos);
    std::string format_str = line.substr(pos, 3);
    std::string value_str = line.substr(pos + 3);
    if (format_str != " | ") {
        std::cerr << "Error: bad input => " << line << std::endl;
        return ;
    }
    
    try {
        Date date(date_str);
        float value = stringToValue(value_str);
        std::cout << date_str << " => " << value_str;
        std::cout << " = " << (value * findClosestDate(date)) << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
