#include "Package.h"

using namespace std;

Package::Package(const string &senderName, const string &senderAddress,
                 const string &senderCity, const string &senderState,
                 int senderZIP, const string &recipientName,
                 const string &recipientAddress, const string &recipientCity,
                 const string &recipientState, int recipientZIP, double weight,
                 double costPerOunce)
	: senderName{senderName},
	  senderAddress{senderAddress},
	  senderCity{senderCity},
	  senderState{senderState},
	  senderZIP{senderZIP},
	  recipientName{recipientName},
	  recipientAddress{recipientAddress},
	  recipientCity{recipientCity},
	  recipientState{recipientState},
	  recipientZIP{recipientZIP},
	  weight{weight},
	  costPerOunce{costPerOunce} {}

void Package::setSenderName(const string &name) {
	senderName = name;
}

string Package::getSenderName() const {
	return senderName;
}

void Package::setSenderAddress(const string &address) {
	senderAddress = address;
}

string Package::getSenderAddress() const {
	return senderAddress;
}

void Package::setSenderCity(const string &city) {
	senderCity = city;
}

string Package::getSenderCity() const {
	return senderCity;
}

void Package::setSenderState(const string &state) {
	senderState = state;
}

string Package::getSenderState() const {
	return senderState;
}

void Package::setSenderZIP(int ZIP) {
	senderZIP = ZIP;
}

int Package::getSenderZIP() const {
	return senderZIP;
}

void Package::setRecipientName(const string &name) {
	recipientName = name;
}

string Package::getRecipientName() const {
	return recipientName;
}

void Package::setRecipientAddress(const string &address) {
	recipientAddress = address;
}

string Package::getRecipientAddress() const {
	return recipientAddress;
}

void Package::setRecipientCity(const string &city) {
	recipientCity = city;
}

string Package::getRecipientCity() const {
	return recipientCity;
}

void Package::setRecipientState(const string &state) {
	recipientState = state;
}

string Package::getRecipientState() const {
	return recipientState;
}

void Package::setRecipientZIP(int ZIP) {
	recipientZIP = ZIP;
}

int Package::getRecipientZIP() const {
	return recipientZIP;
}

void Package::setWeight(double weight) {
	this->weight = weight;
}

double Package::getWeight() const {
	return weight;
}

void Package::setCostPerOunce(double cost) {
	costPerOunce = cost;
}

double Package::getCostPerOunce() const {
	return costPerOunce;
}

double Package::calculateCost() const {
	return costPerOunce * weight;
}
