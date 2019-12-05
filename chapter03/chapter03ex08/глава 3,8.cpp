// глава 3,8.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"
#include "iostream"
#include "string"
#include "vector"
#include "algorithm"
#include "cmath"

using namespace std;
//программа сравнивает 3 числа и пишет их в пор€дке позрастани€
int main()
{
	setlocale(LC_ALL, "Russian");

	cout << "¬ведите три числа\n";
	string val_1 = " ", val_2 = " ", val_3 = " ";
	cin >> val_1 >> val_2 >> val_3;
	cout << "\n";

		if (val_1 >= val_2)
		{
			if (val_2 >= val_3)
				cout << val_3 << ", " << val_2 << ", " << val_1 << "\n";
			else
			{
				if (val_1 >= val_3)
					cout << val_2 << ", " << val_3 << ", " << val_1 << "\n";
				else 
					cout << val_2 << ", " << val_1 << ", " << val_3 << "\n";
			}
		}
		else
		{
			if (val_2 >= val_3)
			{
				if (val_1 >= val_3)
					cout << val_3 << ", " << val_1 << ", " << val_2 << "\n";
				else
					cout << val_1 << ", " << val_3 << ", " << val_2 << "\n";
			}
			else
				cout << val_1 << ", " << val_2 << ", " << val_3 << "\n";
		}

	system ("pause");
	return 0;
}

