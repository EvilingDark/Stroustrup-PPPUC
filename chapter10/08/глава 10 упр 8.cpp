﻿// глава 10 упр 8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <Header.h>

bool is_write(string iname)
{
	ifstream ist{ iname };
	if (!ist)
		error("Невозможно открыть входной файл", iname);
	char ch;
	ist >> ch;
	if (ist.eof())
		return false;
	return true;
}

void fread_to_file(string iname, string oname)
{
	ifstream ist{ iname };
	if (!ist)
		error("Невозможно открыть входной файл", iname);
	ofstream ost{ oname, ios::app };						//запись в конец файла
	if (!ost)
		error("Невозможно открыть выходной файл", oname);
	char ch;
	if (is_write(oname))
		ost << endl;
	while (ist.get(ch))
	{
		ost << ch;
		if (ist.eof()) {
			cout << "Достигнут конец входного файла " << iname << endl;
			return;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Введите название первого файла для чтения" << endl;
	string iname_0;
	cin >> iname_0;
	cout << "Введите название второго файла для чтения" << endl;
	string iname_1;
	cin >> iname_1;
	cout << "Введите название файла для записи" << endl;
	string oname;
	cin >> oname;
	fread_to_file(iname_0, oname);
	fread_to_file(iname_1, oname);
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
