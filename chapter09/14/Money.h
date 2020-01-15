#pragma once
#include <Header.h>

namespace Cash_t {

	class Money
	{
	public:
		double sum() const { return (double(cents) / 100); }		//���������� ��������
		std::string val() const { return value; }					//���������� ������
		Money(int cents, std::string value);						//���� ����� ����������
		Money() {};
	private:
		long int cents;
		std::string value;
	};

	Money sum(const Money& one, const Money& two);		//�����
	Money dif(const Money& one, const Money& two);		//��������
	Money prod(const Money& one, double d);						//��������� �� �����
	Money quot(const Money& one, double q);						//������� �� �����
	ostream& operator<<(ostream& os, const Money& m);
}

