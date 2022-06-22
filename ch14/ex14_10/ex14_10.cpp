#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

#include "Person.h"

using namespace std;

void init(fstream &f) {
	for (int i = 0; i != 100; i++) {
		Person p;
		f.seekp(i * sizeof(Person));
		f.write((const char *)(&p), sizeof(Person));
	}

	for (int i = 0; i != 10; i++) {
		int id = -1, age;
		string firstName, lastName;
		while (id < 0 or id > 99) {
			cout << "Enter a number(0~99): ";
			cin >> id;
		}
		cout << "Enter firstName and lastName: ";
		cin >> firstName >> lastName;
		cout << "Enter age: ";
		cin >> age;
		Person p(id, age, lastName, firstName);
		f.seekp(id * sizeof(Person));
		f.write((const char *)(&p), sizeof(Person));
	}
}

void del(fstream &f) {
	int id = -1;
	while (id < 0 or id > 99) {
		cout << "Enter a number(0~99): ";
		cin >> id;
	}
	Person p;
	f.seekg(id * sizeof(Person));
	f.read(reinterpret_cast<char *>(&p), sizeof(Person));
	if (p.getId() == -1) {
		cout << "No info." << endl;
	} else {
		p.setId(-1);
		f.seekp(id * sizeof(Person));
		f.write((const char *)(&p), sizeof(Person));
	}
}

void update(fstream &f) {
	int id = -1, age;
	string firstName, lastName;
	while (id < 0 or id > 99) {
		cout << "Enter a number(0~99): ";
		cin >> id;
	}

	Person t;
	f.seekg(id * sizeof(Person));
	f.read(reinterpret_cast<char *>(&t), sizeof(Person));
	if (t.getId() == -1) {
		cout << "No info" << endl;
		return;
	}

	cout << "Enter firstName and lastName: ";
	cin >> firstName >> lastName;
	cout << "Enter age: ";
	cin >> age;
	Person p(id, age, lastName, firstName);
	f.seekp(id * sizeof(Person));
	f.write((const char *)(&p), sizeof(Person));
}

void listAll(fstream &f) {
	f.seekg(0);
	while (!f.eof()) {
		Person p;
		f.read(reinterpret_cast<char *>(&p), sizeof(Person));
		if (p.getId() != -1) {
			cout << p.getFirstName() << ' ' << p.getLastName() << ' '
				 << p.getAge() << endl;
		}
	}
	cout << endl;
}

int main() {
	fstream file{"person_info.dat", ios::in | ios::out | ios::binary};
	init(file);

	while (1) {
		cout << "1 - Delete a record\n"
			 << "2 - Update a record\n"
			 << "3 - List records\n"
			 << "4 - End the program\n";
		int cmd;
		cin >> cmd;
		if (cmd == 4)
			break;

		switch (cmd) {
			case 1:
				del(file);
				break;
			case 2:
				update(file);
				break;
			case 3:
				listAll(file);
		}
		file.clear();
	}
}
