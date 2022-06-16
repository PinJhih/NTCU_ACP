#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

#include "Person.h"

using namespace std;

void init() {
	fstream f{"person_info.dat", ios::out | ios::binary};
	for (int i = 0; i != 100; i++) {
		Person p;
		f.seekp(i * sizeof(Person));
		f.write((const char *)(&p), sizeof(Person));
	}

	while (1) {
		int num;
		cout << "Enter a number(0-99, -1 end the input): ";
		cin >> num;
		if (num == -1) {
			break;
		} else if (num >= 0 and num <= 99) {
			string firstName, lastName;
			int age;
			cout << "Enter first name, last name and age: ";
			cin >> firstName >> lastName >> age;
			Person p{num, age, lastName, firstName};
			f.seekp(num * sizeof(Person));
			f.write((const char *)(&p), sizeof(Person));
		}
	}
}

int main() {
	while (1) {
		char cmd;
		cout << "Should the file be initialized (Y or N): ";
		cin >> cmd;

		if (cmd == 'y' or cmd == 'Y') {
			init();
			break;
		} else if (cmd == 'n' or cmd == 'N') {
			break;
		}
	}

	fstream file{"person_info.dat", ios::in | ios::out | ios::binary};

	for (int i = 0; i != 10; i++) {
		int num;
		while (1) {
			cout << "Enter a number(0-99): ";
			cin >> num;
			if (num >= 0 and num <= 99)
				break;
		}

		Person temp;
		file.seekg(num * sizeof(Person));
		file.read((char *)(&temp), sizeof(Person));

		if (temp.getId() == -1) {
			cout << "No info" << endl;
			continue;
		}

		string firstName, lastName;
		int age;
		cout << "Enter first name, last name and age: ";
		cin >> firstName >> lastName >> age;
		Person p{num, age, lastName, firstName};
		file.seekp(num * sizeof(Person));
		file.write((const char *)(&p), sizeof(Person));
	}

	cout << endl;
	file.clear();
	file.seekg(0);
	while (!file.eof()) {
		Person p;
		file.read((char *)(&p), sizeof(Person));
		if (p.getId() == -1)
			continue;
		cout << p.getFirstName() << ' ' << p.getLastName() << ' ' << p.getAge()
			 << endl;
	}
}
