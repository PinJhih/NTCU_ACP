#ifndef DATE_H
#define DATE_H

class Date {
	int month, day, year;

   public:
	Date(int, int, int);

	void setMonth(int);
	void setDay(int);
	void setYear(int);

	int getMonth() const;
	int getDay() const;
	int getYear() const;

    void displayDetails();
};

#endif
