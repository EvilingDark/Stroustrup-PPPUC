// глава 3,9.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"
#include "string"
#include "vector"
#include "algorithm"
#include "cmath"

using namespace std;
//программа определяет четные числа
int main()
{
	setlocale(LC_ALL, "Russian");

	cout << "Введите целое число\n";
	int val = 0;
	cin >> val;
	if (val%2 == 0)
		cout << "Число " << val << " является четным\n";
	else 
		cout << "Число " << val << " не является четным\n";
	system ("pause");
	return 0;
}
