#pragma once

#include <Header.h>

const double not_a_reading = -7777;

struct Day
{
	vector<double> hour{ vector<double>(24, not_a_reading) };
};

