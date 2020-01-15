#pragma once

#include "Header.h"

struct Point
{
	int x;
	int y;
};

ostream& operator<<(ostream& os, const Point& p);
bool operator==(const Point& a, const Point& b);
bool operator!=(const Point& a, const Point& b);