// Polynomial test program.
#include <iostream>

#include "Polynomial.h"
using namespace std;

int main() {
	Polynomial a;
	Polynomial b;

	a.enterTerms();
	b.enterTerms();
	cout << "First polynomial is: " << a.toString();
	cout << "\nSecond polynomial is: " << b.toString() << "\n";

	Polynomial t{a};  // save the original value of a
	Polynomial c{a + b};
	cout << "\nc = a + b yields: " << c.toString();

	a += b;
	cout << "\n\na += b yields: " << a.toString();

	a = t;  // reset a to original value
	c = a - b;
	cout << "\n\nc = a - b yields: " << c.toString();

	a -= b;
	cout << "\n\na -= b yields: " << a.toString();

	a = t;  // reset a to original value
	c = a * b;
	cout << "\n\nc = a * b yields: " << c.toString();

	a *= b;
	cout << "\n\na *= b the polynomials yields: " << a.toString();
	cout << endl;
}
