#include "Rational.h"
#include "Header.h"

int num;
int den;

Rational::Rational(int n, int d) {
	if (d <= 0)
		error("Знаменатель не может быть отрицательным или равняться нулю");
	num = n;	
	den = d;	
	return;
}

void Rational::low_den()
{
	if (num % den == 0)
	{
		num /=den;
		den = 1;
		return;
	}
	if (den % num == 0)
	{
		den /= num;
		num = 1;
		return;
	}
	for (int i = 2; i < den; ++i)
		if (num % i == 0 && den % i == 0)
		{
			num /= i;
			den /= i;
		}
	for (int i = 2; i < den; ++i)
		if (num % i == 0 && den % i == 0)
		{
			num /= i;
			den /= i;
		}
	return;
}

Rational r_plus(const Rational& rat0, const Rational& rat1)
{
	if (rat0.denominator() == rat1.denominator())
	{
		Rational turn{ rat0.numerator() + rat1.numerator(), rat0.denominator() };
		turn.low_den();
		return turn;
	}
	int com_den = rat0.denominator() * rat1.denominator();
	int com_num = rat0.numerator() * rat1.denominator() + rat1.numerator() * rat0.denominator();
	Rational turn{ com_num, com_den };
	turn.low_den();
	return turn;
}

Rational r_minus(const Rational& rat0, const Rational& rat1)
{
	if (rat0.denominator() == rat1.denominator())
	{
		Rational turn{ rat0.denominator() - rat1.numerator(), rat0.denominator() };
		turn.low_den();
		return turn;
	}
	int com_den = rat0.denominator() * rat1.denominator();
	int com_num = rat0.numerator() * rat1.denominator() - rat1.numerator() * rat0.denominator();
	Rational turn{ com_num, com_den };
	turn.low_den();
	return turn;
}

Rational multiply(const Rational& rat0, const Rational& rat1)
{
	int com_den = rat0.denominator() * rat1.denominator();
	int com_num = rat0.numerator() * rat1.numerator();
	Rational turn{ com_num, com_den };
	turn.low_den();
	return turn;
}

Rational division(const Rational& rat0, const Rational& rat1)
{
	int com_den = rat0.denominator() * rat1.numerator();
	int com_num = rat0.numerator() * rat1.denominator();
	if (com_den < 0)
		com_num = -com_num;
	Rational turn{ com_num, com_den };
	turn.low_den();
	return turn;
}

bool equally(const Rational& rat0, const Rational& rat1)
{
	Rational ratio_0 = rat0;
	Rational ratio_1 = rat1;
	ratio_0.low_den();
	ratio_1.low_den();
	if (ratio_0.numerator() == ratio_1.numerator() && ratio_0.denominator() == ratio_1.denominator())
		return true;
	return false;
}

ostream& operator<<(ostream& os, const Rational& rat)
{
	return os << rat.numerator() << '/' << rat.denominator();
}
