#include <cmath>
#include <iostream>

using namespace std;

int sumOfDigits(int x) {
	int sum = 0;
	while (x != 0) {
		sum += x % 10;
		x /= 10;
	}
	return sum;
}

bool isDudeney(int x) {
	if (cbrt(x) == sumOfDigits(x))
		return true;
	return false;
}

int main() {
	cout << "First 3 Dudeney numbers:\n";

	for (int count = 0, n = 0; count != 3; n++) {
		if (isDudeney(n)) {
			cout << n << endl;
			count++;
		}
	}
}
