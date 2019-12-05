// глава 4,4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"
#include "string"
#include "vector"
#include "algorithm"
#include "cmath"

using namespace std;

//программа выводит 2 числа
int main()
{
	setlocale(LC_ALL, "Russian");

	cout << "Напишите два целых числа\n";
	string val_1 = " ", val_2 = " ";
	while (cin >> val_1 >> val_2)
	{
		//char * a;
		double al_e = 0, al_e2 = 0;
		double v1 = atof(val_1.c_str());
		//cout << a << "\n";
		double v2 = atof(val_2.c_str());
		//cout << a << "\n";
		cout << v1 << " " << v2 << "\n";
		if (val_1 == "|")
			return true;
		if (val_2 == "|")
			return true;
		al_e = abs(v1 / v2 -1);
		al_e2 = abs(v2 / v1 -1);
		if (v1 == v2)
			cout << "Числа равны" << "\n\n";
		else if (al_e < 0.01)
			cout << "Числа почти равны" << "\n\n";
		else if (al_e < 0.01)
			cout << "Числа почти равны" << "\n\n";		
		else if (v1 > v2)
		{
			cout << "Наименьшее значение равно: " << v2 << "\n"
			<< "Наименьшее значение равно: " << v1 << "\n\n";
		}
		else if (v2 > v1)
		{
			cout << "Наименьшее значение равно: " << v1 << "\n"
			<< "Наименьшее значение равно: " << v2 << "\n\n";
		}

	}

	system ("pause");
	return 0;
}

