#include <iostream>
using namespace std;

int main() {
	int miles{0}, cost_per_gallon{0}, avg_miles_per_gallon{0}, tolls_per_day{0};
	cout << "Total miles: ";
	cin >> miles;
	cout << "Cost per gallon: ";
	cin >> cost_per_gallon;
	cout << "Avg miles pre gallon: ";
	cin >> avg_miles_per_gallon;
	cout << "Tolls per day: ";
	cin >> tolls_per_day;

	int cost = miles / avg_miles_per_gallon * cost_per_gallon + tolls_per_day;
	cout << "Cost per day: " << cost << endl;
}
