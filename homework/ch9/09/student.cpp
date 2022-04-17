#include "student.h"

Student::Student(Name fullName, std::string sex, std::string registrationNumber,
                 std::string email, Date birthday)
	: fullName{fullName},
	  sex{sex},
	  birthday{birthday},
	  registrationNumber{registrationNumber},
	  email{email} {}

std::string Student::getName() {
	std::string name = "";
	name += fullName.getLastName() + ", ";
	name += fullName.getFirstName() + " ";
	name += fullName.getMiddleName();
	return name;
}

std::string Student::getFirstName() {
	return fullName.getFirstName();
}

std::string Student::getMiddleName() {
	return fullName.getMiddleName();
}

std::string Student::getLastName() {
	return fullName.getLastName();
}

std::string Student::getSex() {
	return sex;
}

std::string Student::getBirthday() {
	return birthday.toString();
}

std::string Student::getRegistrationNumber() {
	return registrationNumber;
}

std::string Student::getEmail() {
	return email;
}

void Student::setName(Name name) {
	fullName = name;
}

void Student::setFirstName(std::string firstName) {
	fullName.setFirstName(firstName);
}

void Student::setMiddleName(std::string middleName) {
	fullName.setMiddleName(middleName);
}

void Student::setLastName(std::string lastName) {
	fullName.setLastName(lastName);
}

void Student::setSex(std::string sex) {
	this->sex = sex;
}

void Student::setBirthday(Date date) {
	birthday = date;
}

void Student::setRegistrationNumber(std::string registrationNumber) {
	this->registrationNumber = registrationNumber;
}

void Student::setEmail(std::string email) {
	this->email = email;
}
