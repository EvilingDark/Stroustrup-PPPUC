#pragma once

#include <Header.h>

struct Reading
{
	int day;
	int hour;
	double temperature;
};

istream& operator>>(istream& is, Reading& r);
bool is_valid(const Reading& r);
