#pragma once
#include <Day.h>
#include "Reading.h"
#include <Header.h>

const int not_a_month = -1;

vector<string> month_input_tb1 = { 
	"jan","feb","mar","apr","may","jun",
	"jul","aug","sep","oct","nov","dec" 
};

struct Month
{
	int month{ not_a_month };
	vector<Day> day{ 32 };
};

istream& operator>>(istream& is, Month& m);
int month_to_int(string s);
string int_to_month(int i);