#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

#include "Person.cpp"

using namespace std;

void init() {
	ofstream outPersonFile{"nameage.dat", ios::out | ios::binary};
	if (!outPersonFile) {
		cerr << "File could not be opened." << endl;
		exit(EXIT_FAILURE);
	}

	Person p;
	for (int i = 0; i != 100; i++) {
		outPersonFile.seekp(p.getId() * sizeof(Person));
		outPersonFile.write(reinterpret_cast<const char *>(&p), sizeof(Person));
	}
	outPersonFile.close();
}

void writeNameAge() {
	fstream outF{"nameage.dat", ios::in | ios::out | ios::binary};
	for (int i = 0; i != 10; i++) {
		int id, age;
		string lastName, firstName;
		cin >> id >> age >> firstName >> lastName;
		Person p;
		outF.seekg(id * sizeof(Person));
		outF.read(reinterpret_cast<char *>(&p), sizeof(Person));
		if (p.getId() == 0) {
			cout << "No info" << endl;
			p.setAge(age);
			p.setFirstName(firstName);
			p.setLastName(lastName);
		}
		outF.seekp(id * sizeof(Person));
		outF.write(reinterpret_cast<const char *>(&p), sizeof(Person));
	}
}

void printNameAge() {
	ifstream inPersonFile{"nameage.dat", ios::in | ios::binary};
	if (!inPersonFile) {
		cerr << "File could not be opened." << endl;
		exit(EXIT_FAILURE);
	}

	inPersonFile.seekg(0);
	for (int i = 0; i != 100; i++) {
		Person p;
		// reinterpret_cast<char *> 其實可以用 (char*) 取代
		// 但用 cast 好像是比較安全
		inPersonFile.read(reinterpret_cast<char *>(&p), sizeof(Person));
		if (p.getId() != 0) {
			printPerson(p);
		}
	}
	inPersonFile.close();
}

void printPerson(Person &p) {
	cout << p.getId() << ' ' << p.getAge() << ' ';
	cout << p.getLastName() << endl;
}

int main() {
	init();
	printNameAge();

	return 0;
}
