#ifndef STUDENT_H
#define STUDENT_H

#include <string>

#include "Date.h"
#include "name.h"

class Student {
	Name fullName;
	std::string sex;
	Date birthday;
	std::string registrationNumber, email;

   public:
	Student(Name fullName, std::string sex, std::string registrationNumber,
	        std::string email, Date birthday = Date());

	std::string getName();
	std::string getFirstName();
	std::string getMiddleName();
	std::string getLastName();
	std::string getSex();
	std::string getBirthday();
	std::string getRegistrationNumber();
	std::string getEmail();

	void setName(Name);
	void setFirstName(std::string);
	void setMiddleName(std::string);
	void setLastName(std::string);
	void setSex(std::string);
	void setBirthday(Date);
	void setRegistrationNumber(std::string);
	void setEmail(std::string);
};

#endif
