#ifndef PERSON_H

#include <string>

class Person {
	char lastName[15];
	char firstName[15];
	int age;
	int id;

   public:
	Person(int = -1, int = 0, std::string = "", std::string = "");

	void setId(int);
	int getId() const;

	void setLastName(const std::string &);
	std::string getLastName() const;

	void setFirstName(const std::string &);
	std::string getFirstName() const;

	void setAge(int);
	int getAge() const;
};

#endif