#include "Money.h"
#include <Header.h>

namespace Cash_t {

	long int cents;
	std::string value;

	Money::Money(int c, string v)
	{
		if (v == "USD" || v == "EUR" || v == "CNY" || v == "RUB" || v == "$")
		{
			if (v == "$")
				v = "USD";
			cents = c;
			value = v;
		}
		else
			error("Неизвестная валюта");
	}

	Money val_to_usd(const Money& m)
	{
		long int s;
		const string v = "USD";
		if (m.val() == "EUR")
		{
			s = m.sum() * 100 * 1.1109;
			return Money(s, v);
		}
		else if (m.val() == "CNY")
		{
			s = m.sum() * 100 * 0.1395;
			return Money(s, v);
		}
		else if (m.val() == "RUB")
		{
			s = m.sum() * 100 * 0.0151;
			return Money(s, v);
		}
		else if (m.val() == "USD")
			return m;
		else
			error("Неизвестная валюта");
	}

	ostream& operator<<(ostream& os, const Money& m)
	{
		return os << m.val() << m.sum();
	}

	Money sum(const Money& one, const Money& two)
	{
		long int f_sum;
		if (one.val() == two.val())
		{
			f_sum = (one.sum() + two.sum()) * 100;
			return Money(f_sum, one.val());
		}
		Money one_f = val_to_usd(one);
		Money two_f = val_to_usd(two);
		f_sum = (one_f.sum() + two_f.sum()) * 100;
		return Money(f_sum, "USD");
	}

	Money dif(const Money& one, const Money& two)
	{
		long int f_sum;
		if (one.val() == two.val())
		{
			f_sum = (one.sum() - two.sum()) * 100;
			return Money(f_sum, one.val());
		}
		Money one_f = val_to_usd(one);
		Money two_f = val_to_usd(two);
		f_sum = (one_f.sum() - two_f.sum()) * 100;
		return Money(f_sum, "USD");
	}

	Money prod(const Money& one, double d)
	{
		if (d < 0)
			error("Множитель должен быть положительным");
		return Money(one.sum() * 100 * d, one.val());
	}

	Money quot(const Money& one, double q)
	{
		if (q <= 0)
			error("Делитель должен быть больше нуля");
		return Money(one.sum() * 100 / q, one.val());
	}

}
