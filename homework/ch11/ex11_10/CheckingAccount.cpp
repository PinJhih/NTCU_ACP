// Member-function definitions for class CheckingAccount.
#include "CheckingAccount.h"  // CheckingAccount class definition

#include <iostream>
#include <stdexcept>
using namespace std;

CheckingAccount::CheckingAccount(double balance, double transactionFee)
	: Account{balance} {
	if (transactionFee < 0) {
		throw invalid_argument("\"transactionFee\" can not be negative");
	} else {
		this->transactionFee = transactionFee;
	}
}

void CheckingAccount::credit(double amount) {
	Account::credit(amount);
	chargeFee();
}

bool CheckingAccount::debit(double amount) {
	if (amount + transactionFee > getBalance()) {
		cout << "Debit amount exceeded account balance." << endl;
		return false;
	}
	Account::debit(amount);
	chargeFee();
	return true;
}

void CheckingAccount::chargeFee() {
	setBalance(getBalance() - transactionFee);
}
