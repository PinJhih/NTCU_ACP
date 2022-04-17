#include <iostream>

#include "date.h"

Date::Date(int month, int day, int year) {
	this->month = month;
	this->day = day;
	this->year = year;
}

void Date::setMonth(int month) {
	if (month >= 1 && month <= 12)
		this->month = month;
}

void Date::setDay(int day) {
	this->day = day;
}

void Date::setYear(int year) {
	this->year = year;
}

int Date::getMonth() const {
	return month;
}

int Date::getDay() const {
	return day;
}

int Date::getYear() const {
	return year;
}

void Date::displayDetails() {
	std::cout << month << '/' << day << '/' << year << std::endl;
}
