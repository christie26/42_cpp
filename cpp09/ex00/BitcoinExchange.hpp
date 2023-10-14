
#pragma once 

#include <fstream>
#include <map>

typedef std::map<std::string, float>::const_iterator itm;

class BitcoinExchange {

public:
	BitcoinExchange (const std::string& file_name);
	~BitcoinExchange();
private:
	BitcoinExchange (const BitcoinExchange&);
	BitcoinExchange& operator= (const BitcoinExchange&);

private: /* member variable */
	std::ifstream					fs_data;
	std::ifstream					fs_input;
	std::map<std::string, float>	_datas;

private: /* parsing */
	void	parseCenter();
	void 	parseFirstLine();
	void 	parseLine();
	void	parseData(const std::string& line);

private: /* processing */
	void	processCenter(std::map<std::string,float>);
	void	processEachLine(std::string& line);
	float	findClosestDate(const std::string&) const;

private: /* utils */
	void	validDateCheck(const std::string& data_str);
	bool	isLeapYear(int year);
	float	stringToFloat(const std::string& str);
	float	stringToValue(const std::string& str) const;

};
