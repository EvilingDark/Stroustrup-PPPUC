#include "Roman_int.h"
#include <Header.h>

string roman;

bool is_same_ch(const string& s, int i, char ch)
{
	if ((i + 1) < s.length())
		if (s[i + 1] == ch)
			return true;
	return false;
}

int reiteration(const string& s, int i)
{
	if (is_same_ch(s, i, s[i]))
		return 1 + reiteration(s, i + 1);
	return 1;
}

void repeat(const string& s)
{
	for (int i = 0; i < s.length(); ++i)
	{
		if (reiteration(s, i) > 3)
			error("repeat: не является римской цифрой ", s);
	}
}

bool is_Roman(const string& s)
{
	if (s.length() > 0)
	{
		for (int i = 0; i < s.length(); ++i)
		{
			if (!(s[i] == 'I' || s[i] == 'V' || s[i] == 'X' || s[i] == 'L' || s[i] == 'C'))
				error("is_Roman: не является римской цифрой ", s);
		}
		//repeat(s);
		return true;
	}
	else
		error("Длина string = 0");
}

Roman_int::Roman_int(string s)
{
	if (is_Roman(s))
		roman = s;
}

int search_pr(const char& ch)
{
	for (int i = 0; i < Roman_priority.size(); ++i)
		if (ch == Roman_priority[i])
			return i;
	error("search_pr ошибка");
}

bool next_high_pr(const string& s, int i)
{
	if ((i + 1) < s.length())
	{
		int priority_0 = search_pr(s[i]);
		int priority_1 = search_pr(s[i + 1]);
		if (priority_0 < priority_1)
			return true;
		return false;
	}
	return false;
}

int Roman_int::as_int() const
{
	int sum = 0;
	for (int i = 0; i < roman.length(); ++i)
	{
		if (next_high_pr(roman, i))
		{
			sum = sum - Roman_value[search_pr(roman[i])] + Roman_value[search_pr(roman[i + 1])];
			++i;
		}
		else
			sum += Roman_value[search_pr(roman[i])];
	}
	return sum;
}

ostream& operator<<(ostream& os, Roman_int& r)
{
	return os << r.as_roman();
}

istream& operator>>(istream& is, Roman_int& r)
{
	string s;
	is >> s;
	r = Roman_int(s);
	return is;
}

Roman_int to_Roman(int i)
{

	string s;
	if (i / 100 > 0)
	{
		int count = i / 100;
		for (int j = 0; j < count; ++j)
		{
			s += 'C';
		}
		i -= count * 100;
	}
	if (i / 50 > 0)
	{
		int count = i / 100;
		for (int j = 0; j < count; ++j)
		{
			s += 'L';
		}
		i -= count * 50;
	}
	if (i / 10 > 0)
	{
		int count = i / 10;
		for (int j = 0; j < count; ++j)
		{
			s += 'X';
		}
		i -= count * 10;
	}
	if (i / 5 > 0)
	{
		int count = i / 5;
		for (int j = 0; j < count; ++j)
		{
			s += 'V';
		}
		i -= count * 5;
	}
	if (i / 1 > 0)
	{
		int count = i / 1;
		for (int j = 0; j < count; ++j)
		{
			s += 'I';
		}
		i -= count * 1;
	}
	if (i > 0)
		error("to_Roman ожидался ноль");
	return Roman_int(s);
}