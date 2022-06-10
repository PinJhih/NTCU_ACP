#include "Person.h"

using namespace std;

Person::Person(int id, int age, string lastName, string firstName)
	: id{id}, age{age} {
	setLastName(lastName);
	setFirstName(firstName);
}

void Person::setId(int id) {
	this->id = id;
}

int Person::getId() const {
	return id;
}

void Person::setLastName(const string &name) {
	int i;
	for (i = 0; i != name.size(); i++) {
		lastName[i] = name[i];
	}
	lastName[i] = '\0';
}

string Person::getLastName() const {
	string name;

	for (int i = 0; lastName[i] != '\0'; i++) {
		name += lastName[i];
	}
	return name;
}

void Person::setFirstName(const string &name) {
	int i;
	for (i = 0; i != name.size(); i++) {
		firstName[i] = name[i];
	}
	firstName[i] = '\0';
}

string Person::getFirstName() const {
	string name;

	for (int i = 0; firstName[i] != '\0'; i++) {
		name += firstName[i];
	}
	return name;
}

void Person::setAge(int age) {
	this->age = age;
}

int Person::getAge() const {
	return age;
}
