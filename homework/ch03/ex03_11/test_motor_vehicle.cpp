#include "motor_vehicle.h"

#include <iostream>

using namespace std;

int main() {
	std::string make, fuelType, color;
	int yearOfManufacture, engineCapacity;
	MotorVehicle myMotorVehicle = {"Triumph Motor", "98", 2020, "Black", 900};
	myMotorVehicle.displayDetails();

	cout << "\nEdit motor vehicle information\n";
	cout << "==============================\n";

	cout << "Make: " << myMotorVehicle.getMake() << " -> ";
	cin >> make;
	myMotorVehicle.setMake(make);

	cout << "Fuel Type: " << myMotorVehicle.getFuelType() << " -> ";
	cin >> fuelType;
	myMotorVehicle.setFuelType(fuelType);

	cout << "Year Of Manufacture: " << myMotorVehicle.getYearOfManufacture()
		 << " -> ";
	cin >> yearOfManufacture;
	myMotorVehicle.setYearOfManufacture(yearOfManufacture);

	cout << "Color: " << myMotorVehicle.getColor() << " -> ";
	cin >> color;
	myMotorVehicle.setColor(color);

	cout << "EngineCapacity: " << myMotorVehicle.getEngineCapacity() << " -> ";
	cin >> engineCapacity;
	myMotorVehicle.setEngineCapacity(engineCapacity);
	cout << "==============================\n\n";

	myMotorVehicle.displayDetails();
	return 0;
}
