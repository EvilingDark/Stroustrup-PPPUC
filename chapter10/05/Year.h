#pragma once

#include <Month.h>
#include <Header.h>

struct Year
{
	int year;
	vector<Month> month{ 12 };
};

istream& operator>>(istream& is, Year& y);