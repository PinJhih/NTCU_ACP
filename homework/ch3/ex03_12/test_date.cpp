#include <iostream>

#include "date.h"

using namespace std;

void editDate(Date &date) {
	int month, day, year;
	cout << "\nEdit date\n";
	cout << "===========\n";

	cout << "Month: " << date.getMonth() << " -> ";
	cin >> month;
	date.setMonth(month);

	cout << "Day: " << date.getDay() << " -> ";
	cin >> day;
	date.setDay(day);

	cout << "Year: " << date.getYear() << " -> ";
	cin >> year;
	date.setYear(year);

	cout << "===========\n";
}

int main() {
	Date date{1, 1, 1};
	date.displayDetails();

	editDate(date);
	date.displayDetails();

	editDate(date);
	date.displayDetails();
	return 0;
}
