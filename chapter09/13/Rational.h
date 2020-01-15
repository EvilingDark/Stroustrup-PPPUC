#pragma once
#include <Header.h>

class Rational
{
public:
	void low_den();							//���������� � ����������� �����������
	int numerator() const { return num; }
	int denominator() const { return den; }
	double db() { return double(num) / double(den); }
	Rational(int n, int d);
	Rational() {}
private:
	int num;
	int den;
};

Rational r_plus(const Rational& rat0, const Rational& rat1);		//��������
Rational r_minus(const Rational& rat0, const Rational& rat1);		//���������
Rational multiply(const Rational& rat0, const Rational& rat1);		//���������
Rational division(const Rational& rat0, const Rational& rat1);		//�������
bool equally(const Rational& rat0, const Rational& rat1);		//���������
ostream& operator<<(ostream& os, const Rational& rat);