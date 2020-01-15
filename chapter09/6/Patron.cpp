#include "Patron.h"

string pr_name;
int pr_lib_code;
double pr_price;
bool pr_price_pay;

void Patron::enter()
{
	cout << "������� ���������� ������ ������������.\n";
	en_name();
	en_lib_code();
	en_price();
	en_price_pay();
}

void Patron::en_name()
{
	cout << "������� ��� ������ ������������.\n";
	string title;
	while (cin) {
		string s;
		char ch;
		cin >> s;
		title += s;
		cin.get(ch);
		if (ch == '\n')
		{
			pr_name = title;
			return;
		}
		if (isspace(ch))
			title += ' ';
		cin.unget();
	}
}

void Patron::en_lib_code()
{
	cout << "������� ������������ ��� ������ ������������.\n";
	int i;
	cin >> i;
	if (i < 0 || i > 100000)
		error("��������� ������������ ��� ��� ���������� ��������� ��������.");
	pr_lib_code = i;
	return;
}

void Patron::en_price()
{
	cout << "������� �������� ����� ��� ������ ������������.\n";
	double d;
	cin >> d;
	if (d < 0 || d > 1000)
		error("��������� �������� ����� �����������.");
	pr_price = d;
	return;
}

void Patron::en_price_pay()
{
	cout << "����� ������������ ������� �������� �����?\n"
		<< "y - ��/n - ���\n";
	char ch;
	cin >> ch;
	switch (ch)
	{
	case('y'):
		pr_price_pay = true;
		return;
	case('n'):
		pr_price_pay = false;
		return;
	default:
		error("����������� �����");
	}
}

string check_pay(const Patron& p)
{
	switch (p.price_pay())
	{
	case(true):
		return "�������� ����� ������������ �������.\n";
	case(false):
		return "�������� ����� ������������ �� �������.\n";
	default:
		return "������������ �� ������.\n";
		break;
	}
}

void pay_enter(Patron& p)
{
	cout << "������ ������������ " << p.name() << endl
		<< "������������ ���: " << p.lib_code() << endl
		<< "�������: " << endl << "1 ����� �������� �������� �����\n"
		<< "2 ����� �������� ������ ��������� ������\n"
		<< "3 ����� � ����\n";
	char ch;
	cin >> ch;
	switch (ch)
	{
	case('1'):
		cout << "������ �������� ��������� ������: " << p.price()
			<< endl << "������� ����� ��������." << endl;
		double d;
		cin >> d;
		if (d < 0 || d > 1000)
			error("��������� �������� ����� �����������.");
		pr_price = d;
		return;
	case('2'):
		if (p.price_pay() == false)
		{
			pr_price_pay = true;
			cout << "������� ������ ��������� ������ ������������ �����������.\n";
			return;
		}
		else
		{
			cout << check_pay(p);
			return;
		}
	case('3'):
		return;
	default:
		cout << "������������ �����. �� ������ ���������� � ����.\n";
		return;
	}
}

ostream& operator<<(ostream& os, const Patron& p)		//�������� ��� ������������, ������������ ��� � ������ �������
{
	return os << endl << p.name() << endl << p.lib_code()
		<< endl << check_pay(p);
}