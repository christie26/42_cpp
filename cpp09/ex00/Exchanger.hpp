
#pragma once 

#include <list>
#include "Parser.hpp"

typedef std::map<Date, float>::const_iterator itm;

class Exchanger {
	
public:
	Exchanger(std::map<Date,float>, const std::string& file_name);
	~Exchanger();
private:
	Exchanger (const Exchanger&);
	Exchanger& operator= (const Exchanger&);

private:
	std::map<Date,float>	_datas;

private:
	float	findClosestDate(const Date& target) const;
	float	stringToValue(std::string& str) const;
	void	processEachLine(std::string& line);
};
