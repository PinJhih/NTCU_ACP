#include "motor_vehicle.h"

#include <iostream>

std::string MotorVehicle::getMake() const {
	return make;
}

std::string MotorVehicle::getFuelType() const {
	return fuelType;
}

std::string MotorVehicle::getColor() const {
	return color;
}

int MotorVehicle::getYearOfManufacture() const {
	return yearOfManufacture;
}

int MotorVehicle::getEngineCapacity() const {
	return engineCapacity;
}

void MotorVehicle::setMake(std::string make) {
	this->make = make;
}

void MotorVehicle::setFuelType(std::string fuelType) {
	this->fuelType = fuelType;
}

void MotorVehicle::setColor(std::string color) {
	this->color = color;
}

void MotorVehicle::setYearOfManufacture(int yearOfManufacture) {
	this->yearOfManufacture = yearOfManufacture;
}

void MotorVehicle::setEngineCapacity(int engineCapacity) {
	this->engineCapacity = engineCapacity;
}

void MotorVehicle::displayDetails() {
	std::cout << "Make: " << make << std::endl;
	std::cout << "Fuel Type: " << fuelType << std::endl;
	std::cout << "Year Of Manufacture: " << yearOfManufacture << std::endl;
	std::cout << "Color: " << color << std::endl;
	std::cout << "EngineCapacity: " << engineCapacity << std::endl;
}
