// ����� 3,7.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "iostream"
#include "string"
#include "vector"
#include "algorithm"
#include "cmath"

using namespace std;
//��������� ���������� 3 ����� � ����� �� � ������� �����������
int main()
{
	setlocale(LC_ALL, "Russian");

	cout << "������� ��� �����\n";
	double val_1 = 0, val_2 = 0, val_3 = 0;
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



