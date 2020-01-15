#include "Patron.h"

string pr_name;
int pr_lib_code;
double pr_price;
bool pr_price_pay;

void Patron::enter()
{
	cout << "Функция добавления нового пользователя.\n";
	en_name();
	en_lib_code();
	en_price();
	en_price_pay();
}

void Patron::en_name()
{
	cout << "Введите имя нового пользователя.\n";
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
	cout << "Введите библиотечный код нового пользователя.\n";
	int i;
	cin >> i;
	if (i < 0 || i > 100000)
		error("Введенный библиотечный код вне возможного диапозона значений.");
	pr_lib_code = i;
	return;
}

void Patron::en_price()
{
	cout << "Введите членский взнос для нового пользователя.\n";
	double d;
	cin >> d;
	if (d < 0 || d > 1000)
		error("Введенный членский взнос некорректен.");
	pr_price = d;
	return;
}

void Patron::en_price_pay()
{
	cout << "Новый пользователь оплатил членский взнос?\n"
		<< "y - да/n - нет\n";
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
		error("Неизвестный ответ");
	}
}

string check_pay(const Patron& p)
{
	switch (p.price_pay())
	{
	case(true):
		return "Членский взнос пользователя оплачен.\n";
	case(false):
		return "Членский взнос пользователя не оплачен.\n";
	default:
		return "Пользователь не найден.\n";
		break;
	}
}

void pay_enter(Patron& p)
{
	cout << "Выбран пользователь " << p.name() << endl
		<< "Библиотечный код: " << p.lib_code() << endl
		<< "Введите: " << endl << "1 чтобы изменить членский взнос\n"
		<< "2 чтобы отметить оплату членского взноса\n"
		<< "3 назад в меню\n";
	char ch;
	cin >> ch;
	switch (ch)
	{
	case('1'):
		cout << "Старое значение членского взноса: " << p.price()
			<< endl << "Введите новое значение." << endl;
		double d;
		cin >> d;
		if (d < 0 || d > 1000)
			error("Введенный членский взнос некорректен.");
		pr_price = d;
		return;
	case('2'):
		if (p.price_pay() == false)
		{
			pr_price_pay = true;
			cout << "Отметка оплаты членского взноса пользователя произведена.\n";
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
		cout << "Неопознанный ответ. Вы будете возвращены в меню.\n";
		return;
	}
}

ostream& operator<<(ostream& os, const Patron& p)		//печатает имя пользователя, библиотечный код и оплату доступа
{
	return os << endl << p.name() << endl << p.lib_code()
		<< endl << check_pay(p);
}