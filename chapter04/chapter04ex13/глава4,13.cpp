﻿// глава4,13.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "iostream"
#include "string"
#include "vector"
#include "algorithm"
#include "cmath"

using namespace std;

//программа ищет простые числа
int main()
{
	setlocale(LC_ALL, "Russian");
	int min = 1, max = 100;
	vector<int> prime = { 2,3,5 };
	cout << "Введите максимальное число\n";
	cin >> max;
	for (int i = 4; i < max; ++i)
	{
		int check = 0;
		if (i % 2 != 0)
			++check;
		if (i % 3 != 0)
			++check;
		if (i % 5 != 0)
			++check;
		if (check == 3)
			prime.push_back(i);
	}
	for (int i = 0; i < prime.size(); ++i)
		cout << " " << prime[i] << "\n";


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
