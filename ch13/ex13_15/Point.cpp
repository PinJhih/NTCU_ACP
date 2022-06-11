#include "Point.h"

ostream &operator<<(ostream &out, const Point &p) {
	out << "(" << p.xCoordinate << ", " << p.yCoordinate << ")";
	return out;
}

istream &operator>>(istream &in, Point &p) {
	in.ignore();
	in >> p.xCoordinate;
	in.ignore();
	in >> p.yCoordinate;
	in.ignore();
	return in;
}
