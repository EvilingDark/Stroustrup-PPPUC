#include "Reading.h"
#include "Header.h"

int day;
int hour;
double temperature;

istream& operator>>(istream& is, Reading& r)
{
	char ch1;
	if (is >> ch1 && ch1 != '(')
	{
		is.unget();
		is.clear(ios_base::failbit);
		return is;
	}
	char ch2;
	int d, h;
	double t;
	is >> d >> h >> t >> ch2;
	if (!is || ch2 != ')')
		error("Плохая запись");
	r.day = d;
	r.hour = h;
	r.temperature = t;
	return is;
}

constexpr int impausible_min = -200;
constexpr int impausible_max = 200;

bool is_valid(const Reading& r)
{
	if (r.day < 1 || 31 < r.day) return false;
	if (r.hour < 0 || 23 < r.hour) return false;
	if (r.temperature < impausible_min || impausible_max < r.temperature)
		return false;
	return true;
}
