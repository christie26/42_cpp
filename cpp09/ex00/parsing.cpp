
#include "BitcoinExchange.hpp"
#include <iostream>
#include <sstream>
#include <algorithm>

void BitcoinExchange::parseCenter() {
    parseFirstLine();
	parseLine();
}
void BitcoinExchange::parseFirstLine() {
	std::string first_line;

	std::getline(_fs, first_line);
	if (first_line != "date,exchange_rate") {
		throw std::out_of_range("data.cvs: first line error.");
	}
}
void BitcoinExchange::parseLine() {
    std::string line;

    while (true) {
        std::getline(_fs, line);
        if (!_fs) {
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