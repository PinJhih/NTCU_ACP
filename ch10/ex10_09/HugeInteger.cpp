// HugeInteger member-function and friend-function definitions.
#include "HugeInteger.h"  // HugeInteger class definition

#include <cctype>  // isdigit function prototype
using namespace std;

// default constructor; conversion constructor that converts
// a long integer into a HugeInteger object
HugeInteger::HugeInteger(long value) {
	// place digits of argument into array
	for (int j{digits - 1}; value != 0 && j >= 0; j--) {
		integer[j] = value % 10;
		value /= 10;
	}
}

// conversion constructor that converts a character string
// representing a large integer into a HugeInteger object
HugeInteger::HugeInteger(const string& number) {
	// place digits of argument into array
	int length{(int)number.size()};

	for (int j{digits - length}, k{0}; j < digits; ++j, ++k) {
		if (isdigit(number[k])) {  // ensure that character is a digit
			integer[j] = number[k] - '0';
		}
	}
}

HugeInteger HugeInteger::operator+(const HugeInteger& num) const {
	HugeInteger sum;
	short carry = 0;
	for (int i = digits - 1; i >= 0; i--) {
		sum.integer[i] = this->integer[i] + num.integer[i] + carry;
		carry = sum.integer[i] / 10;
		sum.integer[i] %= 10;
	}

	return sum;
}

HugeInteger HugeInteger::operator+(int num) const {
	return *this + HugeInteger(num);
}

HugeInteger HugeInteger::operator+(const string& num) const {
	return *this + HugeInteger(num);
}

HugeInteger HugeInteger::operator-(const HugeInteger& num) const {
	HugeInteger difference;
	short carry = 0;
	for (int i = digits - 1; i >= 0; i--) {
		if (integer[i] < num.integer[i]) {
			difference.integer[i] = 10 + integer[i] - num.integer[i] - carry;
			carry = 1;
		} else {
			difference.integer[i] = integer[i] - num.integer[i] - carry;
			carry = 0;
		}
	}
	return difference;
}

HugeInteger HugeInteger::operator-(int num) const {
	return *this - HugeInteger(num);
}

HugeInteger HugeInteger::operator-(const string& num) const {
	return *this - HugeInteger(num);
}

HugeInteger HugeInteger::operator*(const HugeInteger& num) const {
	HugeInteger product;
	int len = digits - 1;

	for (int i = 0; i != digits; i++) {
		int carry = 0;
		for (int j = 0; len - i - j >= 0; j++) {
			int index = len - i - j;
			product.integer[index] += num.integer[len - i] * integer[len - j];
			product.integer[index] += carry;

			carry = product.integer[index] / 10;
			product.integer[index] %= 10;
		}
	}
	return product;
}

HugeInteger HugeInteger::operator*(int num) const {
	return *this * HugeInteger(num);
}

HugeInteger HugeInteger::operator*(const string& num) const {
	return *this * HugeInteger(num);
}

HugeInteger HugeInteger::operator/(const HugeInteger& num) const {
	if (*this < num)
		return 0;

	// 確認兩個數字的位數
	int len = 0, lenNum = 0;
	while (len != digits and integer[len] == 0) {
		len++;
	}
	while (lenNum != digits and num.integer[lenNum] == 0) {
		lenNum++;
	}
	len = digits - len;
	lenNum = digits - lenNum;

	HugeInteger d = *this, result;
	int i = digits - 1 - len + lenNum;  // 商最左位的位置
	for (; i != digits; i++) {
		HugeInteger temp;  // 除數左移的結果
		// 把除數左移 直到除數和被除數位數相同
		for (int j = 0; j != lenNum; j++) {
			temp.integer[i - j] = num.integer[digits - 1 - j];
		}

		// 不斷減去 temp 直到 temp 比 d 大
		while (temp <= d) {
			d = d - temp;
			result.integer[i]++;  // 每減一次就在商的第 i 位加一
		}
	}
	return result;
}

HugeInteger HugeInteger::operator/(int num) const {
	return *this / HugeInteger(num);
}

HugeInteger HugeInteger::operator/(const std::string& num) const {
	return *this / HugeInteger(num);
}

bool HugeInteger::operator==(const HugeInteger& num) const {
	auto operation = [](short a, short b) { return a == b; };
	return cmp(num, operation);
}

bool HugeInteger::operator==(int num) const {
	return *this == HugeInteger(num);
}

bool HugeInteger::operator==(const std::string& num) const {
	return *this == HugeInteger(num);
}

bool HugeInteger::operator!=(const HugeInteger& num) const {
	return !((*this) == num);
}

bool HugeInteger::operator!=(int num) const {
	return *this != HugeInteger(num);
}

bool HugeInteger::operator!=(const std::string& num) const {
	return *this != HugeInteger(num);
}

bool HugeInteger::operator>(const HugeInteger& num) const {
	auto operation = [](short a, short b) { return a > b; };
	return cmp(num, operation);
}

bool HugeInteger::operator>(int num) const {
	return *this > HugeInteger(num);
}

bool HugeInteger::operator>(const std::string& num) const {
	return *this > HugeInteger(num);
}

bool HugeInteger::operator>=(const HugeInteger& num) const {
	auto operation = [](short a, short b) { return a >= b; };
	return cmp(num, operation);
}

bool HugeInteger::operator>=(int num) const {
	return *this >= HugeInteger(num);
}

bool HugeInteger::operator>=(const std::string& num) const {
	return *this >= HugeInteger(num);
}

bool HugeInteger::operator<(const HugeInteger& num) const {
	auto operation = [](short a, short b) { return a < b; };
	return cmp(num, operation);
}

bool HugeInteger::operator<(int num) const {
	return *this < HugeInteger(num);
}

bool HugeInteger::operator<(const std::string& num) const {
	return *this < HugeInteger(num);
}

bool HugeInteger::operator<=(const HugeInteger& num) const {
	auto operation = [](short a, short b) { return a <= b; };
	return cmp(num, operation);
}

bool HugeInteger::operator<=(int num) const {
	return *this <= HugeInteger(num);
}

bool HugeInteger::operator<=(const std::string& num) const {
	return *this <= HugeInteger(num);
}

bool HugeInteger::cmp(const HugeInteger& num,
                      std::function<bool(short, short)> operation) const {
	int i = 0;
	for (; i != digits - 1 and integer[i] == num.integer[i]; i++) {
	}

	return operation(integer[i], num.integer[i]);
}

ostream& operator<<(ostream& output, const HugeInteger& num) {
	int i;
	for (i = 0; (i < HugeInteger::digits) && (0 == num.integer[i]); ++i) {
	}

	if (i == HugeInteger::digits) {
		output << 0;
	} else {
		for (; i < HugeInteger::digits; ++i) {
			output << num.integer[i];
		}
	}
	return output;
}
