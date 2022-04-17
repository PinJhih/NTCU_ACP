#include "student.h"

Student::Student(std::string firstName, std::string middleName,
                 std::string lastName, std::string sex, int yearOfBirth,
                 std::string registrationNumber, std::string email)
	: firstName{firstName},
	  middleName{middleName},
	  lastName{lastName},
	  sex{sex},
	  yearOfBirth{yearOfBirth},
	  registrationNumber{registrationNumber},
	  email{email} {}

std::string Student::getFirstName() {
	return firstName;
}

std::string Student::getMiddleName() {
	return middleName;
}

std::string Student::getLastName() {
	return lastName;
}

std::string Student::getSex() {
	return sex;
}

int Student::getYearOfBirth() {
	return yearOfBirth;
}

std::string Student::getRegistrationNumber() {
	return registrationNumber;
}

std::string Student::getEmail() {
	return email;
}

void Student::setFirstName(std::string firstName) {
	this->firstName = firstName;
}

void Student::setMiddleName(std::string middleName) {
	this->middleName = middleName;
}

void Student::setLastName(std::string lastName) {
	this->lastName = lastName;
}

void Student::setSex(std::string sex) {
	this->sex = sex;
}

void Student::setYearOfBirth(int yearOfBirth) {
	this->yearOfBirth = yearOfBirth;
}

void Student::setRegistrationNumber(std::string registrationNumber) {
	this->registrationNumber = registrationNumber;
}

void Student::setEmail(std::string email) {
	this->email = email;
}
