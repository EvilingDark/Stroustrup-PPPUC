// ����� 3,6.cpp: ���������� ����� ����� ��� ����������� ����������.
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

	cout << "������� ��� ����� �����\n";
	double val_1 = 0, val_2 = 0;
	cin >> val_1 >> val_2;
	cout << "����� " << val_1 << " � " << val_2 << " ����� " << val_1 + val_2 << "\n";
	cout << "�������� " << val_1 << " � " << val_2 << " ����� " << val_1 - val_2 << "\n";
	cout << "������������ " << val_1 << " � " << val_2 << " ����� " << val_1 * val_2 << "\n";
	cout << "������� " << val_1 << " � " << val_2 << " ����� " << val_1 / val_2 << "\n";

	system ("pause");
	return 0;
}

