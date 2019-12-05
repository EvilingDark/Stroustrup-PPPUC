// глава 3,2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"
#include "string"
#include "vector"
#include "algorithm"
#include "cmath"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	string previous = " ";

	string current;
	while (cin>>current)
	{
		if (previous == current)
												// Переменная previous ;
												// инициализирована "не словом"
												// Текущее слово
												// Считыва ем поток слов
												// Проверяем совпадение
												// с предыдущим словом
			cout << "Повторяющееся спово : " << current << '\n' ;
		previous = current ;
	}
	system ("pause");
	return 0;
}

