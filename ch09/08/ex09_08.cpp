#include <iostream>

#include "student.h"

using namespace std;

void printStudent(Student &s) {
	cout << "====================\n";
	cout << "Student information:\n";

	cout << "Name: ";
	cout << s.getFirstName() + ' ';
	cout << s.getMiddleName() + ' ';
	cout << s.getLastName() << endl;

	cout << "Sex: " << s.getSex() << endl;
	cout << "Year of birth: " << s.getYearOfBirth() << endl;
	cout << "Registration number: " << s.getRegistrationNumber() << endl;
	cout << "Email: " << s.getEmail() << endl;

	cout << "====================\n\n";
}

int main() {
	Student s1{"John",
	           "von",
	           "Neumann",
	           "Male",
	           1903,
	           "ACS110000",
	           "ACS110000@example.com"};
	printStudent(s1);

	Student s2{"", "", "", "", 0, "", ""};
	cout << "Edit new student infomation...\n";

	string buffer;
	int year;

	cout << "First name: ";
	cin >> buffer;
	s2.setFirstName(buffer);
	cout << "Middle name: ";
	cin >> buffer;
	s2.setMiddleName(buffer);
	cout << "Last name: ";
	cin >> buffer;
	s2.setLastName(buffer);

	cout << "Sex: ";
	cin >> buffer;
	s2.setSex(buffer);
	cout << "Year of birth: ";
	cin >> year;
	s2.setYearOfBirth(year);

	cout << "Registration number: ";
	cin >> buffer;
	s2.setRegistrationNumber(buffer);
	cout << "Email: ";
	cin >> buffer;
	s2.setEmail(buffer);

	printStudent(s2);

	return 0;
}
