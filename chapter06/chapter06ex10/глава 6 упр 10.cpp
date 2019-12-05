// глава 6 упр 10.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include<iostream>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<cmath>
#include<cstdlib>
#include<string>
#include<list>
#include <forward_list>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include <array>
#include <regex>
#include<random>
#include<stdexcept>
#include <cassert>

using namespace std;

//программа выполняющая перестановки или сочетания с 2 числами
inline void error(const string& s)
{
	throw runtime_error(s);
}

inline void keep_window_open()
{
	cin.clear();
	cout << "Please enter a character to exit\n";
	char ch;
	cin >> ch;
	return;
}

inline void keep_window_open(string s)
{
	if (s == "") return;
	cin.clear();
	cin.ignore(120, '\n');
	for (;;) {
		cout << "Please enter " << s << " to exit\n";
		string ss;
		while (cin >> ss && ss != s)
			cout << "Please enter " << s << " to exit\n";
		return;
	}
}

int32_t fac(std::int32_t x) {
	if (x > 13 || x < 0)
		error("Неверные входные данные для функции fac");
	static const int table[] = {
		1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600,
	};
	assert(x >= 0);
	assert(x <= 12);
	return table[x];
}

int main()
try
{
	setlocale(LC_ALL, "Russian");
	cout << "Введите два не отрицательных целых числа не больше 12\n";
	int a_num, b_num;
	cin >> a_num >> b_num;
	if (a_num > 13 || a_num < 0)
		error("Недопустимый вариант ввода первого числа");
	if (b_num > 13 || b_num < 0)
		error("Недопустимый вариант ввода второго числа");
	if (b_num > a_num)
		error("Второе число не может быть больше первого");
	cout << a_num << " " << b_num << "\n";
	cout << "Перестановка(p) или сочетание(s)?\n";
	char ch;
	cin >> ch;
	long int num;
	switch (ch)
	{
	case('p'):
		num = fac(a_num) / fac(a_num - b_num);
		cout << "Ответ " << num << "\n";
		break;
	case('s'):
		num = fac(a_num) * fac(b_num) / fac(a_num - b_num);
		cout << "Ответ " << num << "\n";
		break;
	default:
		error("Неизвестная операция");
	}
	keep_window_open();
}
catch (exception& e) {
	cerr << "error: " << e.what() << '\n';
	keep_window_open();
	return 1;
}
catch (...) {
	cerr << "Oops: unknown exception!\n";
	keep_window_open();
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
