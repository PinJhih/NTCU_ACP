#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

#include "Person.cpp"

using namespace std;

int main() {
	fstream file{"person_info.dat", ios::in | ios::out | ios::binary};
}
