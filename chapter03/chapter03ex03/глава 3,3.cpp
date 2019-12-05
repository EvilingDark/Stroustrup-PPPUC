// глава 3,3.cpp: определяет точку входа для консольного приложения.
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

	double d = 0;
	while (cin>>d) {   // Повторяем последующие инструкции
						// пока вводятся числа
		int i = d; // Попытка втиснуть douЫ e в i n t

		char с = i ; // Попытка втиснуть i n t в cha r
		int i2 = с ; // Получаем целое зна чение типа cha r
		cout << " d== " << d // Исходное зна чение типа dоиЫе
		<< " i== " << i
		<< " i2== " << i2
		// Преобра зованное в зна чение i n t
		// Целочисленное зна чение cha r
		<< " char(" << с << ")\n"; // Символ
	}
	system ("pause");
	return 0;
}
