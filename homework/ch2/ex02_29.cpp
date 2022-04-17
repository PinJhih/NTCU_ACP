#include <iostream>

using namespace std;

int area(int l) {
	return l * l * 6;
}

int vol(int l) {
	return l * l * l;
}

int main() {
	cout << "Face length\tSurface area\tVolume\n";
	cout << "of cube(cm)\tof cube(cm^2)\tof cube(cm^3)\n";
	for (int len = 0; len <= 4; len++) {
		cout << len << "\t\t" << area(len)<< "\t\t" << vol(len) << endl;
	}
	return 0;
}
