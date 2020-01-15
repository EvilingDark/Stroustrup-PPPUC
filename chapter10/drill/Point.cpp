#include "Point.h"
#include "Header.h"

int x;
int y;

ostream& operator<<(ostream& os, const Point& p)
{
	return os << '(' << p.x << ',' << p.y << ')';
}

bool operator==(const Point& a, const Point& b)
{
	if (a.x == b.x && a.y == b.y)
		return true;
	return false;
}

bool operator!=(const Point& a, const Point& b)
{
	return !(a == b);
}
