#pragma once
#include "Header.h"

struct Numbers
{
	string num() { return Number; }
	string sys() { return Sys; }
	int sys_int() { return Sys_int; }
	int to_dec();
	Numbers(string s);
private:
	string Sys;
	int Sys_int;
	string Number;
};

//ostream& operator<<(ostream& os, Numbers num);
//istream& operator>>(istream& is, string s);