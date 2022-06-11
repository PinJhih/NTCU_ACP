// Time.h
#ifndef TIME_H
#define TIME_H

class Time {
   public:
	explicit Time(int = 0, int = 0, int = 0);  // default constructor

	// set functions
	void setTime(int, int, int);  // set hour, minute, second
	void setHour(int);            // set hour (after validation)
	void setMinute(int);          // set minute (after validation)
	void setSecond(int);          // set second (after validation)

	// get functions
	unsigned int getHour() const;    // return hour
	unsigned int getMinute() const;  // return minute
	unsigned int getSecond() const;  // return second

	void printUniversal() const;  // output time in universal-time format
	void printStandard() const;   // output time in standard-time format
	void tick();                  // increment one second
   private:
	unsigned int hour;    // 0 - 23 (24-hour clock format)
	unsigned int minute;  // 0 - 59
	unsigned int second;  // 0 - 59
};                        // end class Time

#endif
