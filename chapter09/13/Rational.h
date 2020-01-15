#pragma once
#include <Header.h>

class Rational
{
public:
	void low_den();							//приведение к наименьшему знаменателю
	int numerator() const { return num; }
	int denominator() const { return den; }
	double db() { return double(num) / double(den); }
	Rational(int n, int d);
	Rational() {}
private:
	int num;
	int den;
};

Rational r_plus(const Rational& rat0, const Rational& rat1);		//сложение
Rational r_minus(const Rational& rat0, const Rational& rat1);		//вычитание
Rational multiply(const Rational& rat0, const Rational& rat1);		//умножение
Rational division(const Rational& rat0, const Rational& rat1);		//деление
bool equally(const Rational& rat0, const Rational& rat1);		//равенство
ostream& operator<<(ostream& os, const Rational& rat);