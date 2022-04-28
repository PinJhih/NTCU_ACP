// Member-function definitions of class TwoDayPackage.
#include "TwoDayPackage.h"  // TwoDayPackage class definition

#include <stdexcept>

using namespace std;

TwoDayPackage::TwoDayPackage(
	const string &senderName, const string &senderAddress,
	const string &senderCity, const string &senderState, int senderZIP,
	const string &recipientName, const string &recipientAddress,
	const string &recipientCity, const string &recipientState, int recipientZIP,
	double weight, double costPerOunce, double flatFee)
	: Package{senderName,     senderAddress, senderCity,       senderState,
              senderZIP,      recipientName, recipientAddress, recipientCity,
              recipientState, recipientZIP,  weight,           costPerOunce},
	  flatFee{flatFee} {}

void TwoDayPackage::setFlatFee(double fee) {
	flatFee = fee;
}

double TwoDayPackage::getFlatFee() const {
	return flatFee;
}

double TwoDayPackage::calculateCost() const {
	return Package::calculateCost() + flatFee * getWeight();
}
