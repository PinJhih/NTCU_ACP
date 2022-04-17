#include "name.h"

Name::Name(std::string firstName, std::string middleName, std::string lastName,
           std::string salutation)
	: firstName{firstName},
	  middleName{middleName},
	  lastName{lastName},
	  salutation{salutation} {}

std::string Name::toString() {
	std::string result = salutation + " ";
	result += lastName + ", ";
	result += firstName + " ";
	result += middleName + " ";
	return result;
}

std::string Name::getFirstName() {
	return firstName;
}

std::string Name::getMiddleName() {
	return middleName;
}

std::string Name::getLastName() {
	return lastName;
}

std::string Name::getSalutation() {
	return salutation;
}

void Name::setFirstName(std::string firstName) {
	this->firstName = firstName;
}

void Name::setMiddleName(std::string middleName) {
	this->middleName = middleName;
}

void Name::setLastName(std::string lastName) {
	this->lastName = lastName;
}

void Name::setSalutation(std::string salutation) {
	this->salutation = salutation;
}
