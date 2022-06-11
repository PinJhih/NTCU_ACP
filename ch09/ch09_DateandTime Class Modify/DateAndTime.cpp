// DateAndTime.cpp
// Member function definitions for class DateAndTime.
#include "DateAndTime.h"  // include definition of class DateAndTime

#include <array>
#include <iostream>
#include <stdexcept>

using namespace std;

DateAndTime::DateAndTime(int m, int d, int y, int hr, int min, int sec) {
	setDate(m, d, y);       // sets date
	setTime(hr, min, sec);  // sets time
}  // end DateAndTime constructor

void DateAndTime::setDate(int mo, int dy, int yr) {
	date.setDate(mo, dy, yr);
}  // end function setDate

void DateAndTime::setDay(int d) {
	date.setDay(d);
}  // end function setDay

void DateAndTime::setMonth(int m) {
	date.setMonth(m);
}  // end function setMonth

void DateAndTime::setYear(int y) {
	date.setYear(y);
}  // end function setYear

void DateAndTime::nextDay() {
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

void DateAndTime::setTime(int hr, int min, int sec) {
	time.setTime(hr, min, sec);
}  // end function setTime

void DateAndTime::setHour(int h) {
	time.setHour(h);
}  // end function setHour

void DateAndTime::setMinute(int m) {
	time.setMinute(m);
}  // end function setMinute

void DateAndTime::setSecond(int s) {
	time.setSecond(s);
}  // end function setSecond

void DateAndTime::tick() {
	int tempSecond = getSecond();

	if (tempSecond < 59)
		setSecond(tempSecond + 1);  // increment second by 1
	else {
		setSecond(0);
		int tempMinute = getMinute();

		if (tempMinute < 59)
			setMinute(tempMinute + 1);
		else {
			setMinute(0);
			int tempHour = getHour();

			if (tempHour < 23)
				setHour(tempHour + 1);
			else {
				setHour(0);
				nextDay();
			}
		}  // end else
	}      // end else
}  // end function tick

unsigned int DateAndTime::getDay() const {
	return date.getDay();
}  // end function getDay

unsigned int DateAndTime::getMonth() const {
	return date.getMonth();
}  // end function getMonth

unsigned int DateAndTime::getYear() const {
	return date.getYear();
}  // end function getYear

unsigned int DateAndTime::getHour() const {
	return time.getHour();
}  // end function getHour

unsigned int DateAndTime::getMinute() const {
	return time.getMinute();
}  // end function getMinute

unsigned int DateAndTime::getSecond() const {
	return time.getSecond();
}  // end function getSecond

void DateAndTime::printStandard() const {
	time.printStandard();
	cout << " ";
	date.print();
}  // end function printStandard

void DateAndTime::printUniversal() const {
	time.printUniversal();
	cout << " ";
	date.print();
}  // end function printUniversal
