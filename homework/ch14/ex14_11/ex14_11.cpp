#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>

#include "Hardware.cpp"

using namespace std;

void init();
void listAll(fstream&);
void updateRecord(fstream&);
void insertRecord(fstream&);
void deleteRecord(fstream&);

int main() {
	while (1) {
		char cmd;
		cout << "Should the file be initialized (Y or N): ";
		cin >> cmd;

		if (cmd == 'y' or cmd == 'Y') {
			init();
			break;
		} else if (cmd == 'n' or cmd == 'N') {
			break;
		}
	}

	int cmd{0};
	fstream hwFile{"hardware_info.dat", ios::in | ios::out | ios::binary};
	while (cmd != 5) {
		cout << "Enter a choice:\n"
			 << "1 List all tools.\n"
			 << "2 Update record.\n"
			 << "3 Insert record.\n"
			 << "4 Delete record.\n"
			 << "5 End program.\n"
			 << "? ";
		cin >> cmd;
		switch (cmd) {
			case 1:
				listAll(hwFile);
				break;
			case 2:
				updateRecord(hwFile);
				break;
			case 3:
				insertRecord(hwFile);
				break;
			case 4:
				deleteRecord(hwFile);
				break;
		}
	}
}

void clearFile(fstream& file) {
	for (int i = 0; i != 100; i++) {
		Hardware hw;
		file.seekp(i * sizeof(Hardware));
		file.write((char*)(&hw), sizeof(Hardware));
	}
}

void setRecord(fstream& file, int partNumber, Hardware& hw) {
	unsigned long long pos = partNumber * sizeof(Hardware);
	file.clear();
	file.seekp(pos);
	file.write(reinterpret_cast<const char*>(&hw), sizeof(Hardware));
}

Hardware getRecord(fstream& file, int partNumber) {
	unsigned long long pos = partNumber * sizeof(Hardware);
	Hardware hw;
	file.clear();
	file.seekg(pos);
	file.read(reinterpret_cast<char*>(&hw), sizeof(Hardware));
	return hw;
}

void init() {
	fstream file{"hardware_info.dat", ios::out | ios::binary};
	clearFile(file);

	while (1) {
		int number{0}, quantity;
		float price;
		string name;
		cout << "Enter the part number (0 - 99, -1 end input): ";
		cin >> number;
		if (number == -1)
			break;
		else if (number < 0 or number > 99)
			continue;

		cout << "Enter the tool name: ";
		cin.ignore();
		getline(cin, name);

		cout << "Enter quantity and price: ";
		cin >> quantity >> price;

		Hardware hw{number, name, quantity, price};
		setRecord(file, number, hw);
	}

	file.close();
	cout << endl;
}

void printHW(const Hardware& hw) {
	cout << setiosflags(ios::left) << setw(11) << hw.getPartNumber();
	cout << setw(25) << hw.getName();
	cout << setw(12) << hw.getQuantity();
	cout << fixed << setprecision(2) << hw.getPrice() << endl;
	cout << resetiosflags(ios::left);
}

void listAll(fstream& inputFile) {
	cout << "Record#    Tool name                Quantity    Cost" << endl;

	Hardware hw;
	inputFile.clear();
	inputFile.seekg(0, ios::beg);
	inputFile.read(reinterpret_cast<char*>(&hw), sizeof(Hardware));
	bool state = inputFile.eof();
	while (!state) {
		if (hw.getPartNumber() != -1)
			printHW(hw);
		inputFile.read(reinterpret_cast<char*>(&hw), sizeof(Hardware));
		state = inputFile.eof();
	}
	cout << endl;
}

void updateRecord(fstream& outputFile) {
	int number{0}, quantity;
	float price;
	string name;

	cout << "Enter the part number (0 - 99): ";
	cin >> number;
	while (number < 0 or number > 99) {
		cout << "Enter the part number (0 - 99): ";
		cin >> number;
	}

	if (getRecord(outputFile, number).getPartNumber() == -1)
		cout << "No infomation." << endl;
	else {
		cout << "Enter the tool name: ";
		cin.ignore();
		getline(cin, name);

		cout << "Enter quantity and price: ";
		cin >> quantity >> price;

		Hardware hw{number, name, quantity, price};
		setRecord(outputFile, number, hw);
	}
	cout << endl;
}

void insertRecord(fstream& file) {
	int number{0}, quantity;
	float price;
	string name;

	cout << "Enter the part number (0 - 99): ";
	cin >> number;
	while (number < 0 or number > 99) {
		cout << "Enter the part number (0 - 99): ";
		cin >> number;
	}

	cout << "Enter the tool name: ";
	cin.ignore();
	getline(cin, name);

	cout << "Enter quantity and price: ";
	cin >> quantity >> price;

	Hardware hw{number, name, quantity, price};
	setRecord(file, number, hw);
	cout << endl;
}

void deleteRecord(fstream& file) {
	int number{0};
	cout << "Enter the part number (0 - 99): ";
	cin >> number;
	while (number < 0 or number > 99) {
		cout << "Enter the part number (0 - 99): ";
		cin >> number;
	}

	Hardware hw;
	setRecord(file, number, hw);
	cout << endl;
}
