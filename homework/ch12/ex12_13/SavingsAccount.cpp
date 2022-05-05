// Member-function definitions for class SavingsAccount.
#include "SavingsAccount.h"  // SavingsAccount class definition

#include <stdexcept>

using namespace std;

SavingsAccount::SavingsAccount(double balance, double interestRate)
	: Account{balance}, interestRate{interestRate} {}

double SavingsAccount::calculateInterest() {
	return getBalance() * interestRate;
}
