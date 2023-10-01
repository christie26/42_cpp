
#pragma once 

#include <fstream>
#include <map>
#include <list>

class Parser {

private:
	struct data {
		int		year;
		int		month;
		int		day;
		float	ratio;
    data(const data& other) {
        year = other.year;
        month = other.month;
        day = other.day;
        ratio = other.ratio;
    }
	data& operator=(const data& other) {
        if (this != &other) {
            year = other.year;
            month = other.month;
            day = other.day;
            ratio = other.ratio;
        }
        return *this;
    }
    data() : year(0), month(0), day(0), ratio(0.0f) {}
	};
	std::list<data> _datas;
	// std::map<date, int> _data;
	std::ifstream _fs;

private:
	Parser (const Parser&);
	Parser& operator= (const Parser&);

private:
	void parseLine();
	void parseData(std::string line);

public:
	Parser();
	~Parser();

};