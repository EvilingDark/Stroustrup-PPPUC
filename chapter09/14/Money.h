#pragma once
#include <Header.h>

namespace Cash_t {

	class Money
	{
	public:
		double sum() const { return (double(cents) / 100); }		//возвращает значение
		std::string val() const { return value; }					//возвращает валюту
		Money(int cents, std::string value);						//ввод новой переменной
		Money() {};
	private:
		long int cents;
		std::string value;
	};

	Money sum(const Money& one, const Money& two);		//сумма
	Money dif(const Money& one, const Money& two);		//разность
	Money prod(const Money& one, double d);						//умножение на число
	Money quot(const Money& one, double q);						//деление на число
	ostream& operator<<(ostream& os, const Money& m);
}

