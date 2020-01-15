#include "Month.h"
#include "Reading.h"
#include <Header.h>

int month{ not_a_month };
vector<Day> day{ 32 };

int month_to_int(string s)
{
	for (int i = 0; i < 12; ++i)
		if (month_input_tb1[i] == s)
			return i;
	return -1;
}

string int_to_month(int i)
{
	if (i < 0 || 12 <= i)
		error("Неверный индекс месяца");
	return month_input_tb1[i];
}

istream& operator>>(istream& is, Month& m)
{
	char ch = 0;
	if (is >> ch && ch != '(')
	{
		is.unget();
		is.clear(ios_base::failbit);
		return is;
	}

	string month_maker;
	string mm;
	is >> month_maker >> mm;
	if (!is || month_maker != "month")
		error("Неверное начало Month");
	m.month = month_to_int(mm);

	Reading r;
	int duplicates = 0;
	int invalids = 0;
	for (Reading r; is >> r; )
	{
		if (is_valid(r))
		{
			if (m.day[r.day].hour[r.hour] != not_a_reading)
				++duplicates;
			m.day[r.day].hour[r.hour] = r.temperature;
		}
		else
			++invalids;
	}
	if (invalids)
		error("Неверные данные в Month, всего ", invalids);
	if (duplicates)
		error("Повторяющиеся показания в Month, всего ", duplicates);
	end_of_loop(is, '}', "Неправильный конец Month");
	return is;
}