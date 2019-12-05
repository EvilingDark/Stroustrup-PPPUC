﻿// глава 5 задание.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "iostream"
#include "string"
#include "vector"
#include "algorithm"
#include "cmath"

using namespace std;

inline void error(const string& s)
{
	throw runtime_error(s);
}

int main()
{
	setlocale(LC_ALL, "Russian");

	try
	{
		//код



	system("pause");
	return 0;
	}

	catch (const exception& e)
	{
		cout << "Error: " << e.what() << endl;
		system("pause");
		return 1;
	}
	catch (out_of_range)
	{
		cout << "Ошибка диапозона\n" << endl;
		system("pause");
		return 2;
	}	
	catch (...)
	{
		cerr << "Неизвестное исключение! \n";
		system("pause");
		return 3;
	}
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
