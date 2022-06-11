#include <iostream>

using namespace std;

int main() {
	int num;
	cin >> num;
	for (int i=0; i!=4; i++) {
		cout << num % 10 << "  ";
		num /= 10;
	}
	cout << endl;

	return 0;
}
