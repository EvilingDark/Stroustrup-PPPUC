// глава 3,5.cpp: определяет точку входа для консольного приложения.
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

	cout << "Введите количество миль\n";
	double miles = 0;
	cin >> miles;
	cout << miles << " миль это " << miles*1.609 << " километров\n";

	system ("pause");
	return 0;
}

