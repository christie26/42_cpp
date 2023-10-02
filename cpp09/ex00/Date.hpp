#pragma once

#include <string>

class Date {
private:
    std::string date_str;

public:
    Date(const std::string& date_str);
	~Date();
	Date(const Date&);
	bool operator<(const Date&) const;
private:
	Date& operator= (const Date&);
public:
    bool isValidDate() const;
    const std::string& getString() const;
};
