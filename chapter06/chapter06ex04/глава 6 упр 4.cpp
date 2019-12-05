// глава 6 упр 4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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

void flush_stdin() //очищает поток ввода
{
	cin.clear();
	while (cin.get() != '\n');
}

inline void keep_window_open()
{
	cin.clear();
	cout << "Please enter a character to exit\n";
	char ch;
	cin >> ch;
	return;
}

inline void error(const string& s)
{
	throw runtime_error(s);
}

class Name_value {
public:
	string Name;        // what kind of token
	int value;     // for numbers: a value 
	Name_value(string name)    // make a Token from a char
		:Name(name), value(0) { }
	Name_value(string name, int val)     // make a Token from a char and a double
		:Name(name), value(val) { }
};

//программа записывает имена и баллы
int main()
try
{
	setlocale(LC_ALL, "Russian");
	vector<Name_value> names;
	vector<int> marks;
	string nm = " ";
	int mr = 0;
	cout << "Введите имя и количество баллов\nЧтобы закончить ввод введите NoName\n";
	while (cin)
	{
		int check = 0;
		while (cin)
		{
			string s;
			int i;
			cin >> s >> i;
			if (s == "NoName")
				break;
			names.push_back(Name_value(s, i));
			for (int i = 0; i < names.size(); ++i)
			{
				for (int j = 0; j < names.size(); ++j)
					if (names[i].Name == names[j].Name && i != j)
						error("Имя уже имеется в списке");
			}
		}
		for (int i = 0; i < names.size(); ++i)
			cout << names[i].Name << " " << names[i].value << "\n";
	}
	keep_window_open();
	return 0;
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
