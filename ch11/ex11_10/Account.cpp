// Member-function definitions for class Account.
#include "Account.h"  // include definition of class Account

#include <iostream>
#include <stdexcept>
using namespace std;

Account::Account(double balance) {
	setBalance(balance);
}

void Account::credit(double amount) {
	if (amount < 0) {
		throw invalid_argument("\"amount\" can not be negative");
	}
	balance += amount;
}

bool Account::debit(double amount) {
	if (amount > balance) {
		cout << "Debit amount exceeded account balance" << endl;
		return false;
	}
	balance -= amount;
	return true;
}

void Account::setBalance(double balance) {
	if (balance < 0) {
		throw invalid_argument("\"balance\" can not be negative");
	}
	this->balance = balance;
}

double Account::getBalance() {
	return balance;
}
