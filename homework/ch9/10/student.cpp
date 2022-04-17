#include "student.h"

#include <stdexcept>

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

void Student::setFirstName(std::string firstName) {
	if (firstName.empty())
		throw std::invalid_argument("First name can not be empty.");
	else
		fullName.setFirstName(firstName);
}

void Student::setMiddleName(std::string middleName) {
	if (middleName.empty())
		throw std::invalid_argument("Middle name can not be empty.");
	else
		fullName.setMiddleName(middleName);
}

void Student::setLastName(std::string lastName) {
	if (lastName.empty())
		throw std::invalid_argument("Last name can not be empty.");
	else
		fullName.setLastName(lastName);
}

void Student::setSex(std::string sex) {
	this->sex = sex;
}

void Student::setBirthday(Date date) {
	birthday = date;
}

void Student::setRegistrationNumber(std::string registrationNumber) {
	if (registrationNumber.empty())
		throw std::invalid_argument("Registration number can not be empty.");
	else
		this->registrationNumber = registrationNumber;
}

void Student::setEmail(std::string email) {
	if (email.empty())
		throw std::invalid_argument("Email can not be empty.");
	else
		this->email = email;
}
