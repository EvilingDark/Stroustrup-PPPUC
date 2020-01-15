// глава 9 задание 1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <Header.h>

struct Date
{
	int y;
	int m;
	int d;
};

void add_day(Date& dd, int n)
{
	dd.d += n;
}

void init_day(Date& dd, int y, int m, int d)
{
	try
	{
		if (m < 1 || m>12)
			error("Неверно указан месяц");
		if (d < 1 || d>31)
			error("Неверно указан день");
		dd.y = y;
		dd.m = m;
		dd.d = d;
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
	return os << '(' << d.y
		<< ',' << d.m
		<< ',' << d.d << ')';
}

int main()
try
{
	setlocale(LC_ALL, "Russian");
	Date today;
	init_day(today, 2009, 13, -5);
	Date tomorrow = today;
	add_day(tomorrow, 1);
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
