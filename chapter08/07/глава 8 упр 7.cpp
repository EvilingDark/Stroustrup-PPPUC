﻿// глава 8 упр 7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
// программа записывает имена, по именам записывает возраст, сортирует по имени и печатает имя и соответствующий возраст

#include <Header.h>

void print(const vector<string>& vs)		//печатает вектор
{
	cout << '\n';
	for (int i = 0; i < vs.size(); ++i)
		cout << i + 1 << " элемент " << vs[i] << "\n";
	cout << '\n';
}

void enter_names(vector<string>& name)		//ввод имен
{
	cout << "Введите имя для записи в список.\n" << "Введите End для окончания ввода.\n";
	while (cin)
	{
		string s;
		cin >> s;
		if (s == "End")
			return;
		name.push_back(s);
	}
	return;
}

void enter_ages(vector<string>& name, vector<int>& age)		//ввод возраста для соответствующего имени
{
	cout << "Введите возраст для соответствующего имени.\n";
	for (int i = 0; i < name.size(); ++i)
	{
		cout << name[i] << " ";
		int num = 0;
		cin >> num;
		age.push_back(num);
	}
	return;
}

void print_sort(const vector<string>& name, const vector<int>& age)		//печать сортированного списка по имени
{
	vector<string> s_name = name;
	vector<int> s_age;
	sort(s_name.begin(), s_name.end());
	for (int i = 0; i < s_name.size(); ++i)
		for (int j = 0; j < name.size(); ++j)
			if (s_name[i] == name[j])
				s_age.push_back(age[j]);
	for (int i = 0; i < s_name.size(); ++i)
		cout << s_name[i] << " " << s_age[i] << "\n";
	return;
}

int main()
try
{
	setlocale(LC_ALL, "Russian");
	vector<string> name;
	vector<int> age;
	enter_names(name);
	enter_ages(name, age);
	print_sort(name, age);
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
