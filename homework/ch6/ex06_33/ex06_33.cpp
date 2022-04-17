#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

bool tossCoin() {
	int x = rand();
	return (x % 2);
}

int main() {
	srand(time(NULL));
	int countHead = 0, countTail = 0;

	for (int i = 0; i != 100; i++) {
		if (tossCoin()) {
			countHead++;
			cout << "Heads ";
		} else {
			countTail++;
			cout << "Tails ";
		}
		if ((i + 1) % 10 == 0)
			cout << endl;
	}
	cout << "\nThe total number of Heads was " << countHead << endl;
	cout << "The total number of Tails was " << countTail << endl;
}
