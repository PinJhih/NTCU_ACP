// Member-function definitions of class BasePlusCommissionEmployee
// using composition.
#include <iostream>
#include <stdexcept>

// BasePlusCommissionEmployee class definition
#include "BasePlusCommissionEmployee.h"
using namespace std;

BasePlusCommissionEmployee::BasePlusCommissionEmployee(
	const string &firstName, const string &lastName,
	const string &socialSecurityNumber, double grossSales,
	double commissionRate, double baseSalary)
	: commissionEmployee{firstName, lastName, socialSecurityNumber, grossSales,
                         commissionRate},
	  baseSalary{baseSalary} {}

void BasePlusCommissionEmployee::setFirstName(const string &firstName) {
	commissionEmployee.setFirstName(firstName);
}

string BasePlusCommissionEmployee::getFirstName() const {
	return commissionEmployee.getFirstName();
}

void BasePlusCommissionEmployee::setLastName(const string &lastName) {
	commissionEmployee.setLastName(lastName);
}

string BasePlusCommissionEmployee::getLastName() const {
	return commissionEmployee.getLastName();
}

void BasePlusCommissionEmployee::setSocialSecurityNumber(const string &num) {
	commissionEmployee.setSocialSecurityNumber(num);
}

string BasePlusCommissionEmployee::getSocialSecurityNumber() const {
	return commissionEmployee.getSocialSecurityNumber();
}

void BasePlusCommissionEmployee::setGrossSales(double sales) {
	commissionEmployee.setGrossSales(sales);
}

double BasePlusCommissionEmployee::getGrossSales() const {
	return commissionEmployee.getGrossSales();
}

void BasePlusCommissionEmployee::setCommissionRate(double rate) {
	commissionEmployee.setCommissionRate(rate);
}

double BasePlusCommissionEmployee::getCommissionRate() const {
	return commissionEmployee.getCommissionRate();
}

void BasePlusCommissionEmployee::setBaseSalary(double salary) {
	baseSalary = salary;
}

double BasePlusCommissionEmployee::getBaseSalary() const {
	return baseSalary;
}

double BasePlusCommissionEmployee::earnings() const {
	return getBaseSalary() + commissionEmployee.earnings();
}

void BasePlusCommissionEmployee::print() const {
	cout << "base-salaried ";
	commissionEmployee.print();
	cout << "\nbase salary: " << getBaseSalary();
}
