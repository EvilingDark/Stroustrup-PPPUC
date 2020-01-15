#pragma once
#include <Header.h>

enum class Month {
	jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

class Date
{
public:
	Date(int y, Month m, int d);
	void add_day(int n);
	int year() const { return y; }
	Month month() const { return m; }
	int day() const { return d; }
private:
	int y;
	Month m;
	int d;
};

ostream& operator<<(ostream& os, const Date& d);
bool leapyear(int y);

