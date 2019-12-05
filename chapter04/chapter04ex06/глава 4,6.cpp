﻿// глава 4,6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "iostream"
#include "string"
#include "vector"
#include "algorithm"
#include "cmath"

using namespace std;

//программа записывает числа ищет среднее и медиану
int main()
{
	setlocale(LC_ALL, "Russian");

	vector<double> temps ;
	for (double temp; cin >> temp;)
		temps.push_back(temp);
	// Темпера ты
	// Чтение в t emp
	// Внесение temp в вектор
	// Выисление средней темпера туы:
	double sum = 0;
	for (double х : temps)
	{
		sum += х;
	}
	cout << "Средняя температура: "
	<< sum/temps.size() << " " << sum << "\n";
	// Выисление медиан темпера туы:
	sort(temps.begin(), temps.end()); //Сортиовка вектора температу
	if (temps.size()%2 == 0)
		cout << "Медианная температура: " << (temps[temps.size()/2] + temps[temps.size()/2-1])/2.0 << "\n";
	else
		cout << "Медианная температура: " << temps [temps.size()/2] << "\n";

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
