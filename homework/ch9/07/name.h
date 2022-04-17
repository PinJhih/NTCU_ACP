#ifndef NAME_H
#define NAME_H

#include <string>

class Name {
	std::string firstName, middleName, lastName, salutation;

   public:
	Name(std::string = "Unknow", std::string = "Unknow", std::string = "Unknow",
	     std::string = "Unknow");

	std::string toString();
	std::string getFirstName();
	std::string getMiddleName();
	std::string getLastName();
	std::string getSalutation();

	void setFirstName(std::string);
	void setMiddleName(std::string);
	void setLastName(std::string);
	void setSalutation(std::string);
};

#endif
