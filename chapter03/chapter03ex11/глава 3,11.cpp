// ����� 3,11.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "iostream"
#include "string"
#include "vector"
#include "algorithm"
#include "cmath"

using namespace std;
//��������� ��������� �������� �������� � �������
int main()
{
	setlocale(LC_ALL, "Russian");

	cout << "������� �������������� �������� � ��� �����\n";
	string operation = " ";
	double val_1 = 0, val_2 = 0;
	while (cin >> operation >> val_1 >> val_2)
	{
//	cout << s << "\n";
	if (operation == "+")
		cout << "����� " << val_1 << operation << " ����� " << val_2 << " ����� " << val_1+val_2 << "\n";
	else if (operation == "-")
		cout << "����� " << val_1 << operation << " ����� " << val_2 << " ����� " << val_1-val_2 << "\n";
	else if (operation == "*")
		cout << "����� " << val_1 << operation << " ����� " << val_2 << " ����� " << val_1*val_2 << "\n";
	else if (operation == "/")
		cout << "����� " << val_1 << operation << " ����� " << val_2 << " ����� " << val_1/val_2 << "\n";
	else
		cout << "� �� ���� ����� ��������!\n";
	}

	system ("pause");
	return 0;
}


