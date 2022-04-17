// Time.cpp
// Member-function definitions for class Time.
#include "Time.h"  // include definition of class Time from Time.h

#include <iomanip>
#include <iostream>
#include <stdexcept>
using namespace std;

// Time constructor initializes each data member
Time::Time(int hour, int minute, int second) {
	setTime(hour, minute, second);  // validate and set time
}  // end Time constructor

// set new Time value using universal time
void Time::setTime(int h, int m, int s) {
	setHour(h);    // set private field hour
	setMinute(m);  // set private field minute
	setSecond(s);  // set private field second
}  // end function setTime

// set hour value
void Time::setHour(int h) {
	if (h >= 0 && h < 24)
		hour = h;
	else
		throw invalid_argument("hour must be 0-23");
}  // end function setHour

// set minute value
void Time::setMinute(int m) {
	if (m >= 0 && m < 60)
		minute = m;
	else
		throw invalid_argument("minute must be 0-59");
}  // end function setMinute

// set second value
void Time::setSecond(int s) {
	if (s >= 0 && s < 60)
		second = s;
	else
		throw invalid_argument("second must be 0-59");
}  // end function setSecond

// return hour value
unsigned int Time::getHour() const {
	return hour;
}  // end function getHour

// return minute value
unsigned int Time::getMinute() const {
	return minute;
}  // end function getMinute

// return second value
unsigned int Time::getSecond() const {
	return second;
}  // end function getSecond

// print Time in universal-time format (HH:MM:SS)
void Time::printUniversal() const {
	cout << setfill('0') << setw(2) << getHour() << ":" << setw(2)
		 << getMinute() << ":" << setw(2) << getSecond();
}  // end function printUniversal

// print Time in standard-time format (HH:MM:SS AM or PM)
void Time::printStandard() const {
	cout << ((getHour() == 0 || getHour() == 12) ? 12 : getHour() % 12) << ":"
		 << setfill('0') << setw(2) << getMinute() << ":" << setw(2)
		 << getSecond() << (hour < 12 ? " AM" : " PM");
}  // end function printStandard

// increment one second
void Time::tick() {
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
			else
				setHour(0);
		}  // end else
	}      // end else
}  // end function tick
