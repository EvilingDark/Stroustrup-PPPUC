// глава 6 упр 9.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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

using namespace std;

//программа получает число и по порядку говорит сколько тысяч, сокет, десяткой, единиц
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

int main()
try
{
	setlocale(LC_ALL, "Russian");
	cout << "Введите число\n";
	string number = " ";
	cin >> number;
	int i = number.length();
	char ch = i + '0';
	cout << ch << "\n";
	switch (ch)
	{
	case ('1'):
		cout << number << " - это " << number[0] << " единицы\n";
		break;
	case ('2'):
		cout << number << " - это " << number[0] << " десятка, " << number[1] << " единицы\n";
		break;
	case ('3'):
		cout << number << " - это " << number[0] << " сотни, " << number[1] << " десятка, " << number[2] << " единицы\n";
		break;
	case ('4'):
		cout << number << " - это " << number[0] << " тысячи, " << number[1] << " сотни, " << number[2] << " десятка, " << number[3] << " единицы\n";
		break;
	default:
		error("Ошибка ввода");
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
