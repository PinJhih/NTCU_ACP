#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>

#include "Hardware.cpp"

using namespace std;

int main() {
	ofstream file{"hardware_info.dat", ios::out | ios::binary};
	for (int i = 0; i != 10; i++) {
		Hardware c{0};
		file.seekp(i * sizeof(Hardware));
		file.write((char*)(&c), sizeof(Hardware));
	}
	file.close();
}
