// Polynomial member-function definitions.
#include "Polynomial.h"

#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

Polynomial::Polynomial() : numberOfTerms{0}, exponents{}, coefficients{} {}

Polynomial Polynomial::operator+(const Polynomial& pol) const {
	Polynomial sum = *this;
	sum += pol;
	return sum;
}

Polynomial Polynomial::operator-(const Polynomial& pol) const {
	Polynomial difference = *this;
	difference -= pol;
	return difference;
}

Polynomial Polynomial::operator*(const Polynomial& pol) const {
	Polynomial product;
	for (int i = 0; i != getNumberOfTerms(); i++) {
		for (int j = 0; j != pol.getNumberOfTerms(); j++) {
			int index = product.getNumberOfTerms();
			product.exponents[index] = exponents[i] + pol.exponents[j];
			product.coefficients[index] = coefficients[i] * pol.coefficients[j];
			product.numberOfTerms++;
		}
		polynomialCombine(product);
	}
	return product;
}

Polynomial& Polynomial::operator=(const Polynomial& pol) {
	exponents = pol.exponents;
	coefficients = pol.coefficients;
	numberOfTerms = pol.numberOfTerms;
	return *this;
}

Polynomial& Polynomial::operator+=(const Polynomial& pol) {
	for (int i = 0; i != pol.getNumberOfTerms(); i++) {
		int index = getNumberOfTerms();
		exponents[index] = pol.exponents[i];
		coefficients[index] = pol.coefficients[i];
		numberOfTerms++;
		polynomialCombine(*this);
	}
	return *this;
}

Polynomial& Polynomial::operator-=(const Polynomial& pol) {
	for (int i = 0; i != pol.getNumberOfTerms(); i++) {
		int index = getNumberOfTerms();
		exponents[index] = pol.exponents[i];
		coefficients[index] = -pol.coefficients[i];
		numberOfTerms++;
		polynomialCombine(*this);
	}
	return *this;
}

Polynomial& Polynomial::operator*=(const Polynomial& pol) {
	*this = *this * pol;
	return *this;
}

void Polynomial::enterTerms() {
	exponents.fill(0);
	coefficients.fill(0);
	numberOfTerms = 0;
	cin.clear();

	int exponent, coefficient;
	while (cin >> coefficient) {
		if (coefficient == 0)
			return;
		cin >> exponent;
		exponents[numberOfTerms] = exponent;
		coefficients[numberOfTerms] = coefficient;
		numberOfTerms++;
		polynomialCombine(*this);
	}
}

string Polynomial::toString() const {
	ostringstream polynomial;
	bool firstTerm = true;
	for (int i = 0; i != numberOfTerms; i++) {
		if (coefficients[i] == 0)
			continue;

		if (coefficients[i] < 0) {
			polynomial << "- ";
			if (coefficients[i] != -1)
				polynomial << -coefficients[i];
		} else {
			if (!firstTerm) {
				polynomial << "+ ";
			}
			if (coefficients[i] != 1)
				polynomial << coefficients[i];
		}
		firstTerm = false;

		if (exponents[i] != 0) {
			if (exponents[i] == 1)
				polynomial << "x";
			else
				polynomial << "x^" << exponents[i];
		}
		polynomial << ' ';
	}
	return polynomial.str();
}

int Polynomial::getNumberOfTerms() const {
	return numberOfTerms;
}

int Polynomial::getTermExponent(int index) const {
	return exponents[index];
}

int Polynomial::getTermCoefficient(int index) const {
	return coefficients[index];
}

void Polynomial::setCoefficient(int index, int coefficient) {
	coefficients[index] = coefficient;
}

Polynomial::~Polynomial() {
	cout << "\nPolynomial deleted\n";
}

template <size_t LEN>
void shift(array<int, LEN>& arr, int start) {
	for (int i = start; i != LEN - 1 and arr[i + 1] != 0; i++) {
		arr[i] = arr[i + 1];
	}
}

void swap(int& a, int& b) {
	int t = a;
	a = b;
	b = t;
}

void Polynomial::polynomialCombine(Polynomial& pol) {
	for (int i = pol.numberOfTerms - 1; i != -1; i--) {
		for (int j = i - 1; j != -1; j--) {
			if (pol.exponents[i] == pol.exponents[j]) {
				pol.coefficients[j] += pol.coefficients[i];
				pol.coefficients[i] = 0;
				pol.numberOfTerms--;
				shift(pol.exponents, i);
				shift(pol.coefficients, i);
				break;
			}
		}
	}

	for (int i = 0; i != pol.numberOfTerms; i++) {
		for (int j = 0; j != pol.numberOfTerms - i - 1; j++) {
			if (pol.exponents[j] < pol.exponents[j + 1]) {
				swap(pol.exponents[j], pol.exponents[j + 1]);
				swap(pol.coefficients[j], pol.coefficients[j + 1]);
			}
		}
	}
}
