// DateAndTime.h
#ifndef DATEANDTIME_H
#define DATEANDTIME_H

#include "Date.h"
#include "Time.h"

class DateAndTime {
   public:
	explicit DateAndTime(int = 1, int = 1, int = 2000, int = 0, int = 0,
	                     int = 0);   // default constructor
	void setDate(int, int, int);     // set month, day, year
	void setMonth(int);              // set month
	void setDay(int);                // set day
	void setYear(int);               // set year
	void nextDay();                  // next day
	void setTime(int, int, int);     // set hour, minute, second
	void setHour(int);               // set hour
	void setMinute(int);             // set minute
	void setSecond(int);             // set second
	void tick();                     // tick function
	unsigned int getMonth() const;   // get month
	unsigned int getDay() const;     // get day
	unsigned int getYear() const;    // get year
	unsigned int getHour() const;    // get hour
	unsigned int getMinute() const;  // get minute
	unsigned int getSecond() const;  // get second
	void printStandard() const;      // print standard time
	void printUniversal() const;     // print universal time
   private:
	Date date;
	Time time;
};  // end class DateAndTime

#endif
