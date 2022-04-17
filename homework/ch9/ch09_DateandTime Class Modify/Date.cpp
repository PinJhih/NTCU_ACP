// Date.cpp
// Member-function definitions for class Date.
#include "Date.h"  // include definition of class Date

#include <array>
#include <iostream>
#include <stdexcept>
using namespace std;

Date::Date(int m, int d, int y) {
	setDate(m, d, y);  // sets date
}  // end Date constructor

void Date::setDate(int mo, int dy, int yr) {
	setMonth(mo);  // invokes function setMonth
	setDay(dy);    // invokes function setDay
	setYear(yr);   // invokes function setYear
}  // end function setDate

void Date::setDay(int d) {
	if (month == 2 && leapYear() && d <= 29 && d >= 1)
		day = d;
	else if (d <= monthDays() && d >= 1)
		day = d;
	else
		throw invalid_argument("day out of range for current month");
}  // end function setDay

void Date::setMonth(int m) {
	if (m <= 12 && m >= 1)
		month = m;
	else
		throw invalid_argument("month invalid");
}  // end function setMonth

void Date::setYear(int y) {
	if (y >= 2000)
		year = y;
	else
		throw invalid_argument("year invalid");
}  // end function setYear

unsigned int Date::getDay() const {
	return day;
}  // end function getDay

unsigned int Date::getMonth() const {
	return month;
}  // end function getMonth

unsigned int Date::getYear() const {
	return year;
}  // end function getYear

void Date::print() const {
	cout << month << '-' << day << '-' << year << '\n';  // outputs date
}  // end function print

void Date::nextDay() {
	try {
		setDay(getDay() + 1);  // increments day by 1
	} catch (invalid_argument&) {
		setDay(1);

		try {
			setMonth(getMonth() + 1);
		} catch (invalid_argument&) {
			setMonth(1);
			setYear(getYear() + 1);
		}
	}
}  // end function nextDay

bool Date::leapYear() const {
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
		return true;  // is a leap year
	else
		return false;  // is not a leap year
}  // end function leapYear

int Date::monthDays() const {
	const array<int, 12> days = {31, 28, 31, 30, 31, 30,
	                             31, 31, 30, 31, 30, 31};

	return month == 2 && leapYear() ? 29 : days[month - 1];
}  // end function monthDays
