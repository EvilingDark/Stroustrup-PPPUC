#include "Date.h"

int y;
Month m;
int d;

void Date::add_day(int n)
{
	d += n;
}

void Date::add_month(int n)
{
	int i = int(m) + n;
	if (i > 12)
	{
		int rem = i % 12;
		++y;
		m = Month(rem);
	}
	else
		m = Month(n);
}

void Date::add_year(int n)
{
	if (m == Month::feb && d == 29 && !leapyear(y + n))
	{
		m = Month::mar;
		d = 1;
	}
	y += n;
}

Date::Date(int yy, Month mm, int dd)
	:y{ yy }, m{ mm }, d{ dd }
{
	try
	{
		if (int(mm) < 0 || int(mm) > 11)
			error("Неверно указан месяц");
		if (dd < 1 || dd>31)
			error("Неверно указан день");
		z = dd - 1;
		for (int i = 0; i < (yy - 1970); ++i)
		{
			int days_of_year = (leapyear(1970 + i)) ? 366 : 365;
			z += days_of_year;
		}
		for (int i = 0; i<int(mm); ++i)
		{
			int days_in_month = 31;
			if(i == int(Month::feb))
				days_in_month = (leapyear(yy)) ? 29 : 28;
			if (i == int(Month::apr) || i == int(Month::jun) || i == int(Month::sep) || i == int(Month::nov))
				days_in_month = 30;
			z += days_in_month;
		}

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

bool is_date(int y, Month m, int d)
{
	if (d <= 0) return false;
	if (m < Month::jan || Month::dec < m) return false;
	int days_in_month = 31;
	switch (m)
	{
	case Month::feb:
		days_in_month = (leapyear(y)) ? 29 : 28;
		break;
	case Month::apr:	case Month::jun:
	case Month::sep:	case Month::nov:
		days_in_month = 30;
		break;
	}
	if (days_in_month < d) return false;
	return true;
}

Day day_of_week(const Date& dd)
{
	return Day(dd.from_zero_day() % 7);
}

Date next_workday(const Date& dd)
{
	Date d = dd;
	if (int(day_of_week(dd)) == 1)
	{
		d.add_day(3);
		return d;
	}
	if (int(day_of_week(dd)) == 2)
	{
		d.add_day(2);
		return d;
	}
	d.add_day(1);
	return d;
}

int week_of_year(const Date& dd)
{
	int sum_day = dd.day();
	for (int i = 0; i<int(dd.month()); ++i)
	{
		int days_in_month = 31;
		if (i == int(Month::feb))
			days_in_month = (leapyear(dd.year())) ? 29 : 28;
		if (i == int(Month::apr) || i == int(Month::jun) || i == int(Month::sep) || i == int(Month::nov))
			days_in_month = 30;
		sum_day += days_in_month;
	}
	if (sum_day % 7 == 0)
		return sum_day / 7;
	return sum_day / 7 + 1;
}
