#include <iostream>

#include "name.h"

using namespace std;

int main() {
	Name n1{"John", "von", "Neumann", "Developer"};
	cout << n1.toString() << endl;

	Name n2;

	string firstName, midName, lastName, salutation;
	cout << "Enter new values...\n";
	cout << "First name: ";
	cin >> firstName;
	n2.setFirstName(firstName);
	cout << "Set first name to " << n2.getFirstName() << endl;

	cout << "Middle name: ";
	cin >> midName;
	n2.setMiddleName(midName);
	cout << "Set middle name to " << n2.getMiddleName() << endl;

	cout << "Last name: ";
	cin >> lastName;
	n2.setLastName(lastName);
	cout << "Set last name to " << n2.getLastName() << endl;

	cout << "Salutation: ";
	cin >> salutation;
	n2.setSalutation(salutation);
	cout << "Set salutation to " << n2.getSalutation() << endl;

	cout << n2.toString() << endl;

	return 0;
}
