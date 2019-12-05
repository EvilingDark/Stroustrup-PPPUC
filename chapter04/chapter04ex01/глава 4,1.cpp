// глава 4,1.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"
#include "iostream"
#include "string"
#include "vector"
#include "algorithm"
#include "cmath"

using namespace std;

//программа дл€ отображени€ кода букв
int main()
{
	setlocale(LC_ALL, "Russian");

	char letter = 'a';
	int num = letter;
	for (int i = 0; i < 26; ++i)
	{
		cout << letter << "  " << num << "\n";
		++letter;
		++num;
	}


	system ("pause");
	return 0;
}

