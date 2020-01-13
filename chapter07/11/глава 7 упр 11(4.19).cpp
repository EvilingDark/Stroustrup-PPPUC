// глава 7 упр 11(4.19).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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

vector<string> names;
vector<int> marks;

void name_imput()
{
	flush_stdin();
	string nm = " ";
	int mr = 0;
	cout << "Введите имя и количество баллов\nЧтобы закончить ввод введите NoName\n";
	while (cin >> nm)
	{
		int check = 0;
		if (nm == "NoName")
			break;
		cin >> mr;
		flush_stdin();
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
				++check;					//счетчик, если становится равным размеру вектора добавляет еще одно имя
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
					error("Имя уже имеется в списке!\n");
				}
			}
		}
	}
}

void name_output()
{
	for (int i = 0; i < names.size(); ++i)
		cout << names[i] << " " << marks[i] << "\n";
}

void name_search()
{
	cout << "Поиск по имени в списке. Введите имя\n";
	string nm = " ";
	cin >> nm;
	flush_stdin();
	int test = 0;
	for (int i = 0; i < names.size(); ++i)	//ищет введенное имя в векторе
	{
		if (names[i] != nm)
		{
			++test;
			if (test == names.size())
				error("Имени нет в списке\n");
		}
		else if (names[i] == nm)
			cout << names[i] << " " << marks[i] << "\n";
	}
}

void point_search()
{
	cout << "Поиск по баллам в списке\n";
	int test = 0;
	int mr = 0;
	cin >> mr;
	flush_stdin();
	for (int i = 0; i < marks.size(); ++i)
	{
		if (marks[i] != mr)
		{
			++test;
			if (test == marks.size())
				error("В списке нет имен с таким количеством баллов\n");
		}
		else if (marks[i] == mr)
			cout << names[i] << " " << marks[i] << "\n";
	}
}

void selection()
{
	cout << "Программа предназначена для записи имен, баллов и поиск по имени или баллам.\nВозможные действия:\n"
		<< "1 - Запись имен и баллов.\n2 - Просмотр списка.\n3 - Поиск по имени.\n4 - Поиск по баллам.\n";
	while (cin) try {
		cout << "Введите номер требуемой действие.\n";
		char ch;
		cin >> ch;
		switch (ch)
		{
		case('1'):
			name_imput();
			break;
		case('2'):
			name_output();
			break;
		case('3'):
			name_search();
			break;
		case('4'):
			point_search();
			break;
		default:
			error("Неизвестное действие");
			break;
		}
	}
	catch (exception& e) {
		cerr << "error: " << e.what() << '\n';
		keep_window_open();
	}
}

//программа записывает имена и баллы
int main()
try
{
	setlocale(LC_ALL, "Russian");
	selection();
	system("pause");
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
