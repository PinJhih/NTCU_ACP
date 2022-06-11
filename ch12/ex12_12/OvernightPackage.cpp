// Exercise 11.9 Solution: OvernightPackage.cpp
// Member-function definitions of class OvernightPackage.
#include "OvernightPackage.h"  // OvernightPackage class definition

#include <stdexcept>
using namespace std;

OvernightPackage::OvernightPackage(
	const string &senderName, const string &senderAddress,
	const string &senderCity, const string &senderState, int senderZIP,
	const string &recipientName, const string &recipientAddress,
	const string &recipientCity, const string &recipientState, int recipientZIP,
	double weight, double costPerOunce, double overnightFeePerOunce)
	: Package{senderName,     senderAddress, senderCity,       senderState,
              senderZIP,      recipientName, recipientAddress, recipientCity,
              recipientState, recipientZIP,  weight,           costPerOunce},
	  overnightFeePerOunce{overnightFeePerOunce} {}

void OvernightPackage::setOvernightFeePerOunce(double fee) {
	overnightFeePerOunce = fee;
}

double OvernightPackage::getOvernightFeePerOunce() const {
	return overnightFeePerOunce;
}

double OvernightPackage::calculateCost() const {
	return Package::calculateCost() + overnightFeePerOunce * getWeight();
}
