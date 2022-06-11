#include <cmath>
#include <iostream>

using namespace std;

bool isPrime(int x) {
	if (x <= 1)
		return false;
	for (int n = 2; n <= x / 2; n++) {
		if (x % n == 0)
			return false;
	}
	return true;
}

int main() {
	int count = 0;

	cout << "The prime numbers from 1 to 10000 are:\n";
	for (int i = 1; i <= 10000; i++) {
		if (isPrime(i)) {
			cout << '\t' << i;
			count++;
			if (count != 0 and count % 10 == 0)
				cout << endl;
		}
	}
	cout << endl
		 << "Total of " << count << " prime numbers between 1 and 10000.\n";
}
