
#include "BitcoinExchange.hpp"
#include <iostream>
#include <sstream>
#include <algorithm>

BitcoinExchange::BitcoinExchange(const std::string& file_name) 
: fs_data("data.csv"), fs_input(file_name) {
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
    if (_datas.size() == 0)
    	throw std::out_of_range("data.cvs: empty.");
}
void BitcoinExchange::parseData(const std::string& line) {
    size_t pos = line.find(',');
    std::string new_date = line.substr(0, pos);
    validDateCheck(new_date);

    float ratio = stringToFloat(line.substr(pos + 1, line.length()));

    _datas.insert(std::make_pair(new_date, ratio));

}

void BitcoinExchange::processCenter(std::map<std::string,float>) {
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

void BitcoinExchange::processEachLine(std::string& line) {
	size_t pos = line.find(' ');
    if (pos == std::string::npos || line.length() - pos < 3) {
        std::cout << "Error: bad input => " << line << std::endl;
        return;
    }

    std::string date_str = line.substr(0, pos);
    std::string format_str = line.substr(pos, 3);
    std::string value_str = line.substr(pos + 3);
    if (format_str != " | ") {
        std::cout << "Error: bad input => " << line << std::endl;
        return ;
    }

    try {
        validDateCheck(date_str);
        float value = stringToValue(value_str);
        float changedValue = value * findClosestDate(date_str);
        std::cout << date_str << " => " << value_str;
        std::cout << " = " << changedValue << std::endl;

    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}
float BitcoinExchange::findClosestDate(const std::string& target) const{

	itm it;
    itm prev;

	for (it = _datas.begin(); it != _datas.end(); it++) {
		if (target < it->first)
            break;
        prev = it;
	}
    if (it == _datas.begin())
        throw std::invalid_argument("Earilest data is before input date.");
	return prev->second;
}

void BitcoinExchange::validDateCheck(const std::string& date_str) {
    std::stringstream ss(date_str);
    int year, month, day;
    char dash1, dash2;

    if (!(ss >> year >> dash1 >> month >> dash2 >> day) || 
        dash1 != '-' || dash2 != '-' || 
        year < 1900 || month < 1 || month > 12 || day < 1 || day > 31) {
        throw std::invalid_argument("Invalid date format");
    }
    if (!ss.eof() || ss.fail()) {
        throw std::invalid_argument("invalid date format");
    }
    if (month == 2) {
        if (isLeapYear(year) && day > 29)
            throw std::invalid_argument("invalid date format");
        else if (!isLeapYear(year) && day > 28)
            throw std::invalid_argument("invalid date format");
    }
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        throw std::invalid_argument("invalid date format");
}

bool BitcoinExchange::isLeapYear(int year) {
    if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return true;
    return false;
}
float BitcoinExchange::stringToFloat(const std::string& str) {
    std::istringstream iss(str);
    float result;
    iss >> std::noskipws >> result;

    if (!iss.eof() || iss.fail()) {
        throw std::invalid_argument("invalid float format");
    } else {
        return result;
    }
}
float BitcoinExchange::stringToValue(const std::string& str) const {

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
