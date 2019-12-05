// глава 3,6.cpp: определяет точку входа для консольного приложения.
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

	cout << "Введите два целых числа\n";
	double val_1 = 0, val_2 = 0;
	cin >> val_1 >> val_2;
	cout << "Сумма " << val_1 << " и " << val_2 << " равна " << val_1 + val_2 << "\n";
	cout << "Разность " << val_1 << " и " << val_2 << " равна " << val_1 - val_2 << "\n";
	cout << "Произведение " << val_1 << " и " << val_2 << " равна " << val_1 * val_2 << "\n";
	cout << "Частное " << val_1 << " и " << val_2 << " равна " << val_1 / val_2 << "\n";

	system ("pause");
	return 0;
}

