#ifndef MOTOR_VEHICLE_H
#define MOTOR_VEHICLE_H

#include <string>

class MotorVehicle {
	std::string make, fuelType, color;
	int yearOfManufacture, engineCapacity;

   public:
	MotorVehicle(std::string make, std::string fuelType, int yearOfManufacture,
	             std::string color, int engineCapacity)
		: make{make},
		  fuelType{fuelType},
		  yearOfManufacture{yearOfManufacture},
		  color{color},
		  engineCapacity{engineCapacity} {}

	std::string getMake() const;
	std::string getFuelType() const;
	std::string getColor() const;
	int getYearOfManufacture() const;
	int getEngineCapacity() const;

	void setMake(std::string);
	void setFuelType(std::string);
	void setColor(std::string);
	void setYearOfManufacture(int);
	void setEngineCapacity(int);

	void displayDetails();
};

#endif
