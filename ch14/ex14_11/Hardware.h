#ifndef HARDWARE_H
#define HARDWARE_H

#include <string>

class Hardware {
	int partNumber;
	char toolName[20];
	int quantity;
	float price;

   public:
	Hardware(int = -1, const std::string& = "nan", int = 0, float = 0.f);

	void setPartNumber(int);
	int getPartNumber() const;

	void setName(std::string);
	std::string getName() const;

	void setQuantity(int);
	int getQuantity() const;

	void setPrice(float);
	float getPrice() const;
};

#endif