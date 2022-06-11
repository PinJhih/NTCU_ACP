// Polynomial class definition.
#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <array>
#include <string>

class Polynomial {
   public:
	static const int maxTerms = 100;  // maximum number of terms

	Polynomial();
	Polynomial operator+(const Polynomial &) const;  // addition
	Polynomial operator-(const Polynomial &) const;  // subtraction
	Polynomial operator*(const Polynomial &) const;  // multiplication
	Polynomial &operator=(const Polynomial &);       // assignment
	Polynomial &operator+=(const Polynomial &);
	Polynomial &operator-=(const Polynomial &);
	Polynomial &operator*=(const Polynomial &);
	void enterTerms();
	std::string toString() const;
	int getNumberOfTerms() const;  // user can only retrieve value
	int getTermExponent(int) const;
	int getTermCoefficient(int) const;
	void setCoefficient(int, int);  // set coefficient of a specific term
	~Polynomial();                  // destructor
   private:
	size_t numberOfTerms;
	std::array<int, maxTerms> exponents;          // exponent array
	std::array<int, maxTerms> coefficients;       // coefficients array
	static void polynomialCombine(Polynomial &);  // combine common terms
};

#endif
