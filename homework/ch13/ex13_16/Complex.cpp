#include "Complex.h"

#include <stdexcept>
#include <string>

Complex::Complex() : real{0}, imaginary{0} {}

ostream &operator<<(ostream &out, const Complex &c) {
	out << c.real;
	if (c.imaginary >= 0)
		out << "+";
	out << c.imaginary << "i";
	return out;
}

istream &operator>>(istream &in, Complex &c) {
	char sign, buf;
	int r{0}, im{0};

	in >> r;
	if (in.peek() != '\n') {
		in >> sign;
		if (sign == 'i') {
			if (in.peek() != '\n') {
				in.setstate(ios::badbit);
				return in;
			}
			im = r;
			r = 0;
		} else {
			if (sign == '+' or sign == '-') {
				in >> im;
				if (in.peek() == '\n') {
					in.setstate(ios::badbit);
					return in;
				}
				in >> buf;
				if (buf != 'i') {
					in.setstate(ios::badbit);
					return in;
				}
				im = im * ((sign == '-') ? -1 : 1);
			} else {
				in.setstate(ios::badbit);
				return in;
			}
		}
	} else {
		im = 0;
	}

	c.real = r;
	c.imaginary = im;
	return in;
}
