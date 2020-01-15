#include "Year.h"
#include <Header.h>

int year;
vector<Month> month{ 12 };

istream& operator>>(istream& is, Year& y)
{
	char ch;
	is >> ch;
	if (ch != '{')
	{
		is.unget();
		is.clear(ios_base::failbit);
		return is;
	}

	string year_maker;
	int yy;
	is >> year_maker >> yy;
	if (!is || year_maker != "year")
		error("�������� ������ Year");
	y.year = yy;
	while (true)
	{
		Month m;
		if (!(is >> m)) break;
		y.month[m.month] = m;
	}
	end_of_loop(is, '}', "������������ ����� Year");
	return is;
}