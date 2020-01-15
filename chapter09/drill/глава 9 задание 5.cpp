// глава 9 задание 5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <Header.h>

enum class Month {
	jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

class Date
{
public:
	Date(int y, Month m, int d);
	void add_day(int n);
	int year() const { return y; }
	Month month() const { return m; }
	int day() const { return d; }
private:
	int y;
	Month m;
	int d;
};

void Date::add_day(int n)
{
	d += n;
}

Date::Date(int yy, Month mm, int dd)
	:y{ yy }, m{ mm }, d{ dd }
{
	try
	{
		if (int(mm) < 1 || int(mm) > 12)
			error("Неверно указан месяц");
		if (dd < 1 || dd>31)
			error("Неверно указан день");
	}
	catch (exception& e) {
		cerr << "exception: " << e.what() << endl;
		char c;
		while (cin >> c && c != ';');
		return;
	}
}

ostream& operator<<(ostream& os, const Date& d)
{
	return os << '(' << d.year()
		<< ',' << int(d.month())
		<< ',' << d.day() << ')';
}

int main()
try
{
	setlocale(LC_ALL, "Russian");
	Date today{ 2009, Month::dec, -6 };
	Date tomorrow = today;
	tomorrow.add_day(1);
	operator<<(cout, today);
	cout << endl;
	operator<<(cout, tomorrow);
}
catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
	char c;
	while (cin >> c && c != ';');
	return 1;
}
catch (...) {
	cerr << "exception\n";
	char c;
	while (cin >> c && c != ';');
	return 2;
}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
