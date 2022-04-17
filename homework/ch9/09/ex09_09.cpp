#include <iostream>

#include "student.h"

using namespace std;

void printStudent(Student &s) {
	cout << "====================\n";
	cout << "Student information\n";
	cout << "Name: " << s.getName() << endl;
	cout << "Sex: " << s.getSex() << endl;
	cout << "Birth day: " << s.getBirthday() << endl;
	cout << "Registration number: " << s.getRegistrationNumber() << endl;
	cout << "Email: " << s.getEmail() << endl;
	cout << "====================\n\n";
}

int main() {
	Name n1 = {"John", "von", "Neumann"};
	Student s1{n1, "Male", "ACS110000", "ACS110000@example.com"};
	printStudent(s1);

	Student s2 = s1;
	cout << "Edit new student information...\n";

	string buffer;
	unsigned int m, d, y;

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
	cout << "Birthday: ";
	cin >> m >> d >> y;
	Date birth{m, d, y};
	s2.setBirthday(birth);

	cout << "Registration number: ";
	cin >> buffer;
	s2.setRegistrationNumber(buffer);
	cout << "Email: ";
	cin >> buffer;
	s2.setEmail(buffer);

	printStudent(s2);

	return 0;
}
