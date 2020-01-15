#pragma once
#include <Header.h>

enum class Month {
	jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

enum class Day {
	thursday, friday, saturday,
	sunday, monday, tuesday, wednesday
};

class Date
{
public:
	Date(int y, Month m, int d);
	int year() const { return y; }
	Month month() const { return m; }
	int day() const { return d; }
	int from_zero_day() const { return z; }

	void add_day(int n);
	void add_month(int n);
	void add_year(int n);
private:
	int y;
	Month m;
	int d;
	long int z;
};

ostream& operator<<(ostream& os, const Date& d);
bool leapyear(int y);
bool is_date(int y, Month m, int d);
Day day_of_week(const Date& dd);
Date next_workday(const Date& dd);
int week_of_year(const Date& dd);



