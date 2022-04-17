#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
	std::string firstName, middleName, lastName;
	std::string sex;
	int yearOfBirth;
	std::string registrationNumber, email;

   public:
	Student(std::string, std::string, std::string, std::string, int,
	        std::string, std::string);

	std::string getFirstName();
	std::string getMiddleName();
	std::string getLastName();
	std::string getSex();
	int getYearOfBirth();
	std::string getRegistrationNumber();
	std::string getEmail();

	void setFirstName(std::string);
	void setMiddleName(std::string);
	void setLastName(std::string);
	void setSex(std::string);
	void setYearOfBirth(int);
	void setRegistrationNumber(std::string);
	void setEmail(std::string);
};

#endif
