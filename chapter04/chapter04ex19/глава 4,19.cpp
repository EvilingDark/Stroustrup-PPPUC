// глава 4,19.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "iostream"
#include "string"
#include "vector"
#include "algorithm"
#include "cmath"

using namespace std;

void flush_stdin()
{
	cin.clear();
	while (cin.get() != '\n');
}

//программа записывает имена и баллы
int main()
{
	setlocale(LC_ALL, "Russian");
	vector<string> names;
	vector<int> marks;
	string nm = " ";
	int mr = 0;
	cout << "Введите имя и количество баллов\nЧтобы закончить ввод введите NoName\n";
	while (cin >> nm >> mr)
	{
		flush_stdin();
		int check = 0;
		if (names.size() == 0)	//ввод первого имени
		{
			names.push_back(nm);
			marks.push_back(mr);
		}
		int counter = names.size();			//чтобы не менялся размер вектора
		for (int i = 0; i < counter; ++i)	//проверяет чтобы не было повторов имен
		{
			if (names[i] != nm)
			{
				++check;
				if (check == names.size())
				{
					names.push_back(nm);
					marks.push_back(mr);
				}
			}
			else if (names[i] == nm)
			{
				if (names.size() != 1)
				{
					cout << "Ошибка. Имя уже имеется в списке!\n";
				}
			}
		}
	}
	for (int i = 0; i < names.size(); ++i)
		cout << names[i] << " " << marks[i] << "\n";
	cout << "Поиск по имени в списке. Введите имя\n";
	flush_stdin();
	cin	>> nm;
	int test = 0;
	for (int i = 0; i < names.size(); ++i)	//ищет введенное имя в векторе
	{
		if (names[i] != nm)
		{
			++test;
			if (test == names.size())
				cout << "Имени нет в списке\n";
		}
		else if (names[i] == nm)
				cout << names[i] << " " << marks[i] << "\n";
	}

	cout << "Поиск по баллам в списке\n";
	test = 0;
	flush_stdin();
	cin >> mr;
	for (int i = 0; i < marks.size(); ++i)
	{
		if (marks[i] != mr)
		{
			++test;
			if (test == marks.size())
				cout << "В списке нет имен с таким количеством баллов\n";
		}
		else if (marks[i] == mr)
			cout << names[i] << " " << marks[i] << "\n";
	}

	system("pause");
	return 0;
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
