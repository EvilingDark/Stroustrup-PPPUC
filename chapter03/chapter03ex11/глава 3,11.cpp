// глава 3,11.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"
#include "string"
#include "vector"
#include "algorithm"
#include "cmath"

using namespace std;
//программа выполняет заданную операцию с числами
int main()
{
	setlocale(LC_ALL, "Russian");

	cout << "Введите математическую операцию и два числа\n";
	string operation = " ";
	double val_1 = 0, val_2 = 0;
	while (cin >> operation >> val_1 >> val_2)
	{
//	cout << s << "\n";
	if (operation == "+")
		cout << "Число " << val_1 << operation << " число " << val_2 << " равно " << val_1+val_2 << "\n";
	else if (operation == "-")
		cout << "Число " << val_1 << operation << " число " << val_2 << " равно " << val_1-val_2 << "\n";
	else if (operation == "*")
		cout << "Число " << val_1 << operation << " число " << val_2 << " равно " << val_1*val_2 << "\n";
	else if (operation == "/")
		cout << "Число " << val_1 << operation << " число " << val_2 << " равно " << val_1/val_2 << "\n";
	else
		cout << "Я не знаю такой операции!\n";
	}

	system ("pause");
	return 0;
}


