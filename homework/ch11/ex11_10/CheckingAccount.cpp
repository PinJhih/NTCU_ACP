// Member-function definitions for class CheckingAccount.
#include "CheckingAccount.h"  // CheckingAccount class definition

#include <iostream>
#include <stdexcept>
using namespace std;

CheckingAccount::CheckingAccount(double balance, double transactionFee)
	: Account{balance}, transactionFee(transactionFee) {}

void CheckingAccount::credit(double amount) {
	Account::credit(amount);
	chargeFee();
}  // redefined credit function

bool CheckingAccount::debit(double amount) {
	if (amount + transactionFee > getBalance()) {
		return false;
	}
	Account::debit(amount);
	chargeFee();
	return true;
}  // redefined debit function

// utility function to charge fee
void CheckingAccount::chargeFee() {
	setBalance(getBalance() - transactionFee);
}
