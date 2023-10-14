
#include "BitcoinExchange.hpp"
#include <iostream>
#include <sstream>
#include <algorithm>

BitcoinExchange::BitcoinExchange(const std::string& file_name) 
: fs_data("/Users/yoonsele/project/cpp/cpp09/ex00/data.csv"), fs_input(file_name) {
    parseCenter();
	processCenter(_datas);
}
BitcoinExchange::~BitcoinExchange() {}
BitcoinExchange::BitcoinExchange (const BitcoinExchange&) {}
BitcoinExchange& BitcoinExchange::operator= (const BitcoinExchange& copy) {
	if (this != &copy) {
		this->_datas = copy._datas;
	}
	return *this;
}
void BitcoinExchange::parseCenter() {

	if (!fs_data.is_open()) {
		throw std::out_of_range("data.csv: could not open file.");
	}
	parseFirstLine();
	parseLine();
}
void BitcoinExchange::parseFirstLine() {
	std::string first_line;

	std::getline(fs_data, first_line);
	if (first_line != "date,exchange_rate") {
		throw std::out_of_range("data.cvs: first line error.");
	}
}
void BitcoinExchange::parseLine() {
    std::string line;

    while (true) {
        std::getline(fs_data, line);
        if (!fs_data) {
            break;
        }
        parseData(line);
    }
}
void BitcoinExchange::parseData(const std::string& line) {
    size_t pos = line.find(',');
    Date new_date(line.substr(0, pos));

    float ratio = stringToFloat(line.substr(pos + 1, line.length()));

    _datas.insert(std::make_pair(new_date, ratio));

}
float BitcoinExchange::stringToFloat(const std::string& str) {
    std::istringstream iss(str);
    float result;
    iss >> std::noskipws >> result;

    if (iss.eof() && !iss.fail()) {
        return result;
    } else {
        throw std::invalid_argument("data.csv: invalid float format.");
    }
}

void BitcoinExchange::processCenter(std::map<Date,float>) {
	if (!fs_input.is_open()) {
        throw std::invalid_argument("av[1]: could not open file.");
	}

	std::string first_line;
	std::getline(fs_input, first_line);
	if (first_line != "date | value") {
		throw std::out_of_range("av[1]: first line error.");
 	}

	std::string line;
    while (true) {
        std::getline(fs_input, line);
        if (!fs_input) {
            break;
        }
        processEachLine(line);
    }
}

float BitcoinExchange::findClosestDate(const Date& target) const{

	itm it;
    itm prev;

	for (it = _datas.begin(); it != _datas.end(); it++) {
		if (target < it->first)
            break;
        prev = it;
	}
	return prev->second;
}

float BitcoinExchange::stringToValue(std::string& str) const {

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

void BitcoinExchange::processEachLine(std::string& line) {
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
