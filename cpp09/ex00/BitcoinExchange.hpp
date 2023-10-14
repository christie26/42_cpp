
#pragma once 

#include "Date.hpp"
#include <fstream>
#include <map>
#include <list>

typedef std::map<Date, float>::const_iterator itm;

class BitcoinExchange {

public:
	BitcoinExchange (const std::string& file_name);
	~BitcoinExchange();
private:
	BitcoinExchange (const BitcoinExchange&);
	BitcoinExchange& operator= (const BitcoinExchange&);

private: /* member variable */
	std::ifstream			_fs;
	std::map<Date, float>	_datas;

private: /* parsing.cpp */
	void	parseCenter();
	void 	parseFirstLine();
	void 	parseLine();
	void	parseData(const std::string& line);
	float	stringToFloat(const std::string& str);

private: /* processing */
	void	processCenter(std::map<Date,float>, const std::string& file_name);
	float	findClosestDate(const Date& target) const;
	float	stringToValue(std::string& str) const;
	void	processEachLine(std::string& line);
};
