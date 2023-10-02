#include <iostream>
#include <ctime>
#include "Date.hpp"

Date::Date(const std::string& date_str) : date_str(date_str) {
	if (!isValidDate()) {
		throw std::invalid_argument("Invalid date format");
	}
}
Date::~Date() {}
Date::Date(const Date& copy) :date_str(copy.date_str) {}
Date& Date::operator= (const Date& copy) {
	if (this == &copy) {
		date_str = copy.date_str;
	}
	return *this;
}
bool Date::operator<(const Date& other) const {
    struct tm tm_date1, tm_date2;
    tm_date1 = tm_date2 = tm();
    strptime(date_str.c_str(), "%Y-%m-%d", &tm_date1);
    strptime(other.getString().c_str(), "%Y-%m-%d", &tm_date2);

    time_t time1 = mktime(&tm_date1);
    time_t time2 = mktime(&tm_date2);

    if (time1 < time2) {
        return true;
    } else {
        return false;
    }
}

bool Date::isValidDate() const {
	struct tm tm_date;
	if (strptime(date_str.c_str(), "%Y-%m-%d", &tm_date) == nullptr) {
		return false;
	}
	return true;
}

const std::string& Date::getString () const {
	return date_str;
}