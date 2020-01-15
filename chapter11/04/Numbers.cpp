#include "Numbers.h"
#include "Header.h"

string Sys;
int Sys_int;
string Number;

Numbers::Numbers(string s)
{
	for (char ch : s)
		if (!isdigit(ch) && ch != 'x')
			error("Введено не число");
	if (s[0] == '0' && s[1] == 'x')
	{
		Sys = "шестнадцатиричное";
		Sys_int = 16;
		Number = s;
	}
	else if (s[0] == '0')
	{
		Sys = "восьмеричное";
		Sys_int = 8;
		Number = s;
	}
	else
	{
		Sys = "десятичное";
		Sys_int = 10;
		Number = s;
	}
}

int Numbers::to_dec()
{
	if (Sys_int == 10)
		return stoi(Number);
	else if (Sys_int == 16)
	{
		istringstream ist(Number);
		int i;
		ist >> hex >> i;
		return i;
	}
	else if (Sys_int == 8)
	{
		istringstream ist(Number);
		int i;
		ist >> oct >> i;
		return i;
	}
}

/*ostream& operator<<(ostream& os, Numbers num)
{
	
}

istream& operator>>(istream& is, Numbers num)
{
	string s;
	is >> s;
	return num{ Numbers(s) };
}*/