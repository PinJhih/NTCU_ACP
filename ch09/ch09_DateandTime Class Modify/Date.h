// Date.h
#ifndef DATE_H
#define DATE_H

class Date {
   public:
	explicit Date(int = 1, int = 1, int = 2000);  // default constructor
	void print() const;                           // print function
	void setDate(int, int, int);                  // set month, day, year
	void setMonth(int);                           // set month
	void setDay(int);                             // set day
	void setYear(int);                            // set year
	unsigned int getMonth() const;                // get month
	unsigned int getDay() const;                  // get day
	unsigned int getYear() const;                 // get year
	void nextDay();                               // next day
   private:
	unsigned int month;
	unsigned int day;
	unsigned int year;
	bool leapYear() const;  // leap year
	int monthDays() const;  // days in month
};                          // end class Date

#endif
