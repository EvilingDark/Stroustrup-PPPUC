﻿// глава 4,8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "iostream"
#include "string"
#include "vector"
#include "algorithm"
#include "cmath"

using namespace std;

//программа угадывает число которое загадал пользователь
int main()
{
	setlocale(LC_ALL, "Russian");

	int number = 50, check = 0, counter = 50;
	while (check != 7)
	{
		string q = " ";
		cout << "Число больше " << number << "? y/n Yes/Not" << " " << counter << "\n";
		cin >> q;
		if (q == "y")
		{
			++check;
			counter /= 2;
			if (counter < 12)
				++counter;
			if (counter <= 4)
				--counter;
			if (counter == 0)
				++counter;
			number += counter;
			if (check == 7)
				cout << "Загаданное число: " << number << "\n";
		}
		else if (q == "n")
		{
			++check;
			counter /= 2;
			if (counter < 12)
				++counter;
			if (counter <= 4)
				--counter;
			if (counter == 0)
				++counter;
			number -= counter;
			if (check == 7)
				cout << "Загаданное число: " << number + 1 << "\n";
		}
		else
			cout << "Ошибка. Ответ введен неверно.\n";
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
