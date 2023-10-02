
#pragma once 

#include "Date.hpp"
#include <fstream>
#include <map>
#include <list>

class Date;
class Parser {

public:
	Parser ();
	~Parser();
private:
	Parser (const Parser&);
	Parser& operator= (const Parser&);

private:
	std::map<Date, float> _datas;
	// std::list<Date> _datas;
	std::ifstream	_fs;

private:
	void 	parseFirstLine();
	void 	parseLine();
	void	parseData(const std::string& line);
	float	stringToFloat(const std::string& str);
public:
	std::map<Date,float> getDatas() const;

};