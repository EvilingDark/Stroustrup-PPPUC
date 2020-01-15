#include "Date.h"

int y;
Month m;
int d;

void Date::add_day(int n)
{
	d += n;
}

Date::Date(int yy, Month mm, int dd)
	:y{ yy }, m{ mm }, d{ dd }
{
	try
	{
		if (int(mm) < 1 || int(mm) > 12)
			error("Неверно указан месяц");
		if (dd < 1 || dd>31)
			error("Неверно указан день");
	}
	catch (exception& e) {
		cerr << "exception: " << e.what() << endl;
		char c;
		while (cin >> c && c != ';');
		return;
	}
}

ostream& operator<<(ostream& os, const Date& d)
{
	return os << '(' << d.year()
		<< ',' << int(d.month())
		<< ',' << d.day() << ')';
}

bool leapyear(int y)
{
	if (y % 4 != 0)
		return false;
	return true;
}

/*Date next_workday(const Date& dd)
{

}*/
