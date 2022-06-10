#include "Hardware.h"

using namespace std;

Hardware::Hardware(int partNumber, const string& name, int quantity, float price)
	: partNumber{partNumber}, quantity{quantity}, price{price} {
	setName(name);
}

void Hardware::setPartNumber(int number) {
	partNumber = number;
}

int Hardware::getPartNumber() const {
	return partNumber;
}

void Hardware::setName(string name) {
	int i;
	for (i = 0; i != name.length() and i != 19; i++) {
		toolName[i] = name[i];
	}
	toolName[i] = '\0';
}

string Hardware::getName() const {
	string name;
	for (int i = 0; toolName[i] != '\0'; i++) {
		name += toolName[i];
	}
	return name;
}

void Hardware::setQuantity(int q) {
	quantity = q;
}

int Hardware::getQuantity() const {
	return quantity;
}

void Hardware::setPrice(float p) {
	price = p;
}

float Hardware::getPrice() const {
	return price;
}
