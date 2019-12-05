// глава 3,10.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"
#include "iostream"
#include "string"
#include "vector"
#include "algorithm"
#include "cmath"

using namespace std;
//программа определ€ет четные числа
int main()
{
	setlocale(LC_ALL, "Russian");

	cout << "¬ведите целое число от 0 до 4 буквами\n";
	string s = " ";
	cin >> s;
//	cout << s << "\n";
	if (s == "zero")
		cout << 0 << "\n";
	else if (s == "one")
		cout << 1 << "\n";
	else if (s == "two")
		cout << 2 << "\n";
	else if (s == "three")
		cout << 3 << "\n";
	else if (s == "four")
		cout << 4 << "\n";
	else
		cout << "я не знаю такого числа!\n";

	system ("pause");
	return 0;
}

