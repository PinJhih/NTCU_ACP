// Exercise 9.9 Solution: Ex09_09.cpp
#include <iostream>

#include "DateAndTime.h"  // include definitions of class DateAndTime
using namespace std;

int main() {
	const int MAXTICKS = 30;
	DateAndTime d(12, 31, 2004, 23, 59, 57);  // instantiates object d
	                                          // of class DateAndTime

	for (int ticks = 1; ticks <= MAXTICKS; ++ticks) {
		cout << "Universal time: ";
		d.printUniversal();  // invokes function printUniversal
		cout << "Standard  time: ";
		d.printStandard();  // invokes function printStandard
		d.tick();           // invokes function tick
	}                       // end for

	cout << endl;
}  // end main
